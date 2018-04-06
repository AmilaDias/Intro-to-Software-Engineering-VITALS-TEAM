#include "stdafx.h"
#include "dataGen.h"
#include <stdlib.h>


dataGen::dataGen()
{
}


dataGen::~dataGen()
{
}

//normal range is 60-100
int dataGen::generateHeartRate()
{
	return (rand() % (130 - 50 + 1)) + 50;
}

//normal range is 60-80
int dataGen::generateDiastolicBP()
{
	return (rand() % (100 - 40 + 1)) + 40;
}

//normal range is 90-120
int dataGen::generateSystolicBP()
{
	return (rand() % (150 - 70 + 1)) + 70;
}

//normal range is 98-99
double dataGen::generateSkinTemp()
{
	double i = ((double)(rand() % 100)) / 100;
	int j = (rand() % (100-95) + 95);
	double x = i + j;
	return x;
}

//normal range is 95-100%, using decimal to represent percentage (ex: .95)
double dataGen::generateOxySat()
{
	return ((((rand() % 105) + 90) + ((rand() % 105) + 90)) / 200);
}
