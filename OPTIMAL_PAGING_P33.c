#include <stdio.h>
int main()
{
    int n, frames;
    int ref[30], mem[10];
    int i, j, k, pos, faults = 0, found;

    printf("Enter number of pages in reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &ref[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++) {
        mem[i] = -1;
    }

    printf("\nStep\tPage\tFrames\tFault\n");
    for (i = 0; i < n; i++) {
        found = 0;
        for (j = 0; j < frames; j++) {
            if (mem[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        if (found == 0) { 
            if (i < frames) {
                mem[i] = ref[i];
            } else {
                int farthest = i + 1;
                pos = -1;

                for (j = 0; j < frames; j++) {
                    int next = -1;
                    for (k = i + 1; k < n; k++) {
                        if (ref[k] == mem[j]) {
                            next = k;
                            break;
                        }
                    }
                    if (next == -1) { 
                        pos = j;
                        break;
                    }
                    if (next > farthest) {
                        farthest = next;
                        pos = j;
                    }
                }
                if (pos == -1) pos = 0;
                mem[pos] = ref[i];
            }

            faults++;
            printf("%d\t%d\t", i + 1, ref[i]);
            for (k = 0; k < frames; k++) {
                if (mem[k] == -1)
                    printf("- ");
                else
                    printf("%d ", mem[k]);
            }
            printf("\tYes\n");
        } else { 
            printf("%d\t%d\t", i + 1, ref[i]);
            for (k = 0; k < frames; k++) {
                if (mem[k] == -1)
                    printf("- ");
                else
                    printf("%d ", mem[k]);
            }
            printf("\tNo\n");
        }
    }

    printf("\nTotal page faults = %d\n", faults);
    return 0;
}
