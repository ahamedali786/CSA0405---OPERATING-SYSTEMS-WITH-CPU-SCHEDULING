#include <stdio.h>
int main()
{
    int b[10], WT[10], TAT[10];
    int TWT = 0, TTAT = 0, ATWT, ATTAT, i, n;

    printf("Enter no of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    WT[0] = 0;  
    for (i = 1; i < n; i++) {
        WT[i] = b[i - 1] + WT[i - 1];
        TWT += WT[i];
    }
    ATWT = TWT / n;

    for (i = 0; i < n; i++) {
        TAT[i] = b[i] + WT[i];
        TTAT += TAT[i];
    }
    ATTAT = TTAT / n;

    printf("The average waiting time = %d\n", ATWT);
    printf("The average turnaround time = %d\n", ATTAT);

    return 0;
}
