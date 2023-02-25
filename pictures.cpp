#include <iostream>
#include <iomanip>
using namespace std;

//prints a row of numColumns columns where each column is equal to its index * row
void printRow(int row, int numColumns)
{
	for (int i = 1; i <= numColumns; i++)
	{
		cout << row * i << "\t";
	}
}

//prints a horizontal line at the bottom of a table
void printBottom(int columns)
{
	for (int i = 0; i < columns; i++)
	{
		cout << "---------";
	}
	cout << endl;
}

void printTable(int rows, int cols)
{
	if (rows <= 0 || cols <= 0)
		return;
	
	//print header
	cout << "\t";
	printRow(1, cols);
	cout << endl << endl;

	for (int i = 1; i <= rows; i++)
	{
		//print sidebar
		cout << i << "\t";
		printRow(i, cols);
		cout << endl;
	}
	printBottom(cols);
	cout << endl;
}

//print numSpaces whitespaces
void printSpace(int numSpaces)
{
	for (int i = 0; i < numSpaces; i++)
		cout << " ";
}

//print numStars *'s
void printStars(int numStars)
{
	for (int i = 0; i < numStars; i++)
		cout << "*";
}

//print a little pyramid of stars with a given number of layers
void pyramid(int layers)
{
	int numStars = 1;
	for (int i = 0; i < layers; i++)
	{
		printSpace(layers - (i + 1));
		printStars(numStars);
		cout << endl;
		numStars += 2;
	}
}

int main()
{
	//print tables
	printTable(4,6);
	cin.get();
	printTable(11,12);
	cin.get();
	
	//print pyramids
	pyramid(10);
	cin.get();
	pyramid(25);
	cin.get();
}