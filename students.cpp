#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    int id;
    string name;
    string course;
    int marks;
};

// DISPLAY FUNCTION 
void display(const vector<Student>& students) {

    for (int i = 0; i < students.size(); i++) {
        cout << students[i].id << " "
             << students[i].name << " "
             << students[i].course << " "
             << students[i].marks << endl;
    }

    cout << "--------------------------\n";
}

//    BUBBLE SORT (ASCENDING) 
int bubbleSort(vector<Student>& arr) {
    int swaps = 0;
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].marks > arr[j + 1].marks) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }

    return swaps;
}

//  QUICK SORT (DESCENDING) 
int swapCountQuick = 0;

int partition(vector<Student>& arr, int low, int high) {
    int pivot = arr[high].marks;
    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j].marks > pivot) {
            i++;
            swap(arr[i], arr[j]);
            swapCountQuick++;
        }
    }
    swap(arr[i + 1], arr[high]);
    swapCountQuick++;

    return i + 1;
}

void quickSort(vector<Student>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
//  SEARCH FUNCTION 
void searchStudent(const vector<Student>& arr, int id) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].id == id) {
            cout << "Student Found:\n";
            cout << arr[i].id << " "
                 << arr[i].name << " "
                 << arr[i].course << " "
                 << arr[i].marks << endl;
            return;
        }
    }
    cout << "Student not found.\n";
}

//    MAIN 
int main() {
    vector<Student> students;
    ifstream file("students.txt");
    if (!file) {
        cout << "Error opening file!\n";

        return 1;
    }
    Student s;
    while (file >> s.id >> s.name >> s.course >> s.marks) {
        students.push_back(s);
    }
    file.close();
    cout << "Original Data:\n";
    display(students);

    //  Bubble Sort 
    vector<Student> bubbleArr = students;
    int bubbleSwaps = bubbleSort(bubbleArr);
    cout << "Bubble Sort (Ascending):\n";
    display(bubbleArr);

    //     Quick Sort 
    vector<Student> quickArr = students;
    quickSort(quickArr, 0, quickArr.size() - 1);
    cout << "Quick Sort (Descending):\n";
    display(quickArr);

    //    Search 
    int searchID;
    cout << "Enter Student ID to search: ";
    cin >> searchID;

    searchStudent(students, searchID);

    //    Swap Comparison 
    cout << "\nSwap Comparison:\n";

    cout << "Bubble Sort Swaps: "
         << bubbleSwaps << endl;

    cout << "Quick Sort Swaps: "
         << swapCountQuick << endl;

    //  Highest & Lowest 
    Student highest = bubbleArr.back();
    Student lowest = bubbleArr.front();

    cout << "\nTop Student:\n";

    cout << highest.id << " "
         << highest.name << " "
         << highest.course << " "
         << highest.marks << endl;

    cout << "\nLowest Student:\n";

    cout << lowest.id << " "
         << lowest.name << " "
         << lowest.course << " "
         << lowest.marks << endl;

    return 0;
}
