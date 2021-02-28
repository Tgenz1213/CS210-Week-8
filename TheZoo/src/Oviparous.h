/*
 * Oviparous.h
 *
 *  Created on: Feb 20, 2021
 *      Author: 1620308_snhu
 */

#ifndef THEZOO_OVIPAROUS_H_
#define THEZOO_OVIPAROUS_H_

#include "Animal.h"

class Oviparous: public Animal {	// Extends Animal
public:
	Oviparous();
	virtual void SaveData(ofstream& outFS);
	virtual void PrintData();

	int numEggs;
};

#endif /* OVIPAROUS_H_ */
