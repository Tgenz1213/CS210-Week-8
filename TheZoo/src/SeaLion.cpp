/*
 * SeaLion.cpp
 *
 *  Created on: Feb 20, 2021
 *      Author: 1620308_snhu
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "SeaLion.h"
using namespace std;

SeaLion::SeaLion() {	// Default constructor
	trackNum = -1;
	animalName = "";
	nurse = -1;
}

SeaLion::SeaLion(int trackNum, string animalName, int nurse) {	// Overload constructor
	this->trackNum = trackNum;
	this->animalName = animalName;
	this->nurse = nurse;
}

void SeaLion::SaveData(ofstream& outFS) {
	Mammal::SaveData(outFS);
	outFS << setw(17) << "SeaLion";	// Sub-type
	outFS << "0 ";					// N/A to mammals
	outFS << nurse << endl;			// Last column
}

void SeaLion::PrintData() {
	Mammal::PrintData();
	cout << setw(15) << "SeaLion" << '|';	// Sub-type
	cout << "0   |";						// N/A to mammals
	cout << nurse << endl;					// Last column
}
