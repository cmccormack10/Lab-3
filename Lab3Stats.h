#ifndef Lab3Stats_h
#include <iostream>

using namespace std;

class stats
{
public:
	
	// constructor
	stats();
	// deconstructor
	~stats();
	stats(float num1, float num2, float num3, float num4, float statsmean);

	// precondition: iostream, 4 numbers given by either file or inputs
	float mean(float num1, float num2, float num3, float num4);
	// postcondition: returns the mean


	// precondition: iosream, cmath, 4 numbers given by either file or inputs, mean given from the mean function
	float populationStandardDevUser(int size, float statsmean, float num1, float num2, float num3, float num4);
	// returns that calculation of the population standard deviation


private:

	float num1;
	float num2;
	float num3;
	float num4;
	float statsmean;

};
#endif Lab3Stats_h