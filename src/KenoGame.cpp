#include <iostream>// Basic I/O.
#include <fstream> // For handling files.
#include <sstream> // For the stringstream.
#include <stdio.h>
#include <string.h>
#include <chrono>

#include "KenoDAO.h"
#include "utils.h"

using namespace std;

int main(int argc, char *argv[]){

	string fileName;
    std::vector<int> vSpots;
    std::vector<int> vHits;
    int rounds;
    int spots;
    float wageTotal;
    float wageBegin;
    float valueReceived;
    float wagePerRound;

    if(argc > 1){
        fileName = argv[1];
    }else{
        cout << "ERROR! Enter the Data file name that you want to be read!" << endl;
        return -1;
    }
    std::vector<int> kenoNumbers = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
               21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
               41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
               61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80};

    std::vector<std::vector<float>> betPyramid = {
        {0,3},
        {0,1,9},
        {0,1,2,16},
        {0,0.5,2,6,12},
        {0,0.5,1,3,15,50},
        {0,0.5,1,2,3,30,75},
        {0,0.5,0.5,1,6,12,36,100},
        {0,0.5,0.5,1,3,6,19,90,720},
        {0,0.5,0.5,1,2,4,8,20,80,1200},
        {0,0,0.5,1,2,3,5,10,30,600,1800},
        {0,0,0.5,1,1,2,6,15,25,180,1000,3000},
        {0,0,0,0.5,1,2,4,24,72,250,500,2000,4000},
        {0,0,0,0.5,0.5,3,4,5,20,80,240,500,3000,6000},
        {0,0,0,0.5,0.5,2,3,5,12,50,150,500,1000,2000,7500},
        {0,0,0,0.5,0.5,1,2,5,15,50,150,300,600,1200,2500,10000}
    };

    cout << ">>> Preparing to read bet file " <<  fileName << ", please wait..." << endl;
    cout << "----------------------------------------------------------------" << endl;
	KenoBet keno = tokenization(fileName);
    wageBegin = keno.getWage();
    vSpots = keno.getSpots();
    rounds = keno.getRounds();
    spots = keno.numChosen();
    wagePerRound = (wageBegin/rounds);


    if(keno.getWage() == 0 || keno.numChosen() == 0 || vSpots.size() == 0){
        cout << "Invalid BET! See your Bet file to find the error!" << endl;
        return EXIT_SUCCESS;
    }

    cout << ">>> Bet succesfully read!\n" << "    You are going to wage a total of $"<< wageBegin <<" dollars.\n" << "    Going for a total of " << rounds << ", waging $" << wagePerRound << " per round." << endl;
    cout << "\n\n";
    // PESQUISAR TOKENIZAÇÃO!!!e#$@#%@$#%&$ehyee%&&$%

    cout << "    Your bet has " << vSpots.size() << " numbers. They are: ";
    printArray(vSpots, vSpots.size());

    cout << "\t -------+------------" << endl;
    cout << "\t Hits   | Payout" << endl;
    cout << "\t -------+------------" << endl;
    for (int i = 0; i < spots; ++i)
    {
    cout << "\t "<< i <<"      |"<<betPyramid[spots][i]<<"           " << endl;
    }
    cout << "\n";

    // LAÇO A PARTIR DAQUI!
    for (int i = 0; i < rounds; ++i)
    {
        unsigned int randomSeed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(kenoNumbers.begin(), kenoNumbers.end(), std::default_random_engine(randomSeed));
        // 3) Sortear 20 números: 'draw'
        quickSort(kenoNumbers,0,20);

        printArray(kenoNumbers, 20);


    // 4) Verificar quantos números spots estão em draw;


        vHits = keno.getHits(kenoNumbers);
        cout << "Your hits in this rounds were ";
        printArray(vHits, vHits.size());
        cout << "Agora, seu saldo é: " << keno.getWage() << endl;
        cout << "Agora, seu numero de acertos é: " << vHits.size() << endl;
        cout << "Agora, a quantidade de numeros que apostou foi: " <<  vSpots.size() << endl;
        cout << "Agora, vamos multiplicar por: " << betPyramid[vSpots.size()][vHits.size()] << endl;

        valueReceived = ( wageBegin * betPyramid[vSpots.size()][vHits.size()]);
        cout << "Agora, seu saldo nessa rodada é: " << valueReceived << endl;
        wageTotal = wageTotal + valueReceived;
        keno.setWage(wageTotal);
    // vHits = keno.getHits(draw);
    //      ou identificar os 'hits'.
    //      'hits' = 'draw' interseção com 'spots'
    }
    cout << "Seu saldo total é: " << keno.getWage() << endl;

    vHits.clear();
    kenoNumbers.clear();
    betPyramid.clear();
	//5) Calcular o premio com base na quantidade de hits.

	// char str[] = " - dasd - asdasd";
	// char * pch;
	// pch = strtok(str, "-");
	// while(pch != nullptr){
	// 	printf("%s\n", pch);
	// }
	return EXIT_SUCCESS;
}