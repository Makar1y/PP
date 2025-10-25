#include <stdio.h>

long getFileSize(const char *fileName) {
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


char* largest_input_file(const int argc, char *argv[]){
    char *largest = NULL;
    long max_size = -1;
    long tmp_size = 0;

    for (int i = 1; i <= argc; ++i) {
        tmp_size = getFileSize(argv[i]);

        if ((tmp_size >= 0) && (tmp_size > max_size)) {
            largest = argv[i];
            max_size = tmp_size;
        }
    }

    return largest;
}


int main(const int argc, char *argv[]) {
    const char *name = largest_input_file(argc - 1, argv);
    if (name != NULL) 
        printf("%s\n", name);
    else
        printf("Error or no files get.");
    return 0;
}