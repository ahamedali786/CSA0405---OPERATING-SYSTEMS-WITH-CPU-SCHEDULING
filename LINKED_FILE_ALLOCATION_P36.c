#include <stdio.h>


int main()
{
    int diskSize, nBlocks, i;
    int start, next;
    int disk[50];
    int link[50];   

    printf("Enter total number of disk blocks: ");
    scanf("%d", &diskSize);

    for (i = 0; i < diskSize; i++) {
        disk[i] = 0;   
        link[i] = -1;  
    }

    printf("Enter starting block of the file: ");
    scanf("%d", &start);

    if (start < 0 || start >= diskSize || disk[start] == 1) {
        printf("Invalid or already allocated starting block.\n");
        return 0;
    }

    printf("Enter number of blocks to allocate (including start): ");
    scanf("%d", &nBlocks);

    if (nBlocks <= 0 || nBlocks > diskSize) {
        printf("Invalid number of blocks.\n");
        return 0;
    }

    int blocks[20];
    blocks[0] = start;
    disk[start] = 1;

    printf("Enter the remaining %d block numbers:\n", nBlocks - 1);
    for (i = 1; i < nBlocks; i++) {
        scanf("%d", &blocks[i]);
        if (blocks[i] < 0 || blocks[i] >= diskSize || disk[blocks[i]] == 1) {
            printf("Block %d is invalid or already allocated.\n", blocks[i]);
            return 0;
        }
        disk[blocks[i]] = 1;
    }

    for (i = 0; i < nBlocks - 1; i++) {
        link[blocks[i]] = blocks[i + 1];
    }
    link[blocks[nBlocks - 1]] = -1;

    printf("\nFile allocated successfully using linked allocation.\n");
    printf("Blocks of the file:\n");

    next = start;
    while (next != -1) {
        printf("%d -> ", next);
        next = link[next];
    }
    printf("NULL\n");

    printf("\nDisk status (block:allocated):\n");
    for (i = 0; i < diskSize; i++) {
        printf("%d:%d  ", i, disk[i]);
        if ((i + 1) % 8 == 0) printf("\n");
    }

    return 0;
}

SAMPLE INPUT:
Enter total number of disk blocks: 16
Enter starting block of the file: 2
Enter number of blocks to allocate (including start): 4
Enter the remaining 3 block numbers:
5 7 9

SAMPLE OUTPUT:
File allocated successfully using linked allocation.
Blocks of the file:
2 -> 5 -> 7 -> 9 -> NULL

Disk status (block:allocated):
0:0  1:0  2:1  3:0  4:0  5:1  6:0  7:1  
8:0  9:1  10:0  11:0  12:0  13:0  14:0  15:0 
