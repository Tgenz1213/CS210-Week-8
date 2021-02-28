/*
 * Crocodile.cpp
 *
 *  Created on: Feb 20, 2021
 *      Author: 1620308_snhu
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Crocodile.h"
using namespace std;

Crocodile::Crocodile() {	// Default constructor
	trackNum = -1;
	animalName = "";
	numEggs = -1;
}

Crocodile::Crocodile(int trackNum, string animalName, int numEggs) {
	// Overload constructor
	this->trackNum = trackNum;
	this->animalName = animalName;
	this->numEggs = numEggs;
}

void Crocodile::SaveData(ofstream& outFS) {
	Oviparous::SaveData(outFS);
	outFS << setw(17) << "Crocodile";	// Sub-type
	outFS << numEggs;					// Eggs column
	outFS << " 0" << endl;				// Last column
}

void Crocodile::PrintData() {
	Oviparous::PrintData();
	cout << setw(15) << "Crocodile" << '|';	// Sub-type
	cout << setw(4) << numEggs << '|';		// Eggs column
	cout << "0" << endl;					// Last column
}
