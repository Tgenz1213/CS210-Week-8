/*
 * Pelican.cpp
 *
 *  Created on: Feb 20, 2021
 *      Author: 1620308_snhu
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Pelican.h"
using namespace std;

Pelican::Pelican() {	// Default constructor
	trackNum = -1;
	animalName = "";
	numEggs = -1;
}

Pelican::Pelican(int trackNum, string animalName, int numEggs) {
	// Overload constructor
	this->trackNum = trackNum;
	this->animalName = animalName;
	this->numEggs = numEggs;
}

void Pelican::SaveData(ofstream& outFS) {
	Oviparous::SaveData(outFS);
	outFS << setw(17) << "Pelican";	// Sub-type
	outFS << numEggs;				// Eggs column
	outFS << " 0" << endl;			// Last column
}

void Pelican::PrintData() {
	Oviparous::PrintData();
	cout << setw(15) << "Pelican" << '|';	// Sub-type
	cout << setw(4) << numEggs << '|';		// Eggs column
	cout << "0" << endl;					// Last column
}
