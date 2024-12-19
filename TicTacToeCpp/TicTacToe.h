#include <vector>
#pragma once
class TicTacToe
{
	public:
		TicTacToe();
		//void start();
		
		void grid(std::vector<std::string>A, std::vector<std::string>B, std::vector<std::string>C);
		void sort();
		void gridChoice(char player, std::vector<std::string>&plChoices);
		bool checkWinner(std::vector<std::string>&plChoices);

		std::vector<std::string>p1Choices;
		std::vector<std::string>p2Choices;

		std::vector<std::string>rowA = { " ", " ", " " };
		std::vector<std::string>rowB = { " ", " ", " " };
		std::vector<std::string>rowC = { " ", " ", " " };
		std::vector<std::string>availablePlaces = { "A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3" };
		std::vector<std::vector<std::string>>winningCombinations = { {"A1", "A2", "A3"}, {"B1", "B2", "B3"}, {"C1", "C2", "C3"}, {"A1", "B1", "C1"}, 
			{"A2", "B2", "C2"}, {"A3", "B3", "C3"}, {"A1", "B2", "C3"}, {"A3", "B2", "C1"} };


		// winningCombinations = (['A1', 'A2', 'A3'], ['B1', 'B2', 'B3'], ['C1', 'C2', 'C3'], ['A1', 'B1', 'C1'], 
		// ['A2', 'B2', 'C2'], ['A3', 'B3', 'C3'], ['A1', 'B2', 'C3'], ['A3', 'B2', 'C1'])
};


