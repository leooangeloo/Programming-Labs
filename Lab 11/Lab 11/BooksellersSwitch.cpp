#include <iostream>
using namespace std;

int main()
{
	int numBooksPurchased;
	double amntSpent, payBackAmnt;

	cout << "How many books did you buy this month? " << endl;
	cin >> numBooksPurchased;
	cout << "How much, in total, did you spend at the store this month?" << endl;
	cin >> amntSpent;

	switch (numBooksPurchased)
	{
	case '0': cout << "You will receive a 0% payback. We value your support and please come again." << endl;
		break;
	case '1': payBackAmnt = (2 * amntSpent) / 100;
		cout << "You will receive a $" << payBackAmnt << " reward check for the $" << amntSpent << " spent on " << numBooksPurchased << " books last month." << endl;
		break;
	case '2': payBackAmnt = (3.5 * amntSpent) / 100;
		cout << "You will receive a $" << payBackAmnt << " reward check for the $" << amntSpent << " spent on " << numBooksPurchased << " books last month." << endl;
		break;
	case '3': payBackAmnt = (5 * amntSpent) / 100;
		cout << "You will receive a $" << payBackAmnt << " reward check for the $" << amntSpent << " spent on " << numBooksPurchased << " books last month." << endl;
		break;
	case '4': payBackAmnt = (10 * amntSpent) / 100;
		cout << "You will receive a $" << payBackAmnt << " reward check for the $" << amntSpent << " spent on " << numBooksPurchased << " books last month." << endl;
		break;
	default: payBackAmnt = (15 * amntSpent) / 100;
		cout << "You will receive a $" << payBackAmnt << " reward check for the $" << amntSpent << " spent on " << numBooksPurchased << " books last month." << endl;
		break;

	}
	system("PAUSE");
	return 0;

}