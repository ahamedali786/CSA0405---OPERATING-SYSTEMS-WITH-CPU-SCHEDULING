#include <stdio.h>
#include <string.h>

#define MAX_LINES 50
#define MAX_LEN   100

int main() {
    char lines[MAX_LINES][MAX_LEN];
    char pattern[MAX_LEN];
    int n, i;
    int found = 0;

    printf("=== Simulation of `grep` Command ===\n\n");

    printf("Enter number of lines (1-%d): ", MAX_LINES);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_LINES) {
        printf("Invalid number of lines.\n");
        return 1;
    }

    getchar(); 

    printf("\nEnter %d lines:\n", n);
    for (i = 0; i < n; i++) {
        fgets(lines[i], sizeof(lines[i]), stdin);
        lines[i][strcspn(lines[i], "\n")] = '\0'; 
    }

    printf("\nEnter pattern to search: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0';

    printf("\nLines containing '%s':\n", pattern);
    for (i = 0; i < n; i++) {
        if (strstr(lines[i], pattern) != NULL) {
            printf("%s\n", lines[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("[No match found]\n");
    }

    return 0;
}

SAMPLE INPUT:
=== Simulation of `grep` Command ===

Enter number of lines (1-50): 4

Enter 4 lines:
apple pie is tasty
banana bread is good
grapes are sweet
apple jam is nice

Enter pattern to search: apple

SAMPLE OUTPUT:

Lines containing 'apple':
apple pie is tasty
apple jam is nice
