/*
 * Animal.h
 *
 *  Created on: Feb 20, 2021
 *      Author: 1620308_snhu
 */

#ifndef THEZOO_ANIMAL_H_
#define THEZOO_ANIMAL_H_

#include <iostream>
using namespace std;

class Animal {
public:
	Animal();								// Default constructor
	virtual ~Animal();						// Deconstructor
	virtual void SaveData(ofstream& outFS);	// Virtual function
	virtual void PrintData();				// Virtual function
	// Omitting copy assignment operator because no pointer attribute

	string animalName;	// Following UML diagram
	int trackNum;		// Following UML diagram
};

#endif /* ANIMAL_H_ */
