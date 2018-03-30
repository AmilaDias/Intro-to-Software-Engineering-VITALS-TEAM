/*
 * User.h
 *
 *  Created on: Mar 29, 2018
 *      Author: amila
 */

#ifndef USER_H_
#define USER_H_

class User {
private:
	 int heartRate;
	 int userId;
	 int diastolicBp;
	 int systolicBp;
	 int pollingRate;
	 double skinTemperature;
	 double oxygenSaturation;
	 bool warning = false;

public:
	user();

	~user();

	user(int userId, int diastolicBp, int systolicBp, int pollingRate, double skinTemperature, double oxygenSaturation) {
		this->userId = userId;
		this->diastolicBp = diastolicBp;
		this->systolicBp = systolicBp;
		this->pollingRate = pollingRate;
		this->skinTemperature = skinTemperature;
		this->oxygenSaturation = oxygenSaturation;
	}

};



#endif /* USER_H_ */
