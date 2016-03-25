
#include <string.h>
#include <stdio.h>
#include <iostream>// Basic I/O.
#include <fstream> // For handling files.
#include <sstream> // For the stringstream.
#include <cstring>
#include <vector>
#include <stdlib.h>

#ifndef _TOKEN_H_
#define _TOKEN_H_
/**
 * @brief Implementation of the methods present int the class KenoBet
 * @details That class will have all implementation mutators  functions or get methods.
 * @author Irene Ginani e Johnnylee Bryan
 */
using namespace std;
/**
 * @brief Method that will receive the file from the command line.
 * @details That method, will construct the KenoBet class with the data from the file read,
 * like the number of rounds, the bets and the wage.
 *
 * @param fileName Filename that will be read.
 * @return KenoBet The Keno Object with the data from the file read.
 */
KenoBet tokenization(string );
/**
 * @brief Method that is used for sort the vector with 20 random numbers.
 *
 * @param v Vector that will be sorted.
 * @param left Left side of the vector.
 * @param right Most right side of the vector.
 */
void quickSort(std::vector<int>& , int, int );
/**
 * @brief Method that is used for print the vector.
 *
 * @param v Vector that will be print.
 * @param sz size of the vector.
 *
 */
void printArray(std::vector<int> v, unsigned int sz);

#endif