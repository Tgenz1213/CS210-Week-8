/*
 * Bat.cpp
 *
 *  Created on: Feb 20, 2021
 *      Author: 1620308_snhu
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Bat.h"
using namespace std;

Bat::Bat() {	// Default constructor
	trackNum = -1;
	animalName = "";
	nurse = -1;
}

Bat::Bat(int trackNum, string animalName, int nurse) {	// Overload constructor
	this->trackNum = trackNum;
	this->animalName = animalName;
	this->nurse = nurse;
}

void Bat::SaveData(ofstream& outFS) {
	Mammal::SaveData(outFS);
	outFS << setw(17) << "Bat";	// Sub-type
	outFS << "0 ";				// N/A to mammals
	outFS << nurse << endl;		// Last column
}
void Bat::PrintData() {
	Mammal::PrintData();
	cout << setw(15) << "Bat" << '|';	// Sub-type
	cout << "0   |";					// N/A to mammals
	cout << nurse << endl;				// Last column
}
