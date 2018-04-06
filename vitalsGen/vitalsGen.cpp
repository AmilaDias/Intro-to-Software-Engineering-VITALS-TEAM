// vitalsGen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "dataGen.h""
#include "user.h"
#include <string>
#include <iostream>
#include "time.h"
#include <stdio.h>
#include <fstream>

using namespace std;
int id = 1;

//Initialize array
string irregular[5][2] = {
	{ "Diastolic Blood Pressure" , "0"},
	{ "Systolic Blood Pressure" , "0" },
	{ "Heart Rate" , "0" },
	{ "Temperature" , "0" },
	{ "Oxygen Saturation" , "0" },
};

//Randomly generates User Vitals
void getVitals(user &user1) {
	dataGen *dataGenerator = new dataGen();
	int dp = 0;
	int sp = 0;
	int hr = 0;
	double temp = 0.0;
	double oxy = 0.0;

	dp = dataGenerator->generateDiastolicBP();
	sp = dataGenerator->generateSystolicBP();
	hr = dataGenerator->generateHeartRate();
	temp = dataGenerator->generateSkinTemp();
	oxy = dataGenerator->generateOxySat();

	user1.setUserId(id);
	user1.setDiastolicBp(dp);
	user1.setSystolicBp(sp);
	user1.setHeartRate(hr);
	user1.setSkinTemperature(temp);
	user1.setOxygenSaturation(oxy);
	//increase id for next user
	id++;
}

//Allows user to enter in vital values manually
void getUserInput(user &user1) {
	int dp = 0;
	int sp = 0;
	int hr = 0;
	double temp = 0.0;
	double oxy = 0.0;

	cout << "Set User's Diastolic blood pressure:  ";
	cin >> dp;
	cout << "Set User's Systolic blood pressure:  ";
	cin >> sp;
	cout << "Set User's Heart Rate:  ";
	cin >> hr;
	cout << "Set User's Skin Temperature:  ";
	cin >> temp;
	cout << "Set User's Oxygen Saturation:  ";
	cin >> oxy;


	user1.setUserId(id);
	user1.setDiastolicBp(dp);
	user1.setSystolicBp(sp);
	user1.setHeartRate(hr);
	user1.setSkinTemperature(temp);
	user1.setOxygenSaturation(oxy);
}

bool isNormalBp(int dbp, int sbp) {
	//diastolic and sytolic cases
	if (60 <= dbp && dbp <= 80 && 90 <= sbp && sbp <= 120) {
		irregular[0][1] = "Normal";
		irregular[1][1] = "Normal";
		return false;
	}
	else if (60 <= dbp && dbp <= 80 && 120 < sbp && sbp < 140) {
		irregular[0][1] = "Normal";
		irregular[1][1] = "Pre-High blood pressure";
		return true;
	}
	else if (60 <= dbp && dbp <= 80 && 140 < sbp) {
		irregular[0][1] = "Normal";
		irregular[1][1] = "High blood pressure";
		return true;
	}
	else if (60 <= dbp && dbp <= 80 && 70 < sbp && sbp < 90) {
		irregular[0][1] = "Normal";
		irregular[1][1] = "Low blood pressure";
		return true;
	}
	else if (80 < dbp && dbp < 90 && 90 <= sbp && sbp <= 120) {
		irregular[0][1] = "Pre-High blood pressure";
		irregular[1][1] = "Normal";
		return true;
	}
	else if (90 < dbp  && 90 <= sbp && sbp <= 120) {
		irregular[0][1] = "High blood pressure";
		irregular[1][1] = "Normal";
		return true;
	}
	else if (40 < dbp && dbp < 60 && 90 <= sbp && sbp <= 120) {
		irregular[0][1] = "Low blood pressure";
		irregular[1][1] = "Normal";
		return true;
	}
	else if (80 < dbp && dbp < 90 && 120 < sbp && sbp < 140) {
		for (int i = 0; i < 5; i++) {
			if (i == 0) {
				irregular[i][1] = "Pre-High blood pressure";
			}
			if (i == 1) {
				irregular[i][1] = "Pre-High blood pressure";
				break;
			}
		}
		return true;
	}
	else if (90 < dbp  && 140 < sbp ) {
		for (int i = 0; i < 5; i++) {
			if (i == 0) {
				irregular[i][1] = "High blood pressure";
			}
			if (i == 1) {
				irregular[i][1] = "High blood pressure";
				break;
			}
		}
		return true;
	}
	else if ( dbp < 60 && sbp < 90) {
		for (int i = 0; i < 5; i++) {
			if (i == 0) {
				irregular[i][1] = "Low blood pressure";
			}
			if (i == 1) {
				irregular[i][1] = "Low blood pressure";
				break;
			}
		}
		return true;
	}
	else {
		cout << "Invalid readings" << endl;
		irregular[0][1] = "Invalid Reading";
		irregular[1][1] = "Invalid Reading";
	}
	return true;
}

bool isNormalHeartRate(int hr) {
	if (60 <= hr && hr <= 100) {
		irregular[2][1] = "Normal";
		return false;
	}
	else if (hr > 100) {
		irregular[2][1] = "High";
		return true;
	}
	else if (hr < 60) {
		irregular[2][1] = "Low";
		return true;
	}
}

bool isNormalTemp(double temp) {
	if (98 <= temp && temp <= 99) {
		irregular[3][1] = "Normal";
		return false;
	}
	else if (temp > 99) {
		irregular[3][1] = "High";
		return true;
	}
	else if (temp < 98) {
		irregular[3][1] = "Low";
		return true;
	}
}

bool isNormalOxygenLevel(double oxy) {
	if (0.95 <= oxy && oxy <= 1.00) {
		irregular[4][1] = "Normal";
		return false;
	}
	else if (oxy > 1.00) {
		irregular[4][1] = "High";
		return true;
	}
	else if (oxy < .95) {
		irregular[4][1] = "Low";
		return true;
	}
}

int main()
{
	//initialize random seed
	srand(time(NULL));
	
	//Initialize User Object
	user user1 = user();

	/* **IN PLACE FOR TESTING PURPOSES**
	//Randomly generate User Vitals
	getVitals(user1);
	*/
	
	//Get user input for vital signals
	getUserInput(user1);

	//Analyze vital signals
	isNormalBp(user1.getDiastolicBp(), user1.getSystolicBp());
	isNormalHeartRate(user1.getHeartRate());
	isNormalTemp(user1.getSkinTemperature());
	isNormalOxygenLevel(user1.getOxygenSaturation());

	//Output user vitals to console **FOR TESTING**
	printf("Diastolic Blood Pressure: %d\n", user1.getDiastolicBp());
	printf("Systolic Blood Pressure: %d\n", user1.getSystolicBp());
	printf("Heart Rate: %d\n", user1.getHeartRate());
	printf("Temperature: %.2f\n", user1.getSkinTemperature());
	printf("Oxygen Saturation: %.2f\n", user1.getOxygenSaturation());
	printf("\n");

	//Output vitals analysis to console **FOR TESTING**
	for (int i = 0; i < 5; i++) {
		cout << irregular[i][0] << ": " << irregular[i][1] << endl;
	}
	
	//File Output
	FILE * outputFile;
	int n;
	char name[100];

	outputFile = fopen("vitalsOutput.txt", "w");

	if (isNormalBp(user1.getDiastolicBp(), user1.getSystolicBp())) {
		fprintf(outputFile, "Diastolic Blood Pressure: %s \n", irregular[0][1].c_str());
		fprintf(outputFile, "Systolic Blood Pressure: %s \n", irregular[1][1].c_str());
	}
	if (isNormalHeartRate(user1.getHeartRate())) {
		fprintf(outputFile, "Heart Rate: %s \n", irregular[2][1].c_str());
	}
	if (isNormalTemp(user1.getSkinTemperature())) {
		fprintf(outputFile, "Skin Temperature: %s \n", irregular[3][1].c_str());
	}
	if (isNormalOxygenLevel(user1.getOxygenSaturation())) {
		fprintf(outputFile, "Skin Temperature: %s \n", irregular[4][1].c_str());
	}

	fclose(outputFile);


	system("pause");
    return 0;
}

