#include <stdio.h>
#include <string.h>

struct File {
    char name[30];
    char owner[20];
    char group[20];
    int owner_r, owner_w, owner_x;
    int group_r, group_w, group_x;
    int other_r, other_w, other_x;
};

void show_permissions(struct File f)
{
    printf("\nFile: %s\n", f.name);
    printf("Owner: %s | Group: %s\n", f.owner, f.group);
    printf("Permissions: ");

    printf((f.owner_r) ? "r" : "-");
    printf((f.owner_w) ? "w" : "-");
    printf((f.owner_x) ? "x" : "-");

    printf((f.group_r) ? "r" : "-");
    printf((f.group_w) ? "w" : "-");
    printf((f.group_x) ? "x" : "-");

    printf((f.other_r) ? "r" : "-");
    printf((f.other_w) ? "w" : "-");
    printf((f.other_x) ? "x" : "-");

    printf("\n");
}

int main()
{
    struct File file;

    strcpy(file.name, "demo.txt");
    strcpy(file.owner, "ahamed");
    strcpy(file.group, "students");

    file.owner_r = 1; file.owner_w = 1; file.owner_x = 0;
    file.group_r = 1; file.group_w = 0; file.group_x = 0;
    file.other_r = 1; file.other_w = 0; file.other_x = 0;

    printf("=== Linux File Access Permissions (Simulation) ===\n");
    show_permissions(file);

    file.owner_x = 1;
    file.group_x = 1;

    printf("\nAfter changing permissions to 754 (rwxr-xr--):\n");
    show_permissions(file);

    return 0;
}

SAMPLE OUTPUT:
=== Linux File Access Permissions (Simulation) ===

File: demo.txt
Owner: ahamed | Group: students
Permissions: rw-r--r--

After changing permissions to 754 (rwxr-xr--):

File: demo.txt
Owner: ahamed | Group: students
Permissions: rwxr-xr--
