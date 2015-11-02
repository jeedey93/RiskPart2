#pragma once
#include <iostream>
#include <vector>
#include "Map.h"
using namespace std;

class SaveLoadComponent
{
	public:
		static Map SaveLoadComponent::readMap(string);
		static void SaveLoadComponent::saveMap(string, Map);
};