//Leo Genota
//COSC 112 Honors
//Dr. Stone
//This program will convert the Quiz program to read from a file.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream inFile;
ofstream outFile;

int main()
{
	inFile.open("lab6.txt");
	outFile.open("lab6Output.txt");

	string productName;
	double productCost, markDown;
	double discountAmount, finalPrice;

	inFile >> productName >> productCost >> markDown;

	outFile << productName << " originally costs $" << productCost << " with a markdown of " << markDown << endl;
	

	discountAmount = productCost * markDown;
	finalPrice = productCost - discountAmount;

	cout << productName << " used to be $" << productCost << " with a " << markDown
		<< " markdown. You saved $" << discountAmount << " and the final price is $" << finalPrice << endl;

	outFile << "You save $" << discountAmount << " and have a final price of $" << finalPrice << endl;

	inFile.close();
	outFile.close();
	system("PAUSE");

	return 0;
}