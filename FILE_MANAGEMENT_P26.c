#include <stdio.h>

int main() {
    FILE *fp;
    char text[100];

    printf("=== File Management Operations (Simulation) ===\n\n");

    fp = fopen("sample.txt", "w");
    if (!fp) {
        printf("Error creating file!\n");
        return 1;
    }
    fprintf(fp, "Hello! This is a demo text.\n");
    fclose(fp);
    printf("[create/write] sample.txt created & data written.\n");

    fp = fopen("sample.txt", "r");
    if (!fp) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    printf("[read] Contents of sample.txt:\n");
    while (fgets(text, sizeof(text), fp) != NULL) {
        printf("%s", text);
    }
    fclose(fp);

    if (rename("sample.txt", "renamed.txt") == 0)
        printf("\n[rename] sample.txt → renamed.txt\n");
    else
        printf("\n[rename] Failed!\n");

    if (remove("renamed.txt") == 0)
        printf("[delete] renamed.txt removed successfully.\n");
    else
        printf("[delete] Failed to remove file.\n");

    return 0;
}

SAMPLE OUTPUT:
=== File Management Operations (Simulation) ===

[create/write] sample.txt created & data written.
[read] Contents of sample.txt:
Hello! This is a demo text.

[rename] sample.txt → renamed.txt
[delete] renamed.txt removed successfully.
