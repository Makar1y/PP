// #pragma once
#ifndef __FILE_H__
#define __FILE_H__


/// @brief Save array to file
/// @param file Pointer to file to write
/// @param array Pointer to source array
/// @param size Size of array
/// @param element_size Size of array element
/// @return 1 if write something to file, 0 if not (maybe because of invalid arguments)
extern int saveToFile(FILE *file, const void *array, const size_t size, const size_t element_size);

/// @brief Load array from file
/// @param file Pointer to file from to read
/// @param array Pointer to destination array
/// @param element_size Size of array element
/// @return 1 if read something from file, 0 if not (maybe because of invalid arguments)
extern int loadFromFile(FILE *file, void *array, const size_t element_size);
#endif