#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[20];
    float salary;
};

int main() {
    FILE *fp;
    struct Employee emp;
    int n, choice, recordNum;

    fp = fopen("employee.dat", "wb+"); 
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d details:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp.id);
        printf("Name: ");
        scanf("%s", emp.name);
        printf("Salary: ");
        scanf("%f", &emp.salary);
        fwrite(&emp, sizeof(emp), 1, fp);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Display all employees\n");
        printf("2. Display specific employee (random access)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                rewind(fp); 
                printf("\nAll Employees:\n");
                while (fread(&emp, sizeof(emp), 1, fp) == 1) {
                    printf("ID: %d, Name: %s, Salary: %.2f\n", emp.id, emp.name, emp.salary);
                }
                break;

            case 2:
                printf("Enter employee record number (1 to %d): ", n);
                scanf("%d", &recordNum);
                if (recordNum > 0 && recordNum <= n) {
                    fseek(fp, (recordNum - 1) * sizeof(emp), SEEK_SET);
                    fread(&emp, sizeof(emp), 1, fp);
                    printf("Employee %d details:\n", recordNum);
                    printf("ID: %d, Name: %s, Salary: %.2f\n", emp.id, emp.name, emp.salary);
                } else {
                    printf("Invalid record number!\n");
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    fclose(fp);
    return 0;
}
