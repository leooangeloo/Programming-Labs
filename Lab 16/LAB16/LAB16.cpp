#include <iostream>
using namespace std;

bool isVowel(char letter);

int main()
{
	char letter;

	for (int i = 0; i<3; i++)
	{
		cout << "Enter 3 characters, one at a time: " << endl;
		cin >> letter;
		isVowel(letter);

		if (isVowel(letter))
		{
			cout << letter << " is a vowel." << endl;
		}
		else
			cout << letter << " is NOT a vowel." << endl;
	}

	system("PAUSE");
	return 0;
}
bool isVowel(char vowel)
{
	switch (vowel)
	{
	case 'a' :
		break;
	case 'e' : 
		break;
	case 'i' : 
		break;
	case 'o' :
		break;
	case 'u' : 
		break;
	case 'A' : 
		break;
	case 'E' :
		break;
	case 'I' : 
		break;
	case 'O' :
		break;
	case 'U': 
		return true;
		break;
	default: return false;
		break;

	}
}