/*
 * Goose.cpp

 *
 *  Created on: Feb 20, 2021
 *      Author: 1620308_snhu
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Goose.h"
using namespace std;

Goose::Goose() {	// Default constructor
	trackNum = -1;
	animalName = "";
	numEggs = -1;
}

Goose::Goose(int trackNum, string animalName, int numEggs) {
	// Overload constructor
	this->trackNum = trackNum;
	this->animalName = animalName;
	this->numEggs = numEggs;
}

void Goose::SaveData(ofstream& outFS) {
	Oviparous::SaveData(outFS);
	outFS << setw(17) << "Goose";	// Sub-type
	outFS << numEggs;				// Eggs column
	outFS << " 0" << endl;			// Last column
}

void Goose::PrintData() {
	Oviparous::PrintData();
	cout << setw(15) << "Goose" << '|';	// Sub-type
	cout << setw(4) << numEggs << '|';	// Eggs column
	cout << "0" << endl;				// Last column
}
