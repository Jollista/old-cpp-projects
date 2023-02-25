#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;

int positions[3];
bool turnSkip[3];
int whoseTurn;

//returns whether or not a player has reached the end
bool gameOver()
{
	cout << "Player A : " << positions[0] << endl;
	cout << "Player B : " << positions[1] << endl;
	cout << "Player C : " << positions[2] << endl << endl;
	return (positions[0] >= 30 || positions[1] >= 30 || positions[2] >= 30);
}

//determine whose turn it is and return
void determineTurn()
{
	if (++whoseTurn == 3)
		whoseTurn = 0;
	
	while(turnSkip[whoseTurn])
	{
		turnSkip[whoseTurn] = false;
		if (++whoseTurn == 3)
			whoseTurn = 0;
	}
}

void sendToStart()
{
	for (int i = 0; i < sizeof(positions); i++)
	{
		if (i != whoseTurn)
			if (positions[i] == positions[whoseTurn])
				positions[i] = 0;
	}
}

//rolls a d8 and returns the game specific result
//(back if 4, no movement if 6)
int rollDie()
{
	return rand() % 8 + 1;
}

//take turn of whoseTurn
void takeTurn()
{
	//roll die and update position
	int roll = rollDie();
	positions[whoseTurn] += roll;
	cout << "PLAYER " << char(whoseTurn+65) << " ROLLING ... " << roll << "!" << endl;
	
	//instead of moving forward, go back 4 spaces if you roll a 4
	if (roll == 4)
		positions[whoseTurn] -= 8;
	
	//instead of moving, pass turn and skip next turn if you roll a 6
	else if (roll == 6)
	{
		positions[whoseTurn] -= 6;
		turnSkip[whoseTurn] = true;
	}

	sendToStart();

	//set to start if less than start
	if (positions[whoseTurn] < 0)
		positions[whoseTurn] = 0;
}

//returns position of given player as a string
string positionOf(int player)
{	
	//check start
	if (positions[player] == 0)
		return "START";

	//check end
	if (positions[player] >= 30)
		return "END";

	//check the rest of the board
	return to_string(positions[player]);
}

//prints the result of the game
void printResult()
{
	cout << "A-" << positionOf(0) << ", ";
	cout << "B-" << positionOf(1) << ", ";
	cout << "C-" << positionOf(2) << endl;
}

int main()
{
	//initialize randomness
	srand(time(0));

	//initialize board
	positions[0] = 0, positions[1] = 0, positions[2] = 0;
	turnSkip[0] = false, turnSkip[1] = false, turnSkip[2] = false;
	whoseTurn = -1; //start at -1, since determineTurn() increments whoseTurn

	cout << "Starting game." << endl;

	while(!gameOver())
	{
		determineTurn();
		takeTurn();
		//printResult();
	}
	printResult();
}