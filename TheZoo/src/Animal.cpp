/*
 * Animal.cpp
 *
 *  Created on: Feb 20, 2021
 *      Author: 1620308_snhu
 */
#include <iostream>
#include <iomanip>	// Format output
#include <fstream>	// Write to file
#include "Animal.h"
using namespace std;

Animal::Animal() {	// Default constructor
	animalName = "";
	trackNum = 0;
}

Animal::~Animal() {}	// Default deconstructor

void Animal::SaveData(ofstream& outFS) {
	outFS << right << setfill('0') << setw(7) << trackNum << " ";	// Track#
	outFS << left << setfill(' ') << setw(17) << animalName;		// Name
}

void Animal::PrintData() {
	cout <<  right << setfill('0') << setw(6) << trackNum << '|';	// Track#
	cout << left << setfill(' ') << setw(15) << animalName << '|';	// Name
}
