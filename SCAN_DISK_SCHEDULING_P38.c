#include <stdio.h>


int main()
{
    int queue[30], n, head, i, j, seek = 0, temp;
    int diskSize, direction;
5
    printf("Enter total number of tracks (disk size): ");
    scanf("%d", &diskSize);

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk requests (track numbers):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (1 = high, 0 = low): ");
    scanf("%d", &direction);

    queue[n] = head;
    n++;

    queue[n++] = 0;
    queue[n++] = diskSize - 1;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (queue[i] > queue[j]) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    int pos = 0;
    for (i = 0; i < n; i++) {
        if (queue[i] == head) {
            pos = i;
            break;
        }
    }

    printf("\nSeek sequence:\n");

    if (direction == 1) { 
        for (i = pos; i < n; i++) {
            printf("%d -> ", queue[i]);
        }
        for (i = pos - 1; i >= 0; i--) {
            printf("%d -> ", queue[i]);
        }
    } else { 
        for (i = pos; i >= 0; i--) {
            printf("%d -> ", queue[i]);
        }
        for (i = pos + 1; i < n; i++) {
            printf("%d -> ", queue[i]);
        }
    }
    printf("END\n");

    if (direction == 1) {
        seek = (diskSize - 1 - head) + (diskSize - 1 - queue[0]);
    } else {
        seek = head + (diskSize - 1 - queue[0]);
    }

    printf("\nTotal Seek Time = %d\n", seek);
    printf("Average Seek Time = %.2f\n", (float)seek / (n - 3));

    return 0;
}

SAMPLE INPUT:
Enter total number of tracks (disk size): 200
Enter number of disk requests: 5
Enter the disk requests (track numbers):
55 58 39 18 90 
Enter initial head position: 50
Enter direction (1 = high, 0 = low): 1

SAMPLE OUTPUT:
Seek sequence:
50 -> 55 -> 58 -> 90 -> 199 -> 39 -> 18 -> 0 -> END

Total Seek Time = 348
Average Seek Time = 69.60
