#include <stdio.h>

int main()
{
    int n, i;
    int bt[20], rt[20], pr[20];
    int wt[20], tat[20];
    int complete = 0, t = 0;
    int minPr;
    int shortest;
    float totalWT = 0, totalTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time and priority for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d (BT Priority): ", i + 1);
        scanf("%d %d", &bt[i], &pr[i]);
        rt[i] = bt[i];    
    }

    while (complete != n) {
        shortest = -1;
        minPr = 9999;

        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && pr[i] < minPr) {
                minPr = pr[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            t++;            
            continue;
        }

        rt[shortest]--;    
        t++;

        if (rt[shortest] == 0) {         
            complete++;
            tat[shortest] = t;           
            wt[shortest] = tat[shortest] - bt[shortest];
            totalWT += wt[shortest];
            totalTAT += tat[shortest];
        }
    }

    printf("\nProcess\tBurst\tPriority\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\t%d\n",
               i + 1, bt[i], pr[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);
    printf("Average Turnaround Time = %.2f\n", totalTAT / n);

    return 0;
}
SAMPLE INPUT:
Enter number of processes: 4
Enter burst time and priority for each process:
Process 1 (BT Priority): 8 4
Process 2 (BT Priority): 6 3
Process 3 (BT Priority): 4 2
Process 4 (BT Priority): 2 1
SAMPLE OUTPUT:
Process Burst   Priority        Waiting Turnaround
1       8       4               12      20
2       6       3               6       12
3       4       2               2       6
4       2       1               0       2

Average Waiting Time = 5.00
Average Turnaround Time = 10.00
