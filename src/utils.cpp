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

KenoBet
tokenization(string a){
    std::string token;
    std::ifstream file(a);
    std::vector<int> m_spots;
    float spots = 0;
    float aposta=0;
    unsigned int rounds = 0;
    int cont = 0;
    while(std::getline(file, token)) {
        std::stringstream line(token);
        while(line >> token) {
            switch(cont){
                case DataEnum::BET:
                    aposta = atoi(token.c_str());
                case DataEnum::ROUNDS:
                    rounds = atoi(token.c_str());
                case DataEnum::SPOTS:
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
    KenoBet keno(rounds);
    keno.setWage(aposta);
    for(int i =0; i<m_spots.size() ; i++){

        keno.addNumber(m_spots[i]);
    }

    return keno;
}