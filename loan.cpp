#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double getPrincipal()
{
	double result;
	cout << "Principal = ";
	cin >> result;
	return result;
}

double getYears()
{
	double result;
	cout << "Time = ";
	cin >> result;
	return result;
}

double getLowInterest()
{
	double result;
	cout << "Low Rate = ";
	cin >> result;
	return result/100.0;
}

double getHighInterest()
{
	double result;
	cout << "High Rate = ";
	cin >> result;
	return result/100.0;
}

//calculate the monthly payment a = (p*k*c)/(c-1), where c = (1+k)^n
double calculateMonthlyPayment(double principal, double monthlyRate, int numPayments)
{
	double c = pow((1 + monthlyRate), numPayments);
	double payment = (principal * monthlyRate * c)/(c-1);
	return payment;
}

int main()
{
	//prompt for input
	double years = getYears();
	double principal = getPrincipal();
	double loInterest = getLowInterest();
	double hiInterest = getHighInterest();

	//prepare to output
	cout << "\nAnnual Interest Rate\tMonthly Payment\n\n";
	double annualInterest = loInterest, monthlyPayment;

	//floating point == is a goofy silly little bitch that hates me. Rounding errors. Gotta love em.
	while(annualInterest < hiInterest || abs(annualInterest - hiInterest) < 0.001)
	{
		//calculate monthly payment based on annualInterest
		monthlyPayment = calculateMonthlyPayment(principal, annualInterest/12.0, years*12.0);

		//print rate and monthly payment
		cout << setw(15) << fixed << setprecision(2) << annualInterest * 100
		<< "\t" << setw(15) << monthlyPayment << endl;

		//increment annualInterest by 0.25%
		annualInterest += 0.0025;
	}
}