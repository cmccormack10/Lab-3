#include "Lab3Stats.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	float num1, num2, num3, num4;
	stats mystats;

	// Take user inputs and use setter functions to set the values
	cout << "Enter the first number: ";
	cin >> num1;
	mystats.setnum1(num1);

	cout << "Enter the second number: ";
	cin >> num2;
	mystats.setnum2(num2);

	cout << "Enter the third number: ";
	cin >> num3;
	mystats.setnum3(num3);

	cout << "Enter the fourth number: ";
	cin >> num4;
	mystats.setnum4(num4);

	// Calculate mean and population standard deviation using member functions
	float statsmean = mystats.mean();
	float populationStandardDev = mystats.populationStandardDeviation();

	cout << "The mean of the 4 numbers is: " << statsmean << endl;
	cout << "The population standard deviation of the 4 numbers is: " << setprecision(5) << populationStandardDev << endl;
	
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

	stats filestats;

	filestats.setnum1(num1);
	filestats.setnum2(num2);
	filestats.setnum3(num3);
	filestats.setnum4(num4);

	statsmean = filestats.mean();

	int size = 4;

	populationStandardDev = filestats.populationStandardDeviation();

	// Outputting data to outMeanstd.dat file
	ofstream outFile;
	outFile.open("outMeanstd.dat");

		// error message if can't find or open file
		if (!outFile)
		{
			cout << "Error opening file" << endl;
			return 1;
		}

	outFile << "The mean of the file numbers is: " << filestats.mean() << endl;

	outFile << "The population standard deviation of the file numbers is: " << setprecision(5) << populationStandardDev << endl;

	// Closing Files 
	outFile.close();
	inFile.close();

	return 0;
}