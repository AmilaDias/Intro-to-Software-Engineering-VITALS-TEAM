// vitalsGen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "dataGen.h""
#include "user.h"
#include <string>
#include <iostream>
#include "time.h"

using namespace std;
int id = 1;
string irregular[5][1] = {"Diastolic", "Systolic", "Heart Rate", "Temperature", "Oxygen Level"};

int main()
{
	//initialize random seed
	srand(time(NULL));
	
	user user1 = getVitals();
	isNormalBp(user1.getDiastolicBp, user1.getSystolicBp);
	isNormalHeartRate(user1.getHeartRate);
	isNormalTemp(user1.getSkinTemperature);
	isNormalOxygenLevel(user1.getOxygenSaturation);

	cout << "Diastolic Blood Pressure: " + user1.getDiastolicBp << endl;
	cout << "Systolic Blood Pressure: " + user1.getSystolicBp << endl;
	cout << "Heart Rate: " + user1.getHeartRate << endl;
	cout << "Temperature: " + user1.getSkinTemperature << endl;
	cout << "Oxygen Level: " + user1.getOxygenSaturation << endl;
	printf("\n");

	for (int i = 0; i < 5; i++) {
		cout << irregular[i][0] << endl;
	}

	system("pause");
    return 0;
}

user getVitals() {
	dataGen dataGenerator;
	int dp = 0;
	int sp = 0;
	int hr = 0;
	double temp = 0.0;
	double oxy = 0.0;

	dp = dataGenerator.generateDiastolicBP;
	sp = dataGenerator.generateSystolicBP;
	hr = dataGenerator.generateHeartRate;
	temp = dataGenerator.generateSkinTemp;
	oxy = dataGenerator.generateOxySat;

	user user(id, dp, sp, hr, temp, oxy);
	//increase id for next user
	id++;
	return user;
}

int isNormalBp(int dbp, int sbp) {
	//diastolic and sytolic cases
	if (60 <= dbp <= 80 && 90 <= sbp <= 120) {
		return 1;
	}
	else if (60 <= dbp <= 80 && 120 < sbp < 140) {
		irregular[1][0] = "Pre-High blood pressure";
		return 0;
	}
	else if (60 <= dbp <= 80 && 140 < sbp <= 160) {
		irregular[1][0] = "High blood pressure";
		return 0;
	}
	else if (60 <= dbp <= 80 && 70 < sbp < 90) {
		irregular[1][0] = "Low blood pressure";
		return 0;
	}
	else if (80 < dbp < 90 && 90 <= sbp <= 120) {
		irregular[0][0] = "Pre-High blood pressure";
		return 0;
	}
	else if (90 < dbp <= 100 && 90 <= sbp <= 120) {
		irregular[0][0] = "High blood pressure";
		return 0;
	}
	else if (40 < dbp < 60 && 90 <= sbp <= 120) {
		irregular[0][0] = "Low blood pressure";
		return 0;
	}
	else if (80 < dbp < 90 && 120 < sbp < 140) {
		for (int i = 0; i < 5; i++) {
			if (i == 0) {
				irregular[i][0] = "Pre-High blood pressure";
			}
			if (i == 1) {
				irregular[i][0] = "Pre-High blood pressure";
				break;
			}
		}
		return 0;
	}
	else if (90 < dbp <= 100 && 140 < sbp <= 160) {
		for (int i = 0; i < 5; i++) {
			if (i == 0) {
				irregular[i][0] = "High blood pressure";
			}
			if (i == 1) {
				irregular[i][0] = "High blood pressure";
				break;
			}
		}
		return 0;
	}
	else if (40 < dbp < 60 && 70 < sbp < 90) {
		for (int i = 0; i < 5; i++) {
			if (i == 0) {
				irregular[i][0] = "Low blood pressure";
			}
			if (i == 1) {
				irregular[i][0] = "Low blood pressure";
				break;
			}
		}
		return 0;
	}
	else {
		cout << "Invalid readings" << endl;
	}

	return 0;
}

int isNormalHeartRate(int hr) {
	if (60 <= hr <= 100) {
		return 1;
	}
	else if (hr > 100) {
		irregular[3][0] = "High";
		return 0;
	}
	else if (hr < 60) {
		irregular[3][0] = "Low";
		return 0;
	}
}

int isNormalTemp(double temp) {
	if (98 <= temp <= 99) {
		return 1;
	}
	else if (temp > 99) {
		irregular[4][0] = "High";
		return 0;
	}
	else if (temp < 98) {
		irregular[4][0] = "Low";
		return 0;
	}
}

int isNormalOxygenLevel(double oxy) {
	if (0.95 <= oxy <= 1.00) {
		return 1;
	}
	else if (oxy > 1.00) {
		irregular[5][0] = "High";
		return 0;
	}
	else if (oxy < .95) {
		irregular[5][0] = "Low";
		return 0;
	}
}