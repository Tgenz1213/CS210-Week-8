/*
 * Mammal.cpp
 *
 *  Created on: Feb 20, 2021
 *      Author: 1620308_snhu
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Mammal.h"
using namespace std;

Mammal::Mammal() {
	animalName = "";
	trackNum = -1;
	nurse = -1;
}

void Mammal::SaveData(ofstream& outFS) {
	Animal::SaveData(outFS);
	outFS << left << setw(17) << "Mammal";	// Type
}

void Mammal::PrintData() {
	Animal::PrintData();
	cout << left << setw(15) << "Mammal" << '|';	// Type
}


