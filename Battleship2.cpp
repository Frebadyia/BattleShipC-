// Battleship2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <time.h>

const int rows = 10;
const int elements = 10;
int maxships = 10;
int matrix[rows][elements];

// 0 = blank
// 1 = ship that isn't sunk
// 2 = ship that is sunk

void clear()
{
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < elements; j++) 
		{
			matrix[i][j] = 0;
		}
	}
}

//Show the map, placing a space between each number
void show()
{
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < elements; j++) 
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int numberofships()
{
	int c = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < elements; j++)
		{
			if (matrix[i][j] == 1)
				c++;
		}
	}
	return c;
}

//Set ships in random spots on the grid
void setships()
{
	int s = 0;
	while (s < maxships)
	{
		int x = rand() % rows;
		int y = rand() % elements;

		if (matrix[x][y] != 1)
		{
			s++;
			matrix[x][y] = 1;
		}
	}
}

//If a ship was hit, change its placement holder to 2 instead of 1
bool attack(int x, int y)
{
	if (matrix[x][y] == 1)
	{
		matrix[x][y] = 2;
		return true;
	}
	return false;
}
int main(void)
{
	int pos1, pos2;
	int count = 0;
	int max_guesses = 10;

	srand(time(NULL));
	clear();
	setships();
	//show();
	while (1)
	{
		std::cout << "Enter location: ";
		std::cin >> pos1 >> pos2;

		if (isdigit(pos1))
		{
			std::cout << "Not a number, enter a number between 0 - 9" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');

		}
		if (pos1 < 0 || pos1 > 9)
		{
			std::cout << "Position 1 value invalid. Enter number between 0 - 9" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		
		if (pos2 < 0 || pos2 > 9)
		{
			std::cout << "Position 2 value invalid. Enter a number between 0 - 9" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}

		if (attack(pos1, pos2))
			std::cout << "You got me! " << std::endl;
		else
			std::cout << "You missed! " << std::endl;

		std::cout << "Number of ships left: " << numberofships() << std::endl;
		std::cout << "Number of missiles left: " << max_guesses - count << std::endl;
		std::cout << std::endl;
		
		if (count == 10)
			break;

		count++;
		
	}
	std::cout << "Game over!" << std::endl;
	show();
	system("pause");
	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
