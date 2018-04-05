#pragma once
class dataGen
{
public:
	dataGen();
	~dataGen();

	int generateHeartRate();
	int generateDiastolicBP();
	int generateSystolicBP();
	double generateSkinTemp();
	double generateOxySat();
};

