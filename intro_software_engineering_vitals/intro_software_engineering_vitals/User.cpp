#include <iomanip>
#include <iostream>

class user {
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

	/*Setters*/
	void setHeartRate(int hr) {
		heartRate = hr;
	}

	void setUserId(int uid) {
		userId = uid;
	}

	void setDiastolicBp(int dbp) {
		diastolicBp = dbp;
	}

	void setSystolicBp(int sbp) {
		systolicBp = sbp;
	}

	void setPollingRate(int pr) {
		pollingRate = pr;
	}

	void setSkinTemperature(double st) {
		skinTemperature = st;
	}

	void setOxygenSaturation(double os) {
		oxygenSaturation = os;
	}


	/*Getters*/
	int getHeartRate() {
		return heartRate;
	}

	int getUserId() {
		return userId;
	}

	int getDiastolicBp() {
		return diastolicBp;
	}

	int getSystolicBp() {
		return systolicBp;
	}

	int getPollingRate() {
		return pollingRate;
	}

	double getSkinTemperature() {
		return skinTemperature;
	}

	double getOxygenSaturation() {
		return oxygenSaturation;
	}
};

