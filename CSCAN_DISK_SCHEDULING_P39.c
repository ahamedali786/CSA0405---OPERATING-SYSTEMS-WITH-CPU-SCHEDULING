#include <stdio.h>


int main()
{
    int queue[40], n, head, i, j, temp, seek = 0;
    int diskSize;

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

    printf("\nSeek sequence (C-SCAN):\n");

    for (i = pos; i < n; i++) {
        printf("%d -> ", queue[i]);
    }
    for (i = 0; i < pos; i++) {
        printf("%d -> ", queue[i]);
    }
    printf("END\n");

    seek = (diskSize - 1 - head) + (diskSize - 1 - 0) + queue[pos - 1];

    printf("\nTotal Seek Time = %d\n", seek);
    printf("Average Seek Time = %.2f\n", (float)seek / (n - 3));

    return 0;
}
