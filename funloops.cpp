#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//checks to see if a target is equal to the sum of an incrementing list of ints
//basically, if there is a list of the pattern that 1+2+3+...+n = target
bool checkSum(int target)
{
	int sum = 0, increment = 1;
	while (sum < target)
		sum+=increment++;
	return (sum == target);
}

//find first n magic squares
void magicSquares(int n)
{
	int count = 0;
	int base = 1; //starts at first perfect square
	double square = pow(base, 2);

	//checks all perfect squares to determine if they are magic squares
	//until count reaches n
	while (count < n)
	{
		if (checkSum(int(square)))
		{
			cout << "Magic square " << count+1 << ":\t" << square << endl;
			count++;
		}
		base += 1;
		square = pow(base, 2);
	}
}

//reverses an integer, not including leading zeroes
int reverseInt(int toReverse)
{
	int reversed = 0;
	while(toReverse != 0)
	{
		//add last digit of toReverse to the end of reversed
		reversed = reversed*10 + toReverse%10;
		//remove last digit of toReverse
		toReverse /= 10;
	}
	return reversed;
}

//returns whether an int is evenly divisible by a given divisor
bool isDivisible(int divisible, int divisor)
{
	return (divisible % divisor) == 0;
}

//find the least common multiple of two given integers
int leastCommonMultiple(int a, int b)
{
	int multiple;
	int base = 1;
	//while multiple is less than highest possible lcm
	while (multiple < a*b)
	{
		multiple = a*base++;
		if (isDivisible(multiple, b))
			return multiple;
	}
	return multiple;
}

int main()
{
	cout << "MAGIC SQUARES" << endl;
	int n;
	cout << "Find n magic squares; n = ";
	cin >> n;
	magicSquares(n);
	cout << endl;
	
	cout << "REVERSE INT" <<endl;
	int toReverse;
	cout << "Int to reverse: ";
	cin >> toReverse;
	cout << reverseInt(toReverse) << endl << endl;

	cout << "LEAST COMMON MULTIPLE" << endl;
	int a, b;
	cout << "Int a = ";
	cin >> a;
	cout << "Int b = ";
	cin >> b;
	cout << "Least Common Multiple of " << a << " and " << b 
	<< " : " << leastCommonMultiple(a,b) << endl;
}