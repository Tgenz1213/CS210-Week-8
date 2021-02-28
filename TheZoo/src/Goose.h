/*
 * Goose.h
 *
 *  Created on: Feb 20, 2021
 *      Author: 1620308_snhu
 */

#ifndef GOOSE_H_
#define GOOSE_H_

#include "Oviparous.h"

class Goose: public Oviparous {
public:
	Goose();
	Goose(int trackNum, string animalName, int numEggs);
	void SaveData(ofstream& outFS);
	void PrintData();
};

#endif /* GOOSE_H_ */
