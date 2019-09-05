#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double num1, num2;
	double sum, difference, product, quotient;
	char operator1;

	cout << "Enter two integers and an operator, separated by a space (Example: 4 7 +)" << endl;
	cin >> num1 >> num2 >> operator1;

	switch (operator1)
	{
	case '+': sum = num1 + num2;
		cout << num1 << " + " << num2 << " = " << sum << endl;
		break;
	case '-': difference = num1 - num2;
		cout << num1 << " - " << num2 << " = " << difference << endl;
		break;
	case '*': product = num1 * num2;
		cout << num1 << " * " << num2 << " = " << product << endl;
		break;
	case '/': quotient = num1 / num2;
		cout << num1 << " / " << num2 << " = " << quotient << endl;
		break;
	default: cout << "INPUT ERROR. TRY AGAIN." << endl;
	}
	system("PAUSE");
	return 0;

}