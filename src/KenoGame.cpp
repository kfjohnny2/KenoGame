#include <iostream>// Basic I/O.
#include <fstream> // For handling files.
#include <sstream> // For the stringstream.
#include <stdio.h>
#include <string.h>

#include "KenoDAO.h"
#include "utils.cpp"

using namespace std;

int main(string argc, char const *argv[]){

	string fileName;
	std::vector<int> v_bets;
	string token;
// 1) Validar os argumentos em linha de comando.
// keno <nome_arquivo_aposta.txt>
	if(argc != nullptr){
		fileName = argc;
	}else{
		cout << "Digite o nome do arquivo de apostas a ser lido" << endl;
		return -1;
	}


// 2) Tentar abrir aquivo de apostas.
// 2.1) ler linhas do arquivo - getLine(ifs, string): ifs = inputFileStream

	//utiliza o método de tokenização para retornar o vector desejado
	v_bets = utils::tokenization(token, fileName);

// 2.2) Enquanto não obter float e não acabar o arquivo
//	 2.2.1) Tentar converter linha para float (credits)
//	 2.2.2) ler nova linhas
// 2.3) Mesmo para quantidade de rodadas.
// 2.4) Mesmo para spots.
// 2.5) Fechar o stream para o arquivo de entrada.

	// KenoBet myBet(15);

	// myBet.addNumber(spot);
	// myBet.setWage( valor_lido_do_arquivo);

	// PESQUISAR TOKENIZAÇÃO!!!e#$@#%@$#%&$ehyee%&&$%

	// LAÇO A PARTIR DAQUI!
	// 3) Sortear 20 números: 'draw'
	// 4) Verificar quantos números spots estão em draw;
	//		ou identificar os 'hits'.
	//		'hits' = 'draw' interseção com 'spots'

	// hits = myBet.getHits(draw);

	//5) Calcular o premio com base na quantidade de hits.

	char str[] = " - dasd - asdasd";
	char * pch;
	pch = strtok(str, "-");
	while(pch != nullptr){
		printf("%s\n", pch);
	}

}