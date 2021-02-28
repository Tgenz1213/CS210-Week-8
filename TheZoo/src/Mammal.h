/*
 * Mammal.h
 *
 *  Created on: Feb 20, 2021
 *      Author: 1620308_snhu
 */

#ifndef MAMMAL_H_
#define MAMMAL_H_

#include "Animal.h"

class Mammal: public Animal {	// Extends Animal
public:
	Mammal();											// Default constructor
	virtual void SaveData(ofstream& outFS) override;	// Override animal function
	virtual void PrintData() override;					// Override animal function

	int nurse;
};

#endif /* MAMMAL_H_ */
