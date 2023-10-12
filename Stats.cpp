#include "Lab3Stats.h"
#include <cmath>

// Constructor for stats class
stats::stats() {
    // Initialize variables to 0
    float num1 = 0;
    float num2 = 0;
    float num3 = 0;
    float num4 = 0;
    float statsmean = 0;
}

// Parameter constructor for stats class
stats::stats(float num1_, float num2_, float num3_, float num4_, float statsmean_)
{
    // Initialize variables
    num1 = num1_;
    num2 = num2_;
    num3 = num3_;
    num4 = num4_;
    statsmean = statsmean_;
}

// Destructor for stats class
stats::~stats() {}

// Set function to set the value of num1
void stats::setnum1(float num1_)
{
    num1 = num1_;
}

// Setter function to set the value of 'num2'
void stats::setnum2(float num2_)
{
    num2 = num2_;
}

// Set function to set the value of num3
void stats::setnum3(float num3_)
{
    num3 = num3_;
}

// Set function to set the value of num4
void stats::setnum4(float num4_)
{
    num4 = num4_;
}

// Calculate and return the mean of num1, num2, num3, and num4
float stats::mean()
{
    // Calculate mean and store it in statsmean
    float statsmean = (num1 + num2 + num3 + num4) / 4.0;

    return statsmean;
}

// Calculate and return the population standard deviation of 'num1', 'num2', 'num3', and 'num4'
float stats::populationStandardDeviation()
{
    // Calculate the squared deviations sum
    float squared_deviations_sum = pow(num1 - mean(), 2) + pow(num2 - mean(), 2) + pow(num3 - mean(), 2) + pow(num4 - mean(), 2);

    // Calculate the population standard deviation and store it in populationStandardDev
    float populationStandardDev = sqrt(squared_deviations_sum / 4.0);

    return populationStandardDev;
}