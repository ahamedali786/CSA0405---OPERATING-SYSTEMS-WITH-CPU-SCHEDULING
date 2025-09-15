#include <stdio.h>

int main()
{
    int diskSize, i, j, indexBlock, nBlocks;
    int disk[50], blocks[20];

    printf("Enter total number of disk blocks: ");
    scanf("%d", &diskSize);

    for (i = 0; i < diskSize; i++) {
        disk[i] = 0;   
    }

    printf("Enter the index block number: ");
    scanf("%d", &indexBlock);

    if (indexBlock < 0 || indexBlock >= diskSize) {
        printf("Invalid index block.\n");
        return 0;
    }

    if (disk[indexBlock] == 1) {
        printf("Index block already allocated.\n");
        return 0;
    }

    disk[indexBlock] = 1;

    printf("Enter number of blocks to allocate for the file: ");
    scanf("%d", &nBlocks);

    if (nBlocks > 20) {
        printf("Maximum 20 blocks allowed.\n");
        return 0;
    }

    printf("Enter the block numbers to be allocated:\n");
    for (i = 0; i < nBlocks; i++) {
        scanf("%d", &blocks[i]);
        if (blocks[i] < 0 || blocks[i] >= diskSize) {
            printf("Invalid block number %d\n", blocks[i]);
            return 0;
        }
        if (disk[blocks[i]] == 1) {
            printf("Block %d already allocated.\n", blocks[i]);
            return 0;
        }
    }

    for (i = 0; i < nBlocks; i++) {
        disk[blocks[i]] = 1;
    }

    printf("\nFile allocated successfully!\n");
    printf("Index Block: %d\n", indexBlock);
    printf("Blocks of the file: ");
    for (i = 0; i < nBlocks; i++) {
        printf("%d ", blocks[i]);
    }
    printf("\n\nDisk status (block:allocated):\n");
    for (i = 0; i < diskSize; i++) {
        printf("%d:%d  ", i, disk[i]);
        if ((i + 1) % 8 == 0) printf("\n");
    }

    return 0;
}

SAMPLE INPUT:
Enter total number of disk blocks: 16
Enter the index block number: 3
Enter number of blocks to allocate for the file: 5
Enter the block numbers to be allocated:
5 6 8 10 12

SAMPLE OUTPUT:
File allocated successfully!
Index Block: 3
Blocks of the file: 5 6 8 10 12 

Disk status (block:allocated):
0:0  1:0  2:0  3:1  4:0  5:1  6:1  7:0  
8:1  9:0  10:1  11:0  12:1  13:0  14:0  15:0  
