/*This class is for usefull methods along the application*/

#include <string.h>
#include <stdio.h>
#include <iostream>// Basic I/O.
#include <fstream> // For handling files.
#include <sstream> // For the stringstream.
#include <cstring>
#include <vector>
#include <stdlib.h>

#include "KenoDAO.h"
#include "utils.h"

using namespace std;

enum DataEnum: int16_t
{
    BET,
    ROUNDS,
    SPOTS
};

/**
 * @brief Method that will receive the file from the command line.
 * @details That method, will construct the KenoBet class with the data from the file read,
 * like the number of rounds, the bets and the wage.
 *
 * @param fileName Filename that will be read.
 * @return KenoBet The Keno Object with the data from the file read.
 */
KenoBet
tokenization(string fileName){
    std::string token;
    std::ifstream file(fileName);
    std::vector<int> m_spots;
    float spots = 0;
    float aposta=0;
    unsigned int rounds = 0;
    int cont = 0;
    while(std::getline(file, token)) {
    std::stringstream line(token);
    while(line >> token) {
       if (cont == DataEnum::BET){
       aposta = atoi(token.c_str());
       }
       if (cont == DataEnum::ROUNDS){
       rounds = atoi(token.c_str());
       }
       if (cont == DataEnum::SPOTS){
       spots = atoi(token.c_str());
       m_spots.insert(m_spots.begin(), spots);
       }
      // cout << "token: " << token << endl;
      }
    if(file.unget().get() == '\n') {
       cont ++;
    //cout << "Nova linha encontrada" << endl;
      }
        if (cont > 2){
           break;
      }
    }
    file.close();

    /*INIT KENOBET CLASS*/
    KenoBet keno(m_spots.size(), rounds);
    keno.setWage(aposta);
    for(int i =0; i<m_spots.size() ; i++){

        keno.addNumber(m_spots[i]);
    }

    return keno;
}

/**
 * @brief Method that is used for sort the vector with 20 random numbers.
 *
 * @param v Vector that will be sorted.
 * @param left Left side of the vector.
 * @param right Most right side of the vector.
 */
void quickSort(std::vector<int>& v, int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = v[(left + right) / 2];
      /* partition */
      while (i <= j) {
            while (v[i] < pivot)
                  i++;
            while (v[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = v[i];
                  v[i] = v[j];
                  v[j] = tmp;
                  i++;
                  j--;
            }
      };
      /* recursion */
      if (left < j)
            quickSort(v, left, j);
      if (i < right)
            quickSort(v, i, right);

}