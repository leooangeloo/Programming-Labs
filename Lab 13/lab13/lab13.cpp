#include <iostream>
#include <fstream>
using namespace std;

ifstream inFile;
ofstream outFile;

int main()
{
	inFile.open("input.txt.");
	outFile.open("output.txt");

	char grade;
	int passing = 0, failing = 0;
	int valid = 0, erroneous = 0, total = 0;

	inFile >> grade;

	while (!inFile.eof())
	{
		total++;
		if (grade == 'a'|| grade == 'b' || grade == 'c')
		{
			passing++;
			valid++;
		}
		else if (grade == 'd'|| grade == 'f')
		{
			failing++;
			valid++;
		}
		else
		{
			erroneous++;
			outFile << "Erroneous Characters: " << grade << endl;
		}
		inFile >> grade;
	}
		outFile << "There were " << passing << " passing grades." << endl;
		outFile << "There were " << failing << " failing grades." << endl;
		outFile << "There were " << valid << " valid grades." << endl;
		outFile << "Erroneous Characters: " << erroneous << endl;
		outFile << "There were " << total << " total characters in the file." << endl;

		cout << "Check file for output." << endl;

		inFile.close();
		outFile.close();

		system("PAUSE");
		return 0;
	
}