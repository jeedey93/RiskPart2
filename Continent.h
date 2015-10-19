#pragma once
#include <iostream>
#include "Territories.h"
using namespace std;

class Continent
{
public:
	Continent(void);
	~Continent(void);
	Continent(string,int);
	string getName();
	void setName(string);
	int getUnit();
	void setUnit(int);
	vector<Territories> Territories;
private:
	string name;
	int unit;
};

