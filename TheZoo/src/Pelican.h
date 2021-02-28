/*
 * Pelican.h
 *
 *  Created on: Feb 20, 2021
 *      Author: 1620308_snhu
 */

#ifndef PELICAN_H_
#define PELICAN_H_

#include "Oviparous.h"

class Pelican: public Oviparous {
public:
	Pelican();
	Pelican(int trackNum, string animalName, int numEggs);
	void SaveData(ofstream& outFS);
	void PrintData();
};

#endif /* PELICAN_H_ */
