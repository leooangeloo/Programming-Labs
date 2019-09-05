#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream inFile;

int main()
{
	inFile.open("input.txt");

	string gender;
	int age;
	double oldPay, youngPay;

	inFile >> age >> gender;

	oldPay = age * 2;
	youngPay = age;
	
	if ((age >= 21) && (gender == "male"))
		cout << "You are a male, age 21 or older, thus you will pay 2 times your age (" << age << "), which is $"
		<< oldPay << endl;
	else
		cout << "You are female or male under 21. Please pay your age: $" << youngPay << endl;

	system("PAUSE");

	return 0;
}