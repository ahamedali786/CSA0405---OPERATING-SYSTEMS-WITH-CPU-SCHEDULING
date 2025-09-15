#include <stdio.h>
#include <string.h>


struct FileInfo {
    char name[30];
    long size;
    int flags;  
};

void fake_open(struct FileInfo *f) {
    printf("[open] File '%s' opened with flags = %d\n", f->name, f->flags);
}

void fake_stat(struct FileInfo f) {
    printf("[stat] File: %s | Size: %ld bytes | Flags: %d\n",
           f.name, f.size, f.flags);
}

void fake_seek(long offset) {
    printf("[seek] Moving file pointer by %ld bytes (simulation)\n", offset);
}

void fake_fcntl(int cmd) {
    printf("[fcntl] Performing command %d (simulation)\n", cmd);
}

void fake_opendir() {
    printf("[opendir] Opening current directory (simulation)\n");
    printf("[readdir] file1.txt\n");
    printf("[readdir] data.c\n");
    printf("[readdir] report.pdf\n");
}

int main() {
    printf("=== Simulated UNIX I/O System Calls ===\n\n");

    struct FileInfo f;
    strcpy(f.name, "demo.txt");
    f.size = 256;
    f.flags = 1;   

    fake_open(&f);

    fake_stat(f);

    fake_seek(10);

    fake_fcntl(2);

    fake_opendir();

    return 0;
}
