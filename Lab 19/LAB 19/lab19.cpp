#include <iostream> 
#include <fstream>
using namespace std;

ifstream inFile;
ofstream outFile;

void getInts(int& num1, int& num2, int& num3);
void displayAvg(double& avg, int num1, int num2, int num3);
int aboveAvg(double avg, int num1, int num2, int num3);

int main()
{
	int num1, num2, num3;
	double avg;

	getInts(num1, num2, num3);
	displayAvg(avg, num1, num2, num3);

	cout << "There are " << aboveAvg(avg, num1, num2, num3) << " #'s higher than the average, which is " << avg << endl;

	inFile.close();
	system("PAUSE");
	return 0;
}
void getInts(int& num1, int& num2, int& num3)
{
	inFile.open("ints.txt");
	inFile >> num1 >> num2 >> num3;
}
void displayAvg(double& avg, int num1, int num2, int num3)
{
	avg = (num1 + num2 + num3) / 3;
}
int aboveAvg(double avg, int num1, int num2, int num3)
{
	int grt = 0;

	if (num1 > avg)
		grt++;
	if (num2 > avg)
		grt++;
	if (num3 > avg)
		grt++;

	return grt++;
}
