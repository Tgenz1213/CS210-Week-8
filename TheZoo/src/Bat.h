/*
 * Bat.h
 *
 *  Created on: Feb 20, 2021
 *      Author: 1620308_snhu
 */

#ifndef BAT_H_
#define BAT_H_
#include "Mammal.h"

class Bat: public Mammal {
public:
	Bat();
	Bat(int trackNum, string animalName, int nurse);
	virtual void SaveData(ofstream& outFS) override;
	virtual void PrintData() override;
};

#endif /* BAT_H_ */
