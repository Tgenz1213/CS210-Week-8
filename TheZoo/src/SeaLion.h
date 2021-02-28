/*
 * SeaLion.h
 *
 *  Created on: Feb 20, 2021
 *      Author: 1620308_snhu
 */

#ifndef SEALION_H_
#define SEALION_H_

#include "Mammal.h"

class SeaLion: public Mammal {
public:
	SeaLion();
	SeaLion(int trackNum, string animalName, int nurse);
	void SaveData(ofstream& outFS);
	void PrintData();
};

#endif /* SEALION_H_ */
