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

SAMPLE INPUT:
Enter number of processes: 4
Enter burst times:
Process 1: 10
Process 2: 8
Process 3: 6
Process 4: 4
Enter time quantum: 4
SAMPLE OUTPUT:
Process BT      WT      TAT
1       10      18      28
2       8       16      24
3       6       20      26
4       4       12      16

Average Waiting Time = 16.50
Average Turnaround Time = 23.50
