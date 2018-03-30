/*
 * DataGen.cpp
 *
 *  Created on: Mar 29, 2018
 *      Author: Amila Dias
 */

#include <iomanip>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "DataGen.h"

using namespace std;


class DataGen {

	int generateHeartRate(){
		return (rand() % 180 + 50);
	}

	int generateDiastolicBP(){
			return (rand() % 80 + 40);
	}

	int generateSystolicBP(){
			return (rand() % 100 + 80);
		}

	double generateSkinTemp(){
			return ((rand() % 100 + 95) + ((rand() % 100 + 0)/100));

		}

	double generateOxySat(){
		return ((rand() % 50 + 50) + ((rand() % 100 + 0)/100));
		}








};
