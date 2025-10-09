#include <stdio.h>

#define FILENAME "test.bin"
#define TEST_INT 5

unsigned long getFileSize(FILE *fileName) {
    unsigned long size;

    fseek(fileName, 0, SEEK_END);

    size = ftell(fileName);

    return size;
}

// Read value -> number_to_write, return -1 or 0
int getValue(FILE *filename, int index, int *number_to_write) {
    int number = -1;

    if ((index * sizeof(int) < getFileSize(filename)) && (index * sizeof(int) >= 0) ) {
        fseek(filename, index * sizeof(int), SEEK_SET);
        if (fread(number_to_write, sizeof(int), 1, filename)) {
            return 0;
        }
    }

    return -1;
}

int setValue(FILE *filename, int index, int value) {

    if ((index * sizeof(int) < getFileSize(filename)) && (index * sizeof(int) >= 0)) {
        fseek(filename, index * sizeof(int), SEEK_SET);
        if (fwrite(&value, sizeof(int), 1, filename)) {
            return 0;
        }
    }

    return -1;
}

int addValue(FILE *filename, int index, int value) {
    int temp;

    if ((index * sizeof(int) <= getFileSize(filename)) && (index * sizeof(int) >= 0)) {
        fseek(filename, -(int)(sizeof(int) - 1), SEEK_END); // Last number start position

        // Move elements to right
        while (ftell(filename) != (index * sizeof(int))) {
            fread(&temp, sizeof(int), 1, filename);
            fwrite(&temp, sizeof(int), 1, filename);
            fseek(filename, (int)sizeof(int) * -3, SEEK_CUR);
        };

        // Move last element
        fread(&temp, sizeof(int), 1, filename);
        fwrite(&temp, sizeof(int), 1, filename);
        fseek(filename, (int)sizeof(int) * -2, SEEK_CUR);

        // Write value
        if (fwrite(&value, sizeof(int), 1, filename)) {
            return 0;
        }
    }

    return -1;
}

int main() {
    FILE *bin_file = fopen(FILENAME, "rb+");
    int num = 0;
    int res;

    if (bin_file != NULL) {
        res = addValue(bin_file, 1, TEST_INT);
        if (res == 0) {
            printf("Ok.\n");
        } else {
            printf("File function error.\n");
        }    
    } else {
        printf("Error...\n");
        perror("");
    }

    fclose(bin_file);
    return 0;
}