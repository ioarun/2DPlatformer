#!/bin/bash

appRunning=1

while [ $appRunning == 1 ]; do
	echo Compile and run[1], Compile[2], Exit[3]
	read user

	if [[ $user == 1 ]]; then
		echo Compiling and then running...
		g++ -c src/*.cpp -std=c++14 
		g++ *.o -o bin/Game -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
		./bin/Game
		read -n 1 -s
		clear
	elif [[ $user == 2 ]]; then
		echo Compiling...
		g++ -c src/*.cpp -std=c++14 -Werr
		g++ *.o -o bin/Game -lsfml-graphics -lsml-window -lsfml-system -lsfml-audio -lsfml-network
		read -n 1 -s
		clear
	elif [[ $user == 3 ]]; then
		exit

	fi

done