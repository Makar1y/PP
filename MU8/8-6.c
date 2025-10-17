#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MEMORY_PARTS 100


typedef struct memory_part {
    void *ptr;
    long size;
    int used;
} memory_part;

int _size_of_mp = sizeof(memory_part);
int _MEMORY_PARTS = MEMORY_PARTS;

memory_part *memory_parts = NULL;
int memory_parts_multiplier = 0;
int free_index = 0;


void* memory_parts_realloc() {
    memory_part **save = &memory_parts;
    memory_part *ret;

    long old_capacity = MEMORY_PARTS * memory_parts_multiplier;
    long new_size = sizeof(memory_part) * (MEMORY_PARTS + memory_parts_multiplier * MEMORY_PARTS);
    ret = realloc(memory_parts, new_size);

    if (ret != NULL) {
        *save = ret;
        ++memory_parts_multiplier;
        for (int i = old_capacity; i < old_capacity + MEMORY_PARTS; ++i) {
            memory_parts[i].ptr = NULL;
            memory_parts[i].size = 0;
            memory_parts[i].used = 0;
        }
    }
    return ret;
}

void find_free_index() {
    for (int i = 0; i < MEMORY_PARTS * memory_parts_multiplier; ++i) {
        if (!memory_parts[i].used) {
            free_index = i;
            return;
        }
    }
    memory_parts_realloc();
}


void* myMalloc(long size) {
    find_free_index();
    // For better viewing
    memory_part *mem = &memory_parts[free_index];

    if (size >= 0) {
        (*mem).ptr = malloc(size);
        (*mem).size = size;

        if ((*mem).ptr != NULL)
            (*mem).used = 1;

            return (*mem).ptr;
    }
    return NULL;
}

void* myCalloc(int multiplier, long size) {
    find_free_index();
    // For better viewing
    memory_part *mem = &memory_parts[free_index];

    if (size >= 0) {
        (*mem).ptr = calloc(multiplier , size);
        (*mem).size = size * multiplier;

        if ((*mem).ptr != NULL)
            (*mem).used = 1;

            return (*mem).ptr;
    }
    return NULL;
}

void* myRealloc() {
    
}

int myFree(void *pointer) {
    if (pointer != NULL) {
        for(int i = 0; i < MEMORY_PARTS * memory_parts_multiplier; ++i) {
            if (memory_parts[i].ptr == pointer) {
                free(memory_parts[i].ptr);
                memory_parts[i].ptr = NULL;
                memory_parts[i].size = 0;
                memory_parts[i].used = 0;
                return 0;
            }
        }
    }
    return -1;
}

int getMallocSize(void *pointer) {
    if (pointer != NULL) {
        for(int i = 0; i < MEMORY_PARTS * memory_parts_multiplier; ++i) {
            if (memory_parts[i].ptr == pointer) {
                return memory_parts[i].size;
            }
        }
    }
    return -1;
}

void freeAll() {
    for(int i = 0; i < MEMORY_PARTS * memory_parts_multiplier; ++i) {
        if (memory_parts[i].used) {
            free(memory_parts[i].ptr);
            memory_parts[i].ptr = NULL;
            memory_parts[i].size = 0;
            memory_parts[i].used = 0;
        }
    }
}

void* defragmentMemory() {

}



int main() {
    // Initialization
    memory_parts_realloc();

    int *ptr1 = myMalloc(10);
    char *ptr2 = myCalloc(20, sizeof(char));
    strcpy(ptr2, "Hello world!");

    printf("%s %d\n", ptr2, getMallocSize(ptr2));

    ptr1[9] = 5;

    printf("Size:%d 10 el.:%d\n\n", getMallocSize(ptr1), ptr1[9]);

    myFree(ptr1);
    printf("%p\n\n", ptr1);

    freeAll();
    printf("%p\n\n", ptr2);
    printf("%d %d\n", ptr1[9], getMallocSize(ptr1));


    free(memory_parts);
    return 0;
}
