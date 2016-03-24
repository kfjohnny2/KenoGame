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
// 1) Validar os argumentos em linha de comando.
// keno <nome_arquivo_aposta.txt>
	if(argc > 1){
		fileName = argv[1];
	}else{
		cout << "Digite o nome do arquivo de apostas a ser lido" << endl;
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
// 2) Tentar abrir aquivo de apostas.
// 2.1) ler linhas do arquivo - getLine(ifs, string): ifs = inputFileStream
	//utiliza o método de tokenização para retornar o vector desejado
// 2.2) Enquanto não obter float e não acabar o arquivo
//   2.2.1) Tentar converter linha para float (credits)
//   2.2.2) ler nova linhas
// 2.3) Mesmo para quantidade de rodadas.
// 2.4) Mesmo para spots.
// 2.5) Fechar o stream para o arquivo de entrada.
	KenoBet keno = tokenization(fileName);

    cout << "Aposta :" << keno.getWage()<< endl;

    vSpots = keno.getSpots();
    rounds = keno.getRounds();
    spots = keno.numChosen();

    cout << spots << " spots" << endl;
    for(int i =0; i<vSpots.size() ; i++){
        cout << vSpots[i] << endl;
    }

    if(keno.getWage() == 0 || keno.numChosen() == 0 || vSpots.size() == 0){
        cout << "Invalid BET! See your Bet file to find the error!" << endl;
        return EXIT_SUCCESS;
    }
	// PESQUISAR TOKENIZAÇÃO!!!e#$@#%@$#%&$ehyee%&&$%


	// LAÇO A PARTIR DAQUI!
    for (int i = 0; i < rounds; ++i)
    {
        unsigned int randomSeed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(kenoNumbers.begin(), kenoNumbers.end(), std::default_random_engine(randomSeed));
        // 3) Sortear 20 números: 'draw'
        quickSort(kenoNumbers,0,20);
        cout << "Números desta rodada [";
        for (int i = 0; i < 20; ++i)
        {
            cout << kenoNumbers[i] << " ";
        }
        cout << "]" << endl;
    // 4) Verificar quantos números spots estão em draw;
        vHits = keno.getHits(kenoNumbers);
        cout << "os acertos foram [";
        for (int i = 0; i < vHits.size(); ++i)
        {
            cout << vHits[i] << " ";
        }
        cout << "]" << endl;
	// vHits = keno.getHits(draw);
    //      ou identificar os 'hits'.
    //      'hits' = 'draw' interseção com 'spots'
    }

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