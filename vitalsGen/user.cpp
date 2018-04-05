#include "stdafx.h"
#include "user.h"


user::user()
{
}


user::~user()
{
}

user::user(int userId, int diastolicBp, int systolicBp, int heartRate, double skinTemperature, double oxygenSaturation)
{
	this->userId = userId;
	this->diastolicBp = diastolicBp;
	this->systolicBp = systolicBp;
	this->heartRate = heartRate;
	this->skinTemperature = skinTemperature;
	this->oxygenSaturation = oxygenSaturation;
}

void user::setHeartRate(int hr)
{
	heartRate = hr;
}

void user::setUserId(int uid)
{
	userId = uid;
}

void user::setDiastolicBp(int dbp)
{
	diastolicBp = dbp;
}

void user::setSystolicBp(int sbp)
{
	systolicBp = sbp;
}

void user::setSkinTemperature(double st)
{
	skinTemperature = st;
}

void user::setOxygenSaturation(double os)
{
	oxygenSaturation = os;
}

int user::getHeartRate()
{
	return heartRate;
}

int user::getUserId()
{
	return userId;
}

int user::getDiastolicBp()
{
	return diastolicBp;
}

int user::getSystolicBp()
{
	return systolicBp;
}

double user::getSkinTemperature()
{
	return skinTemperature;
}

double user::getOxygenSaturation()
{
	return oxygenSaturation;
}
