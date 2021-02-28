/*
 * Whale.cpp
 *
 *  Created on: Feb 20, 2021
 *      Author: 1620308_snhu
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Whale.h"
using namespace std;

Whale::Whale() {
	trackNum = -1;
	animalName = "";
	nurse = -1;
}

Whale::Whale(int trackNum, string animalName, int nurse) {
	this->trackNum = trackNum;
	this->animalName = animalName;
	this->nurse = nurse;
}

void Whale::SaveData(ofstream& outFS) {
	Mammal::SaveData(outFS);
	outFS << setw(17) << "Whale";	// Sub-type
	outFS << "0 ";					// N/A to mammals
	outFS << nurse << endl;			// Last column
}

void Whale::PrintData() {
	Mammal::PrintData();
	cout << setw(15) << "Whale" << '|';	// Sub-type
	cout << "0   |";					// N/A to mammals
	cout << nurse << endl;				// Last column
}
