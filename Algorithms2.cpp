//By Alan Kokaev
#include <iostream>
#include <conio.h>
#include <vector>
#include <ctime>
#include <random>
#include <iomanip>
#include "stdlib.h"
using namespace std;

		//	0 1 0 1 0
		//	1 0 0 0 1
		//	0 0 H 0 0
		//	1 0 0 0 1
		//	0 1 0 1 0

		// i -> y 
		// j -> x

		// board[i+1][j+2]; rightdown
		// board[i-1][j+2]; rightup
		// board[i+1][j-2]; lefttdown
		// board[i-1][j-2]; lefttup
		// board[i-2][j+1]; upright
		// board[i-2][j-1]; upleft
		// board[i+2][j+1]; downright
		// board[i+2][j-1]; downleft

const int SIZE = 8;
class SecondLab
{
	int arrX[8] = { 1,2,2,1,-1,-2,-2,-1 };
	int arrY[8] = { 2,1,-1,-2,-2,-1,1,2 };
	int board[SIZE][SIZE] = {};
	int iter;
public:
	SecondLab() { iter = 0; }
	void show()
	{
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
				cout << setw(3) << board[i][j];
			cout << "\n";
		}
	}
	void horse(int counter, int i, int j)
	{
		board[i][j] = counter++;
		int inew = 0, jnew = 0;
		for (int k = 0; k < 8; k++)
		{
			inew = i + arrY[k];
			jnew = j + arrX[k];

			if (counter > SIZE*SIZE)
			{
				show();
				cout << "\nmin number is " << iter;
				_getch();
				exit(0);
			}
			if (inew<0 || inew>SIZE - 1 || jnew<0 || jnew>SIZE - 1 || board[inew][jnew] != 0)
				continue;
			horse(counter, inew, jnew);
			board[inew][jnew] = 0;
			if (board[inew][jnew] == 0)
				iter++;
		}
	}
};

int main()
{
	SecondLab object;
	object.horse(1, 0, 0);

 _getch();
}
