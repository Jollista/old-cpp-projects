#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//initialize vars
	float hoursWorked, hourlyRate;
	
	//prompt and read input
	cout << "Hours worked" << "\t";
	cin >> hoursWorked;
	cout << "Hourly rate" << "\t";
	cin >> hourlyRate;

	//calculate rates
	float grossPay = hourlyRate*hoursWorked;
	float federal = grossPay*0.15, fica = grossPay*0.08, 
	state = grossPay*0.032, netPay = grossPay - (federal + fica + state);

	//print it
	cout << "\nGross pay\t" << fixed << setprecision(2) << grossPay << endl;
	cout << "\nFederal tax (15%)\t" << fixed << setprecision(2) << federal << endl;
	cout << "FICA (8%)\t\t" << fixed << setprecision(2) << fica << endl;
	cout << "State tax (3.2%)\t" << fixed << setprecision(2) << state << endl;
	cout << "\nNet pay\t" << fixed << setprecision(2) << netPay;
}