#include <stdio.h>

int main()
{
    int n, frames;
    int ref[30], mem[10], time[10];
    int i, j, k, pos, faults = 0, found, counter = 0;

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
        time[i] = 0;
    }

    printf("\nStep\tPage\tFrames\tFault\n");
    for (i = 0; i < n; i++) {
        counter++;
        found = 0;

        
        for (j = 0; j < frames; j++) {
            if (mem[j] == ref[i]) {
                found = 1;
                time[j] = counter;
                break;
            }
        }

        if (found == 0) { 
            pos = 0;
            for (j = 1; j < frames; j++) {
                if (time[j] < time[pos]) {
                    pos = j;
                }
            }
            mem[pos] = ref[i];
            time[pos] = counter;
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
