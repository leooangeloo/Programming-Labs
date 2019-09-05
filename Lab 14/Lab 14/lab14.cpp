#include <iostream>
using namespace std;

int main()
{
	char letter = ' ';

	do
	{
		int num;
		int numOfScores;
		int odd = 0, highest = 0;
		cout << "How many scores do you want to input: " << endl;
		cin >> numOfScores;

		for (int i = 1; i <= numOfScores; i++)
		{
			cout << "Enter an integer: " << endl;
			cin >> num;

			switch (num % 2)
			{
			case 1:
			case -1: odd++;
			}

			if (num > highest)
				highest = num; // automatically scans the numbers and decides which is the highest
		}

		cout << "You entered " << odd << " odd numbers." << endl;
		cout << "The highest number was: " << highest << endl;
		cout << "Enter x to exit, any key to continue: " << endl;
		cin >> letter;

	} while (letter != 'x');
	
	system("PAUSE");
	return 0;
}