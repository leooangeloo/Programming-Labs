#include <iostream>
using namespace std;

double incomeAmount(double& money);
double boothRentalAmount(double& booth);
void displayBalance(double money, double booth, double& balance);

int main()
{
	double money, booth, balance;

	incomeAmount(money);
	boothRentalAmount(booth);
	displayBalance(money, booth, balance);

	system("PAUSE");
	return 0;
}
double incomeAmount(double& money)
{
	cout << "How much money was collected from clients this week?" << endl;
	cin >> money;

	return money;
}
double boothRentalAmount(double& booth)
{
	cout << "How much is your booth rental this week?" << endl;
	cin >> booth;

	return booth;
}
void displayBalance(double money, double booth, double& balance)
{
	balance = money - booth;

	if (balance > 0)
		cout << "You made a profit of $" << balance << " this week." << endl;
	else if (balance < 0)
		cout << "You lose $" << balance << " this week." << endl;
	else
		cout << "You made no profit." << endl;
}