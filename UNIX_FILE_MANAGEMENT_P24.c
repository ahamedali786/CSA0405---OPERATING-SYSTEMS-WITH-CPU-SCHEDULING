#include <stdio.h>
#include <string.h>

struct Record {
    int id;
    char data[40];
};

int main() {
    struct Record file[5];
    int n, i, rec;

    printf("=== Sequential File Allocation (Simulation) ===\n\n");

    printf("Enter number of records (max 5): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        file[i].id = i + 1;
        printf("Enter data for record %d: ", file[i].id);
        scanf("%s", file[i].data);
    }

    printf("\nRecords stored sequentially:\n");
    for (i = 0; i < n; i++) {
        printf("Record %d -> %s\n", file[i].id, file[i].data);
    }

    printf("\nEnter record number to access: ");
    scanf("%d", &rec);

    if (rec <= 0 || rec > n) {
        printf("Invalid record number.\n");
    } else {
        printf("\nReading records in sequence:\n");
        for (i = 0; i < rec; i++) {
            printf("Reading Record %d: %s\n", file[i].id, file[i].data);
        }
        printf("\nData at Record %d = %s\n", rec, file[rec - 1].data);
    }

    return 0;
}

SAMPLE INPUT:
=== Sequential File Allocation (Simulation) ===

Enter number of records (max 5): 3
Enter data for record 1: ALPHA
Enter data for record 2: BETA
Enter data for record 3: GAMMA

Records stored sequentially:
Record 1 -> ALPHA
Record 2 -> BETA
Record 3 -> GAMMA

Enter record number to access: 3

SAMPLE OUTPUT:
Reading records in sequence:
Reading Record 1: ALPHA
Reading Record 2: BETA
Reading Record 3: GAMMA

Data at Record 3 = GAMMA
