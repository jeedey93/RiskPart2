#pragma once
#include <iostream>
#include <vector>
#include "Map.h"
using namespace std;

class MapEditorComponent
{
public:
	static Map createMap();
	static Map addContinentAndTerritories(Map, string, int);
	static Map EditMap(Map);
	static Map EditContinents(Map);
	static Map EditTerritories(Map);
};