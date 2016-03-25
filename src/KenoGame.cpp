#include <iostream>// Basic I/O.
#include <fstream> // For handling files.
#include <sstream> // For the stringstream.
#include <stdio.h>
#include <string.h>
#include <chrono>

#include "KenoDAO.h"
#include "utils.h"

/**
 * @brief Main class of project
 * @details That class will have all functions call for execute the game.
 * @author Irene Ginani e Johnnylee Bryan
 */

using namespace std;

int main(int argc, char *argv[]){
    /**
         * @brief Declaration of the global variables used in the game.
         *
         * .
         *
    */
    string fileName;
    std::vector<int> vSpots;
    std::vector<int> vHits;
    int rounds;
    int spots;
    float wageTotal=0;
    float wageBegin;
    float valueReceived;
    float wagePerRound;
    float valueWon;
    /**
         * @brief Verification of the file name.
         *
         * .
         *
    */
    if(argc > 1){
        fileName = argv[1];
    }else{
        cout << "ERROR! Enter the Data file name that you want to be read!" << endl;
        return -1;
    }
    /**
         * @brief Vector that containing all possible numbers.
         *
         * .
         *
    */
    std::vector<int> kenoNumbers = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
               21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
               41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
               61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80};
  /**
         * @brief Vector that containing all forms of multiply the hits .
         *
         * .
         *
    */
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
    /**
         * @brief Allocation of class methods in the global variables.
         *
         * .
         *
    */

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

    cout << "    Your bet has " << vSpots.size() << " numbers. They are: " ;
    printArray(vSpots, vSpots.size());
    cout << endl;
    cout << "\t -------+------------" << endl;
    cout << "\t Hits   | Payout" << endl;
    cout << "\t -------+------------" << endl;
    for (int i = 0; i < spots; ++i)
    {
    cout << "\t "<< i <<"      |"<<betPyramid[spots-1][i]<<"           " << endl;
    }
    cout << "----------------------------------------------------------------\n";

   /*Start the game*/
    for (int i = 0; i < rounds; ++i)
    {
        cout << "\t This is round #" << i+1 << " of " << rounds << ", and your wage is $"<<wagePerRound<<". Good luck!"<<endl;
        unsigned int randomSeed = std::chrono::system_clock::now().time_since_epoch().count(); /* Define random numbers */
        std::shuffle(kenoNumbers.begin(), kenoNumbers.end(), std::default_random_engine(randomSeed)); /* Shuffle random numbers  */
        // 3) Sortear 20 números: 'draw'
        quickSort(kenoNumbers,0,20); /*Sort random numbers */
        cout << "\t The hits are: ";
        printArray(kenoNumbers, 20); /*Print chosen numbers  */
        cout << "\n\n";

        vHits = keno.getHits(kenoNumbers); /*Found hits */
        cout << "\t You hit the following number(s) ";
        printArray(vHits, vHits.size()); /*Print hits */
        valueReceived = ( wagePerRound * betPyramid[vSpots.size()][vHits.size()]); /*Calculates whether the player won or lost in the round*/
        wageTotal = wageTotal + valueReceived; /*Calculate how much the player has at the end of the game */
        keno.setWage(wageTotal);
        cout << ", a total of " << vHits.size() << " hit(s) out of " << spots << endl;
        cout << "\t Payout rate is " << betPyramid[spots-1][vHits.size()]<< ", thus your came out with: "<<valueReceived<<endl;
        cout << "\t Yout net balance so far is: $" << valueReceived << " dollars" << endl;
        cout << "\t ----------------------------------------------------------------\n";
        // cout << "Seu saldo nessa rodada é: " << wagePerRound << endl;
        // cout << "Agora, seu numero de acertos é: " << vHits.size() << endl;
        // cout << "Agora, a quantidade de numeros que apostou foi: " <<  vSpots.size() << endl;
        // cout << "Agora, vamos multiplicar por: " << betPyramid[vSpots.size()][vHits.size()] << endl;
        valueWon +=valueReceived;
    }
    cout << ">>> End of rounds!"<<endl;
    cout << "----------------------------------------------------------------" <<endl;
    cout << "===== SUMMARY ====="<<endl;
    cout << ">>>You spent int this game a total of $" << wageBegin <<" dollars."<< endl;
    cout << ">>>Hooray, you won $" << valueWon <<" dollars. See you next time! ;-)"<< endl;
    cout << ">>> You are leaving the Keno table with $"<< keno.getWage() << " dollars."<< endl;

    /*Frees memory*/
    vHits.clear();
    kenoNumbers.clear();
    betPyramid.clear();
    return EXIT_SUCCESS;
}
