#include <stdio.h>
#include <string.h>

int main() {
    int users, i, j, choice, fileCount[10];
    char user[10][20];           
    char files[10][20][20];     

    printf("Two Level Directory Simulation\n");

    printf("Enter number of users: ");
    scanf("%d", &users);

    for (i = 0; i < users; i++) {
        printf("Enter name of user %d: ", i + 1);
        scanf("%s", user[i]);
        fileCount[i] = 0; 
    }

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
                {
                    int u;
                    char fname[20];
                    printf("Enter user number (1 to %d): ", users);
                    scanf("%d", &u);
                    u--; 

                    if (fileCount[u] < 20) {
                        printf("Enter file name to create: ");
                        scanf("%s", files[u][fileCount[u]]);
                        fileCount[u]++;
                        printf("File created successfully for user %s.\n", user[u]);
                    } else {
                        printf("User directory is full!\n");
                    }
                }
                break;

            case 2:
                for (i = 0; i < users; i++) {
                    printf("\nFiles for user %s:\n", user[i]);
                    if (fileCount[i] == 0)
                        printf("No files.\n");
                    else {
                        for (j = 0; j < fileCount[i]; j++)
                            printf("%s\n", files[i][j]);
                    }
                }
                break;

            case 3:
                {
                    int u, found = 0;
                    char fname[20];
                    printf("Enter user number (1 to %d): ", users);
                    scanf("%d", &u);
                    u--;

                    printf("Enter file name to search: ");
                    scanf("%s", fname);

                    for (j = 0; j < fileCount[u]; j++) {
                        if (strcmp(files[u][j], fname) == 0) {
                            found = 1;
                            break;
                        }
                    }
                    if (found)
                        printf("File '%s' found for user %s.\n", fname, user[u]);
                    else
                        printf("File '%s' not found for user %s.\n", fname, user[u]);
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

SAMPLE INPUT:
Two Level Directory Simulation
Enter number of users: 2
Enter name of user 1: CHARAN
Enter name of user 2: CHETHAN

SAMPLE OUTPUT:
Menu:
1. Create File
2. Display Files
3. Search File
4. Exit
Enter your choice: 1
Enter user number (1 to 2): 1
Enter file name to create: HII
File created successfully for user CHARAN.

Menu:
1. Create File
2. Display Files
3. Search File
4. Exit
Enter your choice: 2

Files for user CHARAN:
HII

Files for user CHETHAN:
No files.

Menu:
1. Create File
2. Display Files
3. Search File
4. Exit
Enter your choice: 4
Exiting...

