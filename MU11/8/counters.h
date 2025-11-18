// #pragma once
#ifndef __COUNTERS_H__
#define __COUNTERS_H__


/// @brief Get file saves count
/// @param file 
/// @return 0 if file not found in tracked file list(has 0 saves), otherwise number of saves.
extern int getSaveCount(FILE *file);

/// @brief Get file loads count
/// @param file 
/// @return 0 if file not found in tracked file list(has 0 loads), otherwise number of loads.
extern int getLoadCount(FILE *file);

/// @brief + count to file saves count
/// @param file 
void addSaveCount(FILE *file);

/// @brief + count to file loads count
/// @param file 
void addLoadCount(FILE *file);
#endif