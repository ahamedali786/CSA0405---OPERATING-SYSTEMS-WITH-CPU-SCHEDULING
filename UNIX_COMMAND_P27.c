#include <stdio.h>
#include <string.h>

#define MAX_FILES 20
#define NAME_LEN  40

int main() {
    char files[MAX_FILES][NAME_LEN];
    int n, i;

    printf("=== Simulation of `ls` Command ===\n\n");

    printf("Enter number of files (1–%d): ", MAX_FILES);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_FILES) {
        printf("Invalid number of files.\n");
        return 1;
    }

    printf("\nEnter %d file names:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", files[i]);
    }

    printf("\nOutput of simulated `ls`:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", files[i]);
    }

    return 0;
}

SAMPLE INPUT:
Enter number of files (1–20): 5
Enter 5 file names:
alpha.txt
beta.c
gamma.pdf
delta.jpg
epsilon

SAMPLE OUTPUT:
alpha.txt
beta.c
gamma.pdf
delta.jpg
epsilon
