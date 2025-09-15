#include <stdio.h>

int main()
{
    int n, head, i, seek = 0;
    int queue[30];

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk requests (track numbers):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\nOrder of servicing requests:\n");
    printf("%d", head);

    for (i = 0; i < n; i++) {
        seek += (queue[i] > head) ? (queue[i] - head) : (head - queue[i]);
        head = queue[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Seek Time = %d\n", seek);
    printf("Average Seek Time = %.2f\n", (float)seek / n);

    return 0;
}

SAMPLE INPUT:
Enter number of disk requests: 5
Enter the disk requests (track numbers):
55 58 39 18 90
Enter the initial head position: 50

SAMPLE OUTPUT:
Order of servicing requests:
50 -> 55 -> 58 -> 39 -> 18 -> 90

Total Seek Time = 120
Average Seek Time = 24.00
