#include <stdio.h>

long getFileSize(char *fileName) {
    long size;
    FILE *target_file;

    target_file = fopen(fileName, "rb");

    if (target_file != NULL) {

        fseek(target_file, 0, SEEK_END);

        size = ftell(target_file);

        return size;
    }

    return -1;
}

int main() {
    
    printf("%ld", getFileSize("7-3.c"));
    return 0;
}