#pragma once
class user
{
private:
	int heartRate;
	int userId;
	int diastolicBp;
	int systolicBp;
	double skinTemperature;
	double oxygenSaturation;
	bool warning = false;

public:
	user();
	~user();
	user(int userId, int diastolicBp, int systolicBp, int heartRate, double skinTemperature, double oxygenSaturation);

	void setHeartRate(int hr);
	void setUserId(int uid);
	void setDiastolicBp(int dbp);
	void setSystolicBp(int sbp);
	void setSkinTemperature(double st);
	void setOxygenSaturation(double os);

	int getHeartRate();
	int getUserId();
	int getDiastolicBp();
	int getSystolicBp();
	double getSkinTemperature();
	double getOxygenSaturation();
};

