#pragma once
#include "Obj.h"
#include <string.h>
#include <cstdlib>
#include <iostream>

class AncienneDonnees :
	public Obj

#include "Obj.h"
{
public:
	AncienneDonnees();
	~AncienneDonnees();

	AncienneDonnees(int i, std::string str);

	std::string getdonnee();

	void setdonnee(std::string str);

	int getpositionX();

	int getpositionY();

	std::string donnee;
	int positionX;
	int positionY;
};
