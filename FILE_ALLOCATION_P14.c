#include <stdio.h>
#include <string.h>

int main() {
    int n, i, choice;
    char files[20][20];  
    int fileCount = 0;

    printf("Single Level Directory Simulation\n");

    do {
        printf("\nMenu:\n");
        printf("1. Create File\n");
        printf("2. Display Files\n");
        printf("3. Search File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (fileCount < 20) {
                    printf("Enter file name to create: ");
                    scanf("%s", files[fileCount]);
                    fileCount++;
                    printf("File created successfully.\n");
                } else {
                    printf("Directory is full!\n");
                }
                break;

            case 2:
                printf("Files in directory:\n");
                for (i = 0; i < fileCount; i++) {
                    printf("%s\n", files[i]);
                }
                if (fileCount == 0)
                    printf("Directory is empty.\n");
                break;

            case 3:
                {
                    char fname[20];
                    int found = 0;
                    printf("Enter file name to search: ");
                    scanf("%s", fname);
                    for (i = 0; i < fileCount; i++) {
                        if (strcmp(files[i], fname) == 0) {
                            found = 1;
                            break;
                        }
                    }
                    if (found)
                        printf("File '%s' found in directory.\n", fname);
                    else
                        printf("File '%s' not found.\n", fname);
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
