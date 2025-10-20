#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* ------------------- Setup ------------------- */

// dynamic array growing part
// 2 for easier testing/debugging
#define MEMORY_PARTS 2

// structure to store memories
typedef struct {
    void *ptr;
    long size;
} Memory;

// Memory array (dynamic to grow if needed)
Memory *memory = NULL;
int memory_parts_multiplier = 0;


/* -------------- Helping functions -------------- */

/// @brief reallocates(grow) system memory array
/// @return if needed reallocation status
void* memory_realloc() {
    Memory **save = &memory;
    Memory *ret;

    long old_capacity = MEMORY_PARTS * memory_parts_multiplier;
    long new_capacity = (memory_parts_multiplier + 1) * MEMORY_PARTS;
    ret = realloc(memory, new_capacity * sizeof(Memory));

    if (ret != NULL) {
        *save = ret;
        ++memory_parts_multiplier;
        for (int i = old_capacity; i < old_capacity + MEMORY_PARTS; ++i) {
            memory[i].ptr = NULL;
        }
    }
    return ret;
}


/// @brief Finds unused memory in memory array
/// @return unused memory array index
int find_free_index() {
    for (int i = 0; i < MEMORY_PARTS * memory_parts_multiplier; ++i) {
        if (memory[i].ptr == NULL) {
            return i;
        }
    }

    int to_ret = MEMORY_PARTS * memory_parts_multiplier;
    memory_realloc();
    return to_ret;
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

    if (size >= 0) {
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

    if (size >= 0) {
        memory[index].ptr = calloc(num_of_elements , size);
        memory[index].size = size * num_of_elements;
        printf("%p\n", memory[index].ptr);
        return memory[index].ptr;
    }
    return NULL;
}


/// @brief 
/// @param pointer 
/// @param new_size 
/// @return 
void* myRealloc(void *pointer, size_t new_size) {
    if (pointer != NULL) {
        for (int i = 0; i < MEMORY_PARTS * memory_parts_multiplier; ++i) {
            // printf("%p\n", memory_parts[i].ptr);
            if (pointer == memory[i].ptr) {
                memory[i].ptr = realloc(pointer, new_size);
                if (memory[i].ptr != NULL) {
                    memory[i].size = new_size;
                }
                return memory[i].ptr;
            }
        }
    }
    return NULL;
}


/// @brief 
/// @param pointer 
/// @return 
int myFree(void *pointer) {
    if (pointer != NULL) {
        for(int i = 0; i < MEMORY_PARTS * memory_parts_multiplier; ++i) {
            if (memory[i].ptr == pointer) {
                free(memory[i].ptr);
                memory[i].ptr = NULL;
                return 0;
            }
        }
    }
    return -1;
}


/// @brief 
/// @param pointer 
/// @return 
long getMallocSize(void *pointer) {
    if (pointer != NULL) {
        for(int i = 0; i < MEMORY_PARTS * memory_parts_multiplier; ++i) {
            if (memory[i].ptr == pointer) {
                return memory[i].size;
            }
        }
    }
    return -1;
}

/// @brief 
void freeAll() {
    for(int i = 0; i < MEMORY_PARTS * memory_parts_multiplier; ++i) {
        if (memory[i].ptr != NULL) {
            memory[i].ptr = realloc(memory[i].ptr, 0);
        }
    }
}

/// @brief 
void defragmentMemory() {
    for (int i = 0; i < MEMORY_PARTS * memory_parts_multiplier; ++i) {
        if (memory[i].ptr == NULL) {
            for (int j = i + 1; j < MEMORY_PARTS * memory_parts_multiplier; ++j) {
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
    if (memory_realloc()) {


        int *ptr1 = myMalloc(10 * sizeof(int));
        char *ptr2 = myCalloc(20, sizeof(char));
        int *ptr3 = myCalloc(5, sizeof(int));
        printf(" ptr3 = %p\n parts[2] = %p", ptr3, memory[2].ptr);

        printf("%s %d\n", ptr2, getMallocSize(ptr2));

        ptr1[9] = 5;

        printf("Size:%d 10 el.:%d\n\n", getMallocSize(ptr1), ptr1[9]);


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
        for (int i = 0; i < MEMORY_PARTS * memory_parts_multiplier; ++i) {
            printf("%p\n", memory[i].ptr);
        }


        free(memory);
    }
    return 0;
}
