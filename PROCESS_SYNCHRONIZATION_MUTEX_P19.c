#include <stdio.h>

int main() {
    int resource = 0;  
    int mutex = 1;      
    int choice;

    printf("Process Synchronization Simulation (Mutex)\n");

    do {
        printf("\nMenu:\n");
        printf("1. Process 1 access resource\n");
        printf("2. Process 2 access resource\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (mutex == 1) {
                    printf("Process 1 entering critical section.\n");
                    mutex = 0;   
                    resource++;
                    printf("Process 1 updated resource: %d\n", resource);
                    mutex = 1;   
                    printf("Process 1 leaving critical section.\n");
                } else {
                    printf("Resource busy. Process 1 waiting...\n");
                }
                break;

            case 2:
                if (mutex == 1) {
                    printf("Process 2 entering critical section.\n");
                    mutex = 0;  
                    resource++;
                    printf("Process 2 updated resource: %d\n", resource);
                    mutex = 1;   
                    printf("Process 2 leaving critical section.\n");
                } else {
                    printf("Resource busy. Process 2 waiting...\n");
                }
                break;

            case 3:
                printf("Exiting simulation.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}

SAMPLE INPUT:
Process Synchronization Simulation (Mutex)

Menu:
1. Process 1 access resource
2. Process 2 access resource
3. Exit
Enter choice: 1

SAMPLE OUTPUT:
Enter choice: 1
Process 1 entering critical section.
Process 1 updated resource: 1
Process 1 leaving critical section.

Menu:
1. Process 1 access resource
2. Process 2 access resource
3. Exit
Enter choice: 2
Process 2 entering critical section.
Process 2 updated resource: 2
Process 2 leaving critical section.

Menu:
1. Process 1 access resource
2. Process 2 access resource
3. Exit
Enter choice: 3
Exiting simulation.
