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

SAMPLE INPUT:
Enter number of pages in reference string: 20
Enter the reference string:
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
Enter number of frames: 3

SAMPLE OUTPUT:
Step	Page	Frames	Fault
1	7	7 - - 	Yes
2	0	7 0 - 	Yes
3	1	7 0 1 	Yes
4	2	2 0 1 	Yes
5	0	2 0 1 	No
6	3	2 0 3 	Yes
7	0	2 0 3 	No
8	4	4 0 3 	Yes
9	2	4 0 2 	Yes
10	3	4 3 2 	Yes
11	0	0 3 2 	Yes
12	3	0 3 2 	No
13	2	0 3 2 	No
14	1	1 3 2 	Yes
15	2	1 3 2 	No
16	0	1 0 2 	Yes
17	1	1 0 2 	No
18	7	1 0 7 	Yes
19	0	1 0 7 	No
20	1	1 0 7 	No

Total page faults = 12
