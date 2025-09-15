#include <stdio.h>

int main()
{
    int n, frames;
    int ref[30], mem[10];
    int i, j, k, faults = 0, pos = 0, found;

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
            mem[pos] = ref[i];
            pos = (pos + 1) % frames;
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
6	3	2 3 1 	Yes
7	0	2 3 0 	Yes
8	4	4 3 0 	Yes
9	2	4 2 0 	Yes
10	3	4 2 3 	Yes
11	0	0 2 3 	Yes
12	3	0 2 3 	No
13	2	0 2 3 	No
14	1	0 1 3 	Yes
15	2	0 1 2 	Yes
16	0	0 1 2 	No
17	1	0 1 2 	No
18	7	7 1 2 	Yes
19	0	7 0 2 	Yes
20	1	7 0 1 	Yes

Total page faults = 15
