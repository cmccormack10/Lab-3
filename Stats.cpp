#include "Lab3Stats.h"
#include <cmath>

stats::stats() {
	float num1 = 0;
	float num2 = 0;
	float num3 = 0;
	float num4 = 0;
	float statsmean = 0;
}

stats::stats(float num1_, float num2_, float num3_, float num4_, float statsmean_) 
{
	num1 = num1_;
	num2 = num2_;
	num3 = num3_;
	num4 = num4_;
	statsmean = statsmean_;
}

stats::~stats() {}

void stats::setnum1(float num1_)
{
	num1 = num1_;
}

void stats::setnum2(float num2_)
{
	num2 = num2_;
}

void stats::setnum3(float num3_)
{
	num3 = num3_;
}

void stats::setnum4(float num4_)
{
	num4 = num4_;
}


float stats::mean()
{
	float statsmean = (num1 + num2 + num3 + num4)/4.0;

	return statsmean;
}

float stats::populationStandardDeviation()
{
	float squared_deviations_sum = pow(num1 - mean(), 2) + pow(num2 - mean(), 2) + pow(num3 - mean(), 2) + pow(num4 - mean(), 2);
	float populationStandardDev = sqrt(squared_deviations_sum/4.0);
	return populationStandardDev;

}