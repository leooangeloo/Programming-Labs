// Leo Genota
// COSC 112
// Dr. Stone
// This program allows numerical input from the user, outputs the first number,
// tells whether it is pos, neg, or zero, and then puts the numbers in ascending order.
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int num1, num2, num3;

	cout << "Enter three integers, separated by a space: " << endl;
	cin >> num1 >> num2 >> num3;
	cout << endl;

	if (num1 > 0)
		cout << "The first number " << num1 << " is " << "positive." << endl;
	else if (num1 == 0)
		cout << "The first number " << num1 << " is " << "zero." << endl;
	else if (num1 < 0)
		cout << "The first number " << num1 << " is " << "negative." << endl;

	if ((num1 > num2) && (num2 > num3))
		cout << "The #'s in ascending order are: " << num3 << " " << num2 << " " << num1 << endl;
	else if ((num1 > num3) && (num3 > num2))
		cout << "The #'s in ascending order are: " << num2 << " " << num3 << " " << num1 << endl;
	else if ((num2 > num1) && (num1 > num3))
		cout << "The #'s in ascending order are: " << num3 << " " << num1 << " " << num2 << endl;
	else if ((num2 > num3) && (num3 > num1))
		cout << "The #'s in ascending order are: " << num1 << " " << num3 << " " << num2 << endl;
	else if ((num3 > num1) && (num1 > num2))
		cout << "The #'s in ascending order are: " << num2 << " " << num1 << " " << num3 << endl;
	else if ((num3 > num2) && (num2 > num1))
		cout << "The #'s in ascending order are: " << num1 << " " << num2 << " " << num3 << endl;
	else
		cout << "Error: Numbers inputted are not valid or are not within range of program." << endl;


	system("PAUSE");
	return 0;

}