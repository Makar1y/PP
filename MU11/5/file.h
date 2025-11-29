// #pragma once
#ifndef __FILE_H__
#define __FILE_H__

extern int saveCount;
extern int loadCount;

/// @brief Save int array to file
/// @param file Pointer to file to write
/// @param array Pointer to source array
/// @param size Size of array
/// @return 1 if write something to file, 0 if not (maybe because of invalid arguments)
extern int saveToFile(FILE *file, const int *array, const size_t size);

/// @brief Load int array from file
/// @param file Pointer to file from to read
/// @param array Pointer to destination array
/// @return 1 if read something from file, 0 if not (maybe because of invalid arguments)
extern int loadFromFile(FILE *file, int *array);
#endif