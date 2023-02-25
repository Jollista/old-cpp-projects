#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//converts and returns fahrenheit to celcius
double fToC(double fahrenheit)
{
	return 5.0/9.0 * (fahrenheit - 32.0);
}

//converts and returns celcius to fahrenheit
double cToF(double celcius)
{
	return 9.0/5.0 * celcius + 32;
}

//returns the volume of a sphere
double sphereVolume(double radius)
{
	return 4.0/3.0 * M_PI * pow(radius,3);
}

//returns hypotenuse of a right triangle
double pythagorean(double a, double b)
{
	return sqrt(pow(a,2) + pow(b,2));
}

int main()
{
	//Temperature Conversion
	double fahrenheit, celcius;
	cout << "Temperature Conversion\nFahrenheit: ";
	cin >> fahrenheit;
	cout << "Converted to Celcius: " << fixed << setprecision(2) << fToC(fahrenheit) << endl;
	cout << "Celcius: ";
	cin >> celcius;
	cout << "Converted to Fahrenheit: " << fixed << setprecision(2) << cToF(celcius) << endl;
	cout << endl;

	//Sphere Volume
	double radius;
	cout << "Sphere Volume\nRadius: ";
	cin >> radius;
	cout << "Volume: " << fixed << setprecision(2) << sphereVolume(radius) << endl;
	cout << endl;

	//Pythagorean Theorem
	double a, b;
	cout << "Pythagorean Theorem\na: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "Hypotenuse: " << fixed << setprecision(2) << pythagorean(a, b) << endl;
	cout << endl;
}