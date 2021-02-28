/*
 * Oviparous.cpp
 *
 *  Created on: Feb 20, 2021
 *      Author: 1620308_snhu
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Animal.h"
#include "Oviparous.h"
using namespace std;

Oviparous::Oviparous() {	// Default constructor
	animalName = "";
	trackNum = -1;
	numEggs = -1;
}

void Oviparous::SaveData(ofstream& outFS) {
	Animal::SaveData(outFS);
	outFS << setw(17) << "Oviparous";	// Animal type

}

void Oviparous::PrintData() {
	Animal::PrintData();
	cout << setw(15) << "Oviparous" << '|';	// Animal type

}
