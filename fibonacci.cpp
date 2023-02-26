#include <iostream>
#include <iomanip>
using namespace std;

int fibonacciHelper(int a, int b, int acc)
{
	if (acc == 0)
	{
		cout << a << endl;
		return a;
	}
	cout << a << ", ";
	return fibonacciHelper(b, a+b, acc-1);
}

int fibonacci(int n)
{
	return fibonacciHelper(0, 1, n);
}

int main()
{
	int n, result;
	cout << "Find nth term in fibonacci sequence; n = ";
	cin >> n;
	cout << endl;
	result = fibonacci(n);
	cout << "\nFibonacci at " << n << " = " << result << endl;
}