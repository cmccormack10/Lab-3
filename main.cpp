/*
    Chris McCormack 
    C++ Fall 2023 
    Lab 3 - User and File I/O
    Write an interactive C++ program that computes and outputs the mean and
    population standard deviation of a set of four integers that are inputted by a file called
    “inMeanStd.dat” and the user
*/

#include "Lab3Stats.h" 
#include <iostream>     
#include <iomanip>      
#include <fstream>      

using namespace std;   

int main() {
    float num1, num2, num3, num4;  // Declares the 4 numbers as floats
    stats mystats;                // Creates object for stats class

    // Take user inputs and use set functions to set the values
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

    // Calculation section
    float statsmean = mystats.mean();                   // Calculate the mean of the four numbers
    float populationStandardDev = mystats.populationStandardDeviation();  // Calculate the population standard deviation

    cout << "The mean of the 4 numbers is: " << statsmean << endl;
    cout << "The population standard deviation of the 4 numbers is: " << setprecision(5) << populationStandardDev << endl;

    // Open the "inMeanStd.dat" file to prep for assigning to new variables
    ifstream inFile;
    inFile.open("inMeanStd.dat");

    // Check if the file can't be opened
    if (!inFile) {
        cout << "Error opening file";
        return 1;
    }

    // Read data from the file and overides the numbers
    inFile >> num1 >> num2 >> num3 >> num4;

    stats filestats;  // Creates new object for the file data

    // Set the values from the file to the filestats object
    filestats.setnum1(num1);
    filestats.setnum2(num2);
    filestats.setnum3(num3);
    filestats.setnum4(num4);

    // Recalculate the mean and population standard deviation from file data
    statsmean = filestats.mean();
    populationStandardDev = filestats.populationStandardDeviation();

    // Open the "outMeanstd.dat" file to prep for outputs of the calctulations
    ofstream outFile;
    outFile.open("outMeanstd.dat");

    // Check if the file couldn't be opened
    if (!outFile) {
        cout << "Error opening file" << endl;
        return 1;
    }

    // outputs calculated statistics to the "outMeanstd.dat" file
    outFile << "The mean of the file numbers is: " << filestats.mean() << endl;
    outFile << "The population standard deviation of the file numbers is: " << setprecision(5) << populationStandardDev << endl;

    // Close the I/O files
    outFile.close();
    inFile.close();

    return 0;
}