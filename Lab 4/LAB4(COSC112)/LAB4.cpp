/*Leo Genota
COSC 112 HONORS
Dr. Stone
September 15, 2016
-This program will compute the total number of miles a car can travel
when the size of the gas tank and the miles per gallon are entered by the user.
*/
#include <iostream>
using namespace std;

int main()
{
	int size, mPG, totMiles;

	cout << "Enter an integer for the size of the gas tank of the car in gallons: ";
	cin >> size;
	cout << endl;

	cout << "Enter an integer for the miles per gallon of the car: ";
	cin >> mPG;
	cout << endl;

	totMiles = size * mPG;

	cout << "Total miles the car can travel wihtout refueling: " << totMiles << endl;

	system("pause");
	return 0;
}
/*
#include <iostream>

using namespace std;

int main()
{
int gasTankSize, milesPerGallon, totalMiles;

cout << "Enter the size of the gas tank of the car in gallons: ";
cin >> gasTankSize;
cout << endl;

cout << "Enter the MPG of the vehicle: ";
cin >> milesPerGallon;
cout << endl;

totalMiles = gasTankSize * milesPerGallon;

cout << "The total number of miles you can drive without refueling is: " << totalMiles << endl;

system("PAUSE");
return 0;
*/