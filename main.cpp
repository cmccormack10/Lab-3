#include "Lab3Stats.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	stats mystats;
	float num1, num2, num3, num4;
	
	// take the user inputs
	cout << "What is your first number: ";
	cin >> num1;

	cout << "What is your second number: ";
	cin >> num2;

	cout << "What is your third number: ";
	cin >> num3;

	cout << "What is your fourth number: ";
	cin >> num4;

	// calls functioin from stats.cpp and outputs calculations to screen of the user input
	float statsmean = mystats.mean(num1, num2, num3, num4);

	cout << "The mean of the 4 numbers is: " << statsmean << endl;


	int size = sizeof(num1, num2, num3, num4) / 4;

	float populationStandardDev = mystats.populationStandardDevUser(size, statsmean, num1, num2, num3, num4);
	
	cout << "The population standard deviation of the 4 numbers is: " << populationStandardDev;
	
	// opens meanstd file to take file input
	ifstream inFile;
	inFile.open("inMeanStd.dat");

		// error message if can't find or open file
		if (!inFile) {
			
			cout << "Error opening file";
			return 0;
		}
	

	// assigning file data to override the number identifiers
		inFile >> num1 >> num2 >> num3 >> num4;

	statsmean = mystats.mean(num1, num2, num3, num4);

	size = sizeof(num1, num2, num3, num4) / 4;

	populationStandardDev = mystats.populationStandardDevUser(size, statsmean, num1, num2, num3, num4);

	// Outputting data to outMeanstd.dat file
	ofstream outFile;
	outFile.open("outMeanstd.dat");

		// error message if can't find or open file
		if (!outFile)
		{
			cout << "Error opening file" << endl;
			return 1;
		}

	outFile << "The mean of the file numbers is: " << statsmean << endl;

	outFile << "The population standard deviation of the file numbers is: " << setprecision(5) << populationStandardDev << endl;

	// Closing Files 
	outFile.close();
	inFile.close();

	return 0;
}