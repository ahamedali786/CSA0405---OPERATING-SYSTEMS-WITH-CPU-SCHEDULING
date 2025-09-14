#include <stdio.h>

int main()
{
    FILE *src, *dest;
    char ch;
    char srcname[50], destname[50];

    printf("Enter source file name: ");
    scanf("%s", srcname);

    printf("Enter destination file name: ");
    scanf("%s", destname);

    src = fopen(srcname, "r");
    if (src == NULL) {
        printf("Cannot open source file\n");
        return 1;
    }

    dest = fopen(destname, "w");
    if (dest == NULL) {
        printf("Cannot open destination file\n");
        fclose(src);
        return 1;
    }

    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    printf("File copied successfully.\n");

    fclose(src);
    fclose(dest);
    return 0;
}
