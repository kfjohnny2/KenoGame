/*This class is for usefull methods along the application*/

#include <string.h>
#include <stdio.h>
#include <iostream>// Basic I/O.
#include <fstream> // For handling files.
#include <sstream> // For the stringstream.
#include <cstring>
#include <vector>
#include <stdlib.h>

using namespace std;

std::vector<int>
tokenization(string token, ifstream file){
    std::vector<int> m_spots;
    int spots = 0;
    int aposta=0;
    int rounds = 0;
    int cont = 0;
    while(std::getline(file, token)) {
        std::stringstream line(token);
        while(line >> token) {
            aposta = atoi(line.str().c_str());
            cont++;
            if(file.unget().get() == '\n') {
                   rounds = atoi(line.str().c_str());
                   cont++;
                   if(file.unget().get() == '\n') {
                        spots = atoi(line.str().c_str());
                        m_spots.insert(m_spots.begin(), spots);
                        cont++;
                    }
               }
                if (cont == 3){
                    break;
                }
            }

        }
        cout << rounds;
        cout << aposta;
        for(int i =0; i<5 ; i++){
            cout << m_spots[i];
        }
    return m_spots;
}
