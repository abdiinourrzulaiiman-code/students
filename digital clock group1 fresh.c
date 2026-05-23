#include <stdio.h>
#include <time.h>

int main()
 {
    int choice;

    while (1) 
	{
        
        printf("........   DIGITAL CLOCK MENU    ........\n");
        printf("1. Show Current Time\n");
        printf("2. Exit\n");
        printf("Choose an option (1 or 2): ");
        scanf("%d", &choice);

        if (choice == 1)
		 {
            
            time_t now = time(0);
            struct tm *lt = localtime(&now);

            int hour = lt->tm_hour;
            int minute = lt->tm_min;
            int second = lt->tm_sec;
            char period[3] = "AM";

            if (hour >= 12) 
			{
                period[0] = 'P';
                if (hour > 12) hour -= 12;
            } else if (hour == 0)  
			{
                hour = 12;
            }

            

            printf("\n_______    DIGITAL CLOCK    _______\n\n");
            printf("Current Time: %02d:%02d:%02d %s\n", hour, minute, second, period);
            printf("\n_________\n\n");
        }
        else if (choice == 2)
		 {
            printf("Exiting program. Goodbye!\n");
            break;
        }
        else
		 {
            printf("Invalid choice. Please enter 1 or 2.\n\n");
        }
    }

    return 0;
}
