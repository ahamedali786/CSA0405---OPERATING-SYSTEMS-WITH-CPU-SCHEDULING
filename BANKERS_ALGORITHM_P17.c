#include <stdio.h>

int main() {
    int p, r, i, j, k, count = 0;
    
    printf("Enter number of processes and resources: ");
    scanf("%d %d", &p, &r);

    int alloc[p][r], max[p][r], need[p][r], avail[r], done[p], safeSeq[p];

    printf("Enter allocation matrix (%dx%d):\n", p, r);
    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter max matrix (%dx%d):\n", p, r);
    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            scanf("%d", &max[i][j]);

    printf("Enter available resources (%d):\n", r);
    for(j = 0; j < r; j++)
        scanf("%d", &avail[j]);

    printf("\nNeed Matrix:\n");
    for(i = 0; i < p; i++) {
        for(j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d\t", need[i][j]);
        }
        printf("\n");
        done[i] = 0;
    }

    while(count < p) {
        int found = 0;
        for(i = 0; i < p; i++) {
            if(done[i] == 0) {
                int canAllocate = 1;
                for(j = 0; j < r; j++) {
                    if(need[i][j] > avail[j]) {
                        canAllocate = 0;
                        break;
                    }
                }
                if(canAllocate) {
                    for(j = 0; j < r; j++)
                        avail[j] += alloc[i][j];
                    safeSeq[count++] = i;
                    done[i] = 1;
                    found = 1;
                }
            }
        }
        if(found == 0)
            break;
    }

    if(count == p) {
        printf("\nSystem is in a safe state.\nSafe sequence: ");
        for(i = 0; i < p; i++)
            printf("P%d ", safeSeq[i]);
        printf("\n");
    } else {
        printf("System is not in a safe state.\n");
    }
    return 0;
}
