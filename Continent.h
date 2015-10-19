#pragma once
#include <iostream>
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
private:
	string name;
	int unit;
};

