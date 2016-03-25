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
tokenization(string a){
    std::string token;
    std::ifstream file(a);
    std::vector<int> m_spots;
    float spots = 0;
    float aposta=0;
    unsigned int rounds = 0;
    int cont = 0;
    int spotsCount = 0;
    while(std::getline(file, token)) { /* while exist line, !=null */
    std::stringstream line(token); /* extract the value for the variable */
    while(line >> token) {
       if (cont == DataEnum::BET){ /* converts the value of the string for the variable wage */
       aposta = atoi(token.c_str());
        if (aposta == 0) /* decrements cont because the value is invalid  */
            cont --;
       }
       if (cont == DataEnum::ROUNDS){ /* converts the value of the string for the variable rounds */
       rounds = atoi(token.c_str());
       if (rounds == 0) /* decrements cont because the value is invalid  */
            cont --;
       }
       if (cont == DataEnum::SPOTS){ /*converts the value of the string for the variable spots */
            spots = atoi(token.c_str());
           if ((spots != 0) && (spots>0) && (spots<=80) && spotsCount < 15){ /* verification of the shelf life variable spots  */
                m_spots.insert(m_spots.begin(), spots);
                spotsCount++;
           }
       }
      // cout << "token: " << token << endl;
    }
    if(file.unget().get() == '\n') { /* Detection new lines */
       cont ++;
    //cout << "Nova linha encontrada" << endl;
      }
        if (cont > 2){ /* stop if exist three lines */
           break;
      }
    }
    file.close();

    /*INIT KENOBET CLASS*/
    KenoBet keno(m_spots.size(), rounds);
    keno.setWage(aposta);
    for(unsigned int i =0; i<m_spots.size() ; i++){

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

/**
 * @brief Method that is used for print the vector.
 *
 * @param v Vector that will be print.
 * @param sz size of the vector.
 *
 */
void printArray(std::vector<int> v, unsigned int sz){
    cout << "[";
    for (unsigned int i = 0; i < sz; ++i)
    {
        cout << v[i] << " ";
    }
    cout<< "]";
}

