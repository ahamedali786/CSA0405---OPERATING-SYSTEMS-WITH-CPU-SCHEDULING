#include <stdio.h>


int main()
{
    int diskSize, files;
    int disk[50];
    int i, j, start, size, ok;

    printf("Enter total number of disk blocks: ");
    scanf("%d", &diskSize);

    for (i = 0; i < diskSize; i++) {
        disk[i] = 0;  
    }

    printf("Enter number of files to allocate: ");
    scanf("%d", &files);

    for (i = 0; i < files; i++) {
        printf("\nEnter starting block and length of file %d: ", i + 1);
        scanf("%d %d", &start, &size);

        if (start + size > diskSize) {
            printf("File %d: Not enough blocks on disk.\n", i + 1);
            continue;
        }

        ok = 1;
        for (j = start; j < start + size; j++) {
            if (disk[j] == 1) {
                ok = 0;
                break;
            }
        }

        if (ok == 1) {
            for (j = start; j < start + size; j++) {
                disk[j] = 1;
            }
            printf("File %d allocated blocks %d to %d\n", i + 1, start, start + size - 1);
        } else {
            printf("File %d: Blocks already allocated, cannot place file.\n", i + 1);
        }
    }

    printf("\nFinal allocation status of disk blocks:\n");
    for (i = 0; i < diskSize; i++) {
        printf("%d:%d  ", i, disk[i]);
        if ((i + 1) % 8 == 0) printf("\n");
    }

    return 0;
}
