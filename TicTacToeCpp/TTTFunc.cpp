#include <iostream>
#include <random>
#include <time.h>
#include <vector>
#include <cctype>
#include <algorithm> 
#include "TicTacToe.h"

//TicTacToe::TicTacToe(){}

TicTacToe::TicTacToe() {
	char player1;
	char player2;
	srand(time(NULL));
	int a = rand() % 2; // randoming choice of O and X
	if (a == 0)
	{
		player1 = 'X';
		player2 = 'O';
	}	
	else {
		player1 = 'O';
		player2 = 'X';
	}

	std::cout << "P1: " << player1 << " | P2: " << player2 << std::endl;
	while (availablePlaces.size() != 0) {
		TicTacToe::grid(rowA, rowB, rowC);
		TicTacToe::gridChoice(player1, p1Choices);
		if (p1Choices.size() == 5 && !checkWinner(p1Choices)) {
			std::cout << "Draw!" << std::endl;
			TicTacToe::TicTacToe();
		}
		if (checkWinner(p1Choices)) {
			std::cout << player1<<" wins!"<<std::endl;
			TicTacToe::TicTacToe();
		}
		TicTacToe::grid(rowA, rowB, rowC);
		TicTacToe::gridChoice(player2, p2Choices);
		if (checkWinner(p2Choices)) {
			std::cout << player2 << " wins!" << std::endl;
			TicTacToe::TicTacToe();
		}
	}
	
	//sort();
}

void TicTacToe::gridChoice(char player, std::vector<std::string>&plChoices) {
	std::string choice;
	while (true) {
		std::cin >> choice;
		int cnt = count(availablePlaces.begin(), availablePlaces.end(), choice); //checking if choice is valid
		if (cnt == 1) {
			char row = (char)choice[0];
			std::string columnStr = choice.substr(1);
			int column = atoi(columnStr.c_str());
			//std::cout << row << ", " << columnChar;
			plChoices.push_back(choice);
			availablePlaces.erase(std::remove(availablePlaces.begin(), availablePlaces.end(), choice), availablePlaces.end()); //if valid remove form all choices
			switch (row)
			{
			case 'A':
				rowA[column - 1] = std::string() + player;
				break;
			case 'B':
				rowB[column - 1] = std::string() + player;
				break;
			case 'C':
				rowC[column - 1] = std::string() + player;
				break;
			}
			break;
		}
		else {
			std::cout << "Invalid place, try another one!" << std::endl;
		}
	}
	
}

bool TicTacToe::checkWinner(std::vector<std::string>&plChoices) {
	std::sort(std::begin(plChoices), std::end(plChoices));
	bool found = std::any_of(winningCombinations.begin(), winningCombinations.end(),[&plChoices](const std::vector<std::string>& winningCombinations) {
			return std::all_of(winningCombinations.begin(), winningCombinations.end(),
				[&plChoices](const std::string& elem) {
					return std::find(plChoices.begin(), plChoices.end(), elem) != plChoices.end();
				});
		});
	if (found) {
		return true;
	}
	return false;
}

void TicTacToe::sort() { // helping to understand how sort works wth winComb
	std::string as[3] = { "B3", "B2", "B1" };
	for (int i = 0; i < 3; i++) {
		if (i == 0)
			std::cout << "Przed: ";
		std::cout << "[" << as[i] << "]  ";
	}
	std::sort(std::begin(as), std::end(as));
	for (int i = 0; i < 3; i++) {
		if (i == 0)
			std::cout << "Po: ";
		std::cout << "[" << as[i] << "]  ";
	}
}

void TicTacToe::grid(std::vector<std::string>A, std::vector<std::string>B, std::vector<std::string>C)
{
	std::cout << "   1   2   3" << std::endl;
	std::cout << "A [" << A[0] << "] [" << A[1] << "] [" << A[2] << "]" << std::endl;
	std::cout << "B [" << B[0] << "] [" << B[1] << "] [" << B[2] << "]" << std::endl;
	std::cout << "C [" << C[0] << "] [" << C[1] << "] [" << C[2] << "]" << std::endl;
	std::cout << std::endl;
}

