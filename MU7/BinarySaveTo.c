#include <stdio.h>
#include <stdlib.h>

#define FILENAME "test.bin"

unsigned long getFileSize(FILE *fileName) {
    unsigned long size;

    fseek(fileName, 0, SEEK_END);

    size = ftell(fileName);

    return size;
}

// Read value -> number_to_write, return -1 or 0
int getValue(FILE *file, const int index, int *number_to_write) {
    if ((index * sizeof(int) < getFileSize(file)) && (index * sizeof(int) >= 0) && (file != NULL)) {
        fseek(file, index * sizeof(int), SEEK_SET);
        if (fread(number_to_write, sizeof(int), 1, file)) {
            return 0;
        }
    }

    return -1;
}

int setValue(FILE *file, const char filename[], const int index, const int value) {
    freopen(filename, "rb+", file);

    if ((index * sizeof(int) < getFileSize(file)) && (index * sizeof(int) >= 0) && (file != NULL)) {
        fseek(file, index * sizeof(int), SEEK_SET);
        if (fwrite(&value, sizeof(int), 1, file)) {
            return 0;
        }
    }

    return -1;
}

int addValue(FILE *file, const char filename[], const int index, const int value) {
    int temp_num1, temp_num2;
    int int_size = sizeof(int);
    int count_of_nums = getFileSize(file) / sizeof(int);

    fclose(file);
    freopen(filename, "rb+", file);

    if ((index <= count_of_nums) && (index >= 0) && (file != NULL)) {
        for (int i = 0; i <= count_of_nums; ++i) {

            // Go to curent index
            fseek(file, i, SEEK_SET);

            // if index
            if (i == index) {
                if (i != count_of_nums) {
                    fread(&temp_num1, int_size, 1, file);
                    fseek(file, -int_size, SEEK_CUR);
                }
                fwrite(&value, int_size, 1, file);
            
            // if EOF and not index
            } else if (i == count_of_nums) {
                fwrite(&temp_num1, int_size, 1, file);

            // If > index and not EOF
            } else if (i > index) {
                fread(&temp_num2, int_size, 1, file);
                fseek(file, -int_size, SEEK_CUR);
                fwrite(&temp_num1, int_size, 1, file);
                temp_num1 = temp_num2;
            }
        }
        return 0;
    }
    return -1;
}

int remValue(FILE *file, const char filename[], const int index) {
    int int_size = sizeof(int);
    int count_of_nums = getFileSize(file) / sizeof(int);
    int *buffer = malloc(int_size * (count_of_nums - 1));

    rewind(file);
    if ((index < count_of_nums) && (index >= 0) && (file != NULL) && (buffer != NULL)) {
        for (int i = 0, buffer_index = 0; i < count_of_nums; ++i) {
            int temp;

            fread(&temp, int_size, 1, file);
            if (i != index) {
                buffer[buffer_index++] = temp;
            }
        }

        freopen(filename, "wb+", file);
        if (file != NULL && count_of_nums == 1){
            return 0;
        } else if (file != NULL) {
            if (fwrite(buffer, int_size, count_of_nums - 1, file)) {
                return 0;
            }
        }  
    }

    return -1;
}

int main() {
    FILE *bin_file = fopen(FILENAME, "rb");
    int num = 0;
    int res;

    if (bin_file != NULL) {
        res = remValue(bin_file, FILENAME, 0);
        if (res == 0) {
            printf("Ok.\n");
        } else {
            printf("File function error.\n");
        }    
    } else {
        perror("Error");
    }

    fclose(bin_file);
    return 0;
}