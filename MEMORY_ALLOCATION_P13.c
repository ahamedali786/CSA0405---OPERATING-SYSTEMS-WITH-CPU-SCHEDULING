#include <stdio.h>

int main() {
    int i, j, n, m;
    
    printf("Enter number of memory blocks: ");
    scanf("%d", &n);
    int blockSize[n], allocated[n];
    
    printf("Enter size of each memory block:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &blockSize[i]);
        allocated[i] = 0; 
    }

    printf("Enter number of processes: ");
    scanf("%d", &m);
    int processSize[m], allocation[m];
    
    printf("Enter size of each process:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &processSize[i]);
        allocation[i] = -1;
    }

   
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (!allocated[j] && blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                allocated[j] = 1;
                break;
            }
        }
    }


    printf("\nProcess No\tProcess Size\tBlock Allocated\n");
    for (i = 0; i < m; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
