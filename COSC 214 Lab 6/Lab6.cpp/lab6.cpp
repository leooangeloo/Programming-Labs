#include<iostream>
#include<string>
using namespace std;

int numVows(string name, int upper, int lower, int& counter);
bool vowelcheck(char letter);

int main() {
	string name = "DarylStone";
	int counter = 0;

	cout << "There are " << numVows(name, 9, 0, counter) << " vowels in the string. " << endl;
	system("PAUSE");
	return 0;
}
int numVows(string name, int upper, int lower, int& counter) {

	if (lower == upper) {
		if (vowelcheck(name[lower]) == true)
			counter++;
	}
	else {
		numVows(name, upper, lower + 1, counter);
		if (vowelcheck(name[lower]) == true)
			counter++;
	}
	return counter;
}
bool vowelcheck(char letter) {
	bool found = false;

	switch (letter) {
		case 'A' :
		case 'a' :
		case 'E' :
		case 'e' :
		case 'I' :
		case 'i' :
		case 'O' :
		case 'o' :
		case 'U' :
		case 'u' : found = true;
		break;

	}return found;
}