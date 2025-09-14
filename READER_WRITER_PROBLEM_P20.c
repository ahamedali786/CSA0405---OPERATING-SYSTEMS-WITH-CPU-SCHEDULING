#include <stdio.h>

int main() {
    int resource = 0;       
    int readers = 0;        
    int choice;

    printf("Reader-Writer Problem Simulation\n");

    do {
        printf("\nMenu:\n");
        printf("1. Reader reads resource\n");
        printf("2. Writer writes resource\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readers++;
                printf("Reader %d reading resource: %d\n", readers, resource);
                readers--;
                break;

            case 2:
                if (readers == 0) {  
                    resource++;
                    printf("Writer updated resource to: %d\n", resource);
                } else {
                    printf("Resource busy with readers. Writer waiting...\n");
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
Reader-Writer Problem Simulation

Menu:
1. Reader reads resource
2. Writer writes resource
3. Exit
Enter choice: 1

SAMPLE OUTPUT:
Enter choice: 1
Reader 1 reading resource: 0

Enter choice: 2
Writer updated resource to: 1

Enter choice: 1
Reader 1 reading resource: 1

Enter choice: 3
Exiting simulation.
