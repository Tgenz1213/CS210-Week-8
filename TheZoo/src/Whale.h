/*
 * Whale.h
 *
 *  Created on: Feb 20, 2021
 *      Author: 1620308_snhu
 */

#ifndef WHALE_H_
#define WHALE_H_

#include "Mammal.h"

class Whale: public Mammal {
public:
	Whale();
	Whale(int trackNum, string animalName, int nurse);
	void SaveData(ofstream& outFS);
	void PrintData();
};

#endif /* WHALE_H_ */
