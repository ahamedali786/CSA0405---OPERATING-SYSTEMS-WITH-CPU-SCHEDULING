#include <stdio.h>

int main() {
    int b[10], WT[10], TAT[10], pid[10];
    int TWT = 0, TTAT = 0, i, j, n;
    float ATWT, ATTAT;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        pid[i] = i + 1;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (b[i] > b[j]) {
                int temp = b[i];
                b[i] = b[j];
                b[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    WT[0] = 0;  
    for (i = 1; i < n; i++) {
        WT[i] = b[i - 1] + WT[i - 1];
        TWT += WT[i];
    }

    for (i = 0; i < n; i++) {
        TAT[i] = b[i] + WT[i];
        TTAT += TAT[i];
    }

    ATWT = (float)TWT / n;
    ATTAT = (float)TTAT / n;
    
    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", pid[i], b[i], WT[i], TAT[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", ATWT);
    printf("Average Turnaround Time = %.2f\n", ATTAT);

    return 0;
}
