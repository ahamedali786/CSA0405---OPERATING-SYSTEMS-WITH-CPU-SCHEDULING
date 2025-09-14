#include <stdio.h>

int main()
{
    int n, i;
    int bt[20], rt[20], wt[20], tat[20];
    int time = 0, remain;
    int tq;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];      
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    while (remain != 0) {
        for (i = 0; i < n; i++) {
            if (rt[i] > 0) {
                if (rt[i] <= tq) {
                    time += rt[i];
                    tat[i] = time;        
                    wt[i] = tat[i] - bt[i];
                    avgWT += wt[i];
                    avgTAT += tat[i];
                    rt[i] = 0;
                    remain--;
                } else {
                    time += tq;
                    rt[i] -= tq;
                }
            }
        }
    }

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", avgWT / n);
    printf("Average Turnaround Time = %.2f\n", avgTAT / n);

    return 0;
}
