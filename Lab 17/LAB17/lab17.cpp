#include <iostream>
#include <string>
using namespace std;

void getGrades(int& grade1, int& grade2, string type);
double computeAverage(int s1, int s2);

int main()
{
	int test1, test2, project1, project2;
	string gradeType;

	cout << "Enter the type of grade your entering: (test or project)" << endl;
	cin >> gradeType;
	getGrades(test1, test2, gradeType);
	getGrades(project1, project2, "project");

	cout << "The test average is: " << computeAverage(test1, test2) << endl;
	cout << "The project average is: " << computeAverage(project1, project2) << endl;

	system("PAUSE");
	return 0;
}
void getGrades(int& grade1, int& grade2, string type)
{
	cout << "Enter two " << type << " scores: " << endl;
	cin >> grade1 >> grade2;
}
double computeAverage(int s1, int s2)
{
	double avg;
	avg = (s1 + s2) / 2;
	
	return avg;
}
