#include "Lab3Stats.h"
#include <cmath>

stats::stats() 
{
	num1 = 0;
	num2 = 0;
	num3 = 0;
	num4 = 0;
	statsmean = 0;
}

stats::~stats() {}

stats::stats(float num1, float num2, float num3, float num4, float statsmean)
{
	this -> num1 = num1;
	this -> num2 = num2;
	this -> num3 = num3;
	this -> num4 = num4;
	this-> statsmean = statsmean;
}

float stats::mean(float num1, float num2, float num3, float num4)
{
	float statsmean = (num1 + num2 + num3 + num4)/4.0;

	return statsmean;
}

float stats::populationStandardDevUser(int size, float statsmean, float num1, float num2, float num3, float num4)
{
	float squared_deviations_sum = pow(num1 - statsmean, 2) + pow(num2 - statsmean, 2) + pow(num3 - statsmean, 2) + pow(num4 - statsmean, 2);

	float populationStandardDev = sqrt(squared_deviations_sum/4.0);
	return populationStandardDev;

}