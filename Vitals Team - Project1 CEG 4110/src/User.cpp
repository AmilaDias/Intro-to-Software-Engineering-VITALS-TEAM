/*
 * User.cpp
 *
 *  Created on: Mar 29, 2018
 *      Author: Amila Dias
 */

#include <iomanip>
#include <iostream>
#include "User.h"




	/*Setters*/
	void setHeartRate(int hr) {
		:heartRate = hr;
	}

	void setUserId(int uid) {
		:userId = uid;
	}

	void setDiastolicBp(int dbp) {
		:diastolicBp = dbp;
	}

	void setSystolicBp(int sbp) {
		:systolicBp = sbp;
	}

	void setPollingRate(int pr) {
		:pollingRate = pr;
	}

	void setSkinTemperature(double st) {
		:skinTemperature = st;
	}

	void setOxygenSaturation(double os) {
		:oxygenSaturation = os;
	}


	/*Getters*/
	int getHeartRate() {
		return :heartRate;
	}

	int getUserId() {
		return :userId;
	}

	int getDiastolicBp() {
		return :diastolicBp;
	}

	int getSystolicBp() {
		return :systolicBp;
	}

	int getPollingRate() {
		return :pollingRate;
	}

	double getSkinTemperature() {
		return :skinTemperature;
	}

	double getOxygenSaturation() {
		return :oxygenSaturation;
	}
};




