/*
 * Crocodile.h
 *
 *  Created on: Feb 20, 2021
 *      Author: 1620308_snhu
 */

#ifndef CROCODILE_H_
#define CROCODILE_H_

#include "Oviparous.h"

class Crocodile: public Oviparous {
public:
	Crocodile();
	Crocodile(int trackNum, string animalName, int numEggs);
	void SaveData(ofstream& outFS);
	void PrintData();
};

#endif /* CROCODILE_H_ */
