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
string irregular[5][2];
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

int isNormalBp(int dbp, int sbp) {
	//diastolic and sytolic cases
	if (60 <= dbp >= 80 && 90 <= sbp >= 120) {
		irregular[0][1] = "Normal";
		irregular[1][1] = "Normal";
		return 1;
	}
	else if (60 <= dbp >= 80 && 120 < sbp > 140) {
		irregular[1][1] = "Pre-High blood pressure";
		return 0;
	}
	else if (60 <= dbp >= 80 && 140 < sbp >= 160) {
		irregular[1][1] = "High blood pressure";
		return 0;
	}
	else if (60 <= dbp >= 80 && 70 < sbp > 90) {
		irregular[1][1] = "Low blood pressure";
		return 0;
	}
	else if (80 < dbp > 90 && 90 <= sbp >= 120) {
		irregular[0][1] = "Pre-High blood pressure";
		return 0;
	}
	else if (90 < dbp >= 100 && 90 <= sbp >= 120) {
		irregular[0][1] = "High blood pressure";
		return 0;
	}
	else if (40 < dbp > 60 && 90 <= sbp >= 120) {
		irregular[0][1] = "Low blood pressure";
		return 0;
	}
	else if (80 < dbp > 90 && 120 < sbp > 140) {
		for (int i = 0; i < 5; i++) {
			if (i == 0) {
				irregular[i][1] = "Pre-High blood pressure";
			}
			if (i == 1) {
				irregular[i][1] = "Pre-High blood pressure";
				break;
			}
		}
		return 0;
	}
	else if (90 < dbp >= 100 && 140 < sbp >= 160) {
		for (int i = 0; i < 5; i++) {
			if (i == 0) {
				irregular[i][1] = "High blood pressure";
			}
			if (i == 1) {
				irregular[i][1] = "High blood pressure";
				break;
			}
		}
		return 0;
	}
	else if (40 < dbp > 60 && 70 < sbp > 90) {
		for (int i = 0; i < 5; i++) {
			if (i == 0) {
				irregular[i][1] = "Low blood pressure";
			}
			if (i == 1) {
				irregular[i][1] = "Low blood pressure";
				break;
			}
		}
		return 0;
	}
	else {
		cout << "Invalid readings" << endl;
		irregular[0][1] = "Invalid Reading";
		irregular[1][1] = "Invalid Reading";
	}

	return 0;
}

int isNormalHeartRate(int hr) {
	if (60 <= hr >= 100) {
		irregular[3][1] = "Normal";
		return 1;
	}
	else if (hr > 100) {
		irregular[3][1] = "High";
		return 0;
	}
	else if (hr < 60) {
		irregular[3][1] = "Low";
		return 0;
	}
}

int isNormalTemp(double temp) {
	if (98 <= temp >= 99) {
		irregular[4][1] = "Normal";
		return 1;
	}
	else if (temp > 99) {
		irregular[4][1] = "High";
		return 0;
	}
	else if (temp < 98) {
		irregular[4][1] = "Low";
		return 0;
	}
}

int isNormalOxygenLevel(double oxy) {
	if (0.95 <= oxy >= 1.00) {
		irregular[5][1] = "Normal";
		return 1;
	}
	else if (oxy > 1.00) {
		irregular[5][1] = "High";
		return 0;
	}
	else if (oxy < .95) {
		irregular[5][1] = "Low";
		return 0;
	}
}

int main()
{
	//initialize random seed
	srand(time(NULL));
	
	user user1 = user();
	getVitals(user1);

	isNormalBp(user1.getDiastolicBp(), user1.getSystolicBp());
	isNormalHeartRate(user1.getHeartRate());
	isNormalTemp(user1.getSkinTemperature());
	isNormalOxygenLevel(user1.getOxygenSaturation());

	printf("Diastolic Blood Pressure: %d\n", user1.getDiastolicBp());
	printf("Systolic Blood Pressure: %d\n", user1.getSystolicBp());
	printf("Heart Rate: %d\n", user1.getHeartRate());
	printf("Temperature: %.2f\n", user1.getSkinTemperature());
	printf("Oxygen Level: %.2f\n", user1.getOxygenSaturation());
	printf("\n");
	
	for (int i = 0; i < 5; i++) {
		cout << irregular[i] << ": " << irregular[i][1] << endl;
	}
	
	system("pause");
    return 0;
}

