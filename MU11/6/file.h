// #pragma once
#ifndef __FILE_H__
#define __FILE_H__
#include <stdio.h>

/// @brief 
/// @param file Pointer to file to write
/// @param array Pointer to source array(int) first element
/// @param size Size of array
/// @return 1 if write something to file, 0 if not (maybe because of invalid arguments)
extern int saveToFile(FILE *file, const int *array, const size_t size);

/// @brief 
/// @param file Pointer to file from to read
/// @param array Pointer to destination array(int) first element
/// @return 1 if read something from file, 0 if not (maybe because of invalid arguments)
extern int loadFromFile(FILE *file, int *array);

/// @brief 
/// @param file 
/// @return 
extern int getSaveCount(FILE *file);
/// @brief 
/// @param file 
/// @return 
extern int getLoadCount(FILE *file);
#endif