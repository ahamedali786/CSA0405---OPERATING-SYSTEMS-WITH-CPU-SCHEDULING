#include <stdio.h>

int main() {
    int b[20], p[20], nb, np;
    int alloc[20];
    int i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);
    printf("Enter sizes of blocks:\n");
    for (i = 0; i < nb; i++) scanf("%d", &b[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);
    printf("Enter sizes of processes:\n");
    for (i = 0; i < np; i++) scanf("%d", &p[i]);

    for (i = 0; i < np; i++) alloc[i] = -1;

    for (i = 0; i < np; i++) {
        int worst = -1;
        for (j = 0; j < nb; j++) {
            if (b[j] >= p[i]) {
                if (worst == -1 || b[j] > b[worst]) worst = j;
            }
        }
        if (worst != -1) {
            alloc[i] = worst;
            b[worst] -= p[i];
        }
    }

    printf("\nProcess\tSize\tBlock\n");
    for (i = 0; i < np; i++) {
        if (alloc[i] != -1)
            printf("%d\t%d\t%d\n", i + 1, p[i], alloc[i] + 1);
        else
            printf("%d\t%d\tNot Allocated\n", i + 1, p[i]);
    }

    return 0;
}

SAMPLE INPUT:
Enter number of memory blocks: 4
Enter sizes of blocks:
100
500
200
300
Enter number of processes: 3
Enter sizes of processes:
212
417
112
SAMPLE OUTPUT:
Process Size    Block
1       212     2
2       417     2
3       112     4
