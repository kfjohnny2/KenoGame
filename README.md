## KenoGame
Versão 1.0 - Quinta-Feira 24 de maço de 2016

por Irene Ginani e Johnnylee Bryan Marques da Rocha

# Introduction
Keno game is a comum casino game that looks like a lottery bet. In this game you choose the value of your bet, the rounds you want to play and the spots you want to bet.

By the information given, the game will generate 20 random number from 1 to 80 and will compare your spots with that numbers. With the hit numbers, the game will calculate your wage by the Payout you have reached on the Bet Pyramid.

Written in C++;

# Instalation

To run the you will have to extract the file "KenoGame-master", and enter the folder by the command line terminal and run the command:

    g++ -Wall -std=c++11 -I include src/KenoGame.cpp src/KenoImpl.cpp src/utils.cpp -o bin/keno

After that you can run the game using the command:

    ./bin/exe /data/*file_name.txt*

Overwrite the *file_name.txt* space with your file name.

We recommend you to use a ".txt" or ".dat" file.

The bet file must have 3 lines, which one will represent respectively: the wage amount to the bet, the rounds you want to play, the spots you will bet on and the ammount must be lower or equal 15 and your numbers must be between 1 and 80.

The game can be played normally

# For a better gameplay

Don't put all the information in one single line of the ".txt" file and dont begin the bet line or the rounds line with letters, that will not be good for the play.

##HAVE FUN!



