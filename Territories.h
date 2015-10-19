#pragma once
#include <iostream>
#include <vector>

using namespace std;
class Territories
{
public:
	Territories(void);
	~Territories(void);
	Territories::Territories(string, double, double, string, vector<string>);
	string getName();
	void setName(string);
	double getLatitude();
	void setLatitude(double);
	double getLongitude();
	void setLongitude(double);
	string getContinent();
	void setContinent(string);
	vector<string> adjacentTerritories;
private:
	string name;
	double latitude;
	double longitude;
	string continent;
};

