#include <stdio.h>

int main()
{
    int n, i, j, temp;
    int bt[20], wt[20], tat[20], p[20];
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;   
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    wt[0] = 0;  
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        avgWT += wt[i];
    }

    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avgTAT += tat[i];
    }

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", avgWT / n);
    printf("Average Turnaround Time = %.2f\n", avgTAT / n);

    return 0;
}
