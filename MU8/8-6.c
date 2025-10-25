#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* ------------------- Setup ------------------- */
#define MEMORY_SIZE 10

// structure to store memories
typedef struct {
    void *ptr;
    long size;
} Memory;

// Memory array
Memory memory[MEMORY_SIZE] = {0};


/* -------------- Helping functions -------------- */

/// @brief Finds unused memory in memory array
/// @return unused memory array index
int find_free_index() {
    for (int i = 0; i < MEMORY_SIZE; ++i) {
        if (memory[i].ptr == NULL) {
            return i;
        }
    }
    return -1;
}


/// @brief Swap memory in memory array
/// @param index1 first memory index in memory array
/// @param index2 second memory index in memory array
void swap(int index1, int index2) {
    Memory tmp = {memory[index1].ptr, memory[index1].size};

    memory[index1].ptr = memory[index2].ptr;
    memory[index1].size = memory[index2].size;

    memory[index2].ptr = tmp.ptr;
    memory[index2].size = tmp.size;
}


/* -------------- Main functions -------------- */

/// @brief Heap memory allocation in memory array
/// @param size size of memory to allocate
/// @return NULL if unallocated or pointer to memory if allocated
void* myMalloc(size_t size) {
    int index = find_free_index();

    if (index >=0) {
        memory[index].ptr = malloc(size);
        memory[index].size = size;
        return memory[index].ptr;

    }
    return NULL;
}


/// @brief Initialized memory allocation in memory array
/// @param num_of_elements for how number of elements allocate memory
/// @param size size of element
/// @return NULL if unallocated or pointer to memory if allocated
void* myCalloc(int num_of_elements, size_t size) {
    int index = find_free_index();

    if (index >=0) {
        memory[index].ptr = calloc(num_of_elements , size);
        memory[index].size = size * num_of_elements;
        printf("%p\n", memory[index].ptr);
        return memory[index].ptr;
    }
    return NULL;
}


/// @brief Reallocate memory of selected array 
/// @param pointer Pointer to array
/// @param new_size New array size
/// @return Null if failed to reallocate and pointer to new array if success
void* myRealloc(void *pointer, size_t new_size) {
    if (pointer != NULL) {
        for (int i = 0; i < MEMORY_SIZE; ++i) {
            // printf("%p\n", memory_parts[i].ptr);
            if (pointer == memory[i].ptr) {
                void *new_ptr = realloc(pointer, new_size);
                if (new_ptr != NULL) {
                    memory[i].ptr = new_ptr;
                    memory[i].size = new_size;
                }
                return memory[i].ptr;
            }
        }
    }
    return NULL;
}


/// @brief Free array
/// @param pointer Pointer to array
/// @return 0 if success and -1 if error
int myFree(void *pointer) {
    if (pointer != NULL) {
        for(int i = 0; i < MEMORY_SIZE; ++i) {
            if (memory[i].ptr == pointer) {
                free(memory[i].ptr);
                memory[i].ptr = NULL;
                return 0;
            }
        }
    }
    return -1;
}


/// @brief Get size  of array
/// @param pointer pointer to array
/// @return size of array(bytes) or -1 if error
long getMallocSize(void *pointer) {
    if (pointer != NULL) {
        for(int i = 0; i < MEMORY_SIZE; ++i) {
            if (memory[i].ptr == pointer) {
                return memory[i].size;
            }
        }
    }
    return -1;
}

/// @brief Free all memory
void freeAll() {
    for(int i = 0; i < MEMORY_SIZE; ++i) {
        if (memory[i].ptr != NULL) {
            free(memory[i].ptr);
            memory[i].ptr = NULL;
        }
    }
}

/// @brief Defragment memory so there will be no gaps between memories parts
void defragmentMemory() {
    for (int i = 0; i < MEMORY_SIZE; ++i) {
        if (memory[i].ptr == NULL) {
            for (int j = i + 1; j < MEMORY_SIZE; ++j) {
                if (memory[j].ptr != NULL) {
                    swap(i, j);
                    break;
                }
            }
        }
    }
}



int main() {
    // Initialization
    if (memory != NULL) {


        int *ptr1 = myMalloc(10 * sizeof(int));
        char *ptr2 = myCalloc(20, sizeof(char));
        int *ptr3 = myCalloc(5, sizeof(int));
        printf(" ptr3 = %p\n parts[2] = %p\n", ptr3, memory[2].ptr);

        printf("%p %ld\n", ptr2, getMallocSize(ptr2));

        ptr1[9] = 5;

        printf("Size:%ld 10 el.:%d\n\n", getMallocSize(ptr1), ptr1[9]);


        printf("%d\n\n", ptr3[4]);

        printf("ptr before %p\n", ptr3);
        printf("mem[2] before %p\n", memory[2].ptr);
        ptr3 = myRealloc(ptr3, 15 * sizeof(int));
        printf("ptr after %p\n", ptr3);
        printf("mem[2] after %p\n", memory[2].ptr);

        ptr3[12] = 45;
        printf("%d\n\n", ptr3[12]);

        myFree(ptr2);
        defragmentMemory();
        for (int i = 0; i < MEMORY_SIZE; ++i) {
            printf("%p\n", memory[i].ptr);
        }
    }
    return 0;
}