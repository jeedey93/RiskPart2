#include<iostream>
#include<string>
#include <fstream>
#include "Continent.h"
#include "Territories.h"
#include "Map.h"
#include <sstream>
#include "MapEditorComponent.h"

using namespace std;

Map MapEditorComponent::createMap(){
	string author;
	string image;
	string wrap;
	string scroll;
	string warn;
	Map map;

	cout << "What is the author's name?" << endl;
	cin >> author;

	cout << "What is the image's extension?" << endl;
	cin >> image;

	cout << "Is the map wrap?" << endl;
	cin >> wrap;

	cout << "Is the map vertical or horizontal?" << endl;
	cin >> scroll;

	cout << "Is the map warn?" << endl;
	cin >> warn;

	map = Map(author, image, wrap=="yes"?true:false, scroll, warn=="yes"?true:false);
	return map;
}

Map MapEditorComponent::EditMap(Map map){
	string modification;

	cout << "This is the author's name:" << map.getAuthor() << endl;
	cout << "Input a new author's name or skip" << endl;
	cin >> modification;
	
	if (modification != "skip"){
		map.setAuthor(modification);
	}

	cout << "This is the image's filename:" << map.getImage() << endl;
	cout << "Input a new image's filename or skip" << endl;
	cin >> modification;

	if (modification != "skip"){
		map.setImage(modification);
	}

	cout << "This is the map's wrap:" << map.getWrap() << endl;
	cout << "Input a new map's wrap or skip" << endl;
	cin >> modification;

	if (modification != "skip"){
		map.setWrap(modification=="true"?true:false);
	}

	cout << "This is the map's scroll:" << map.getScroll() << endl;
	cout << "Input a new map's scroll or skip" << endl;
	cin >> modification;

	if (modification != "skip"){
		map.setScroll(modification);
	}

	cout << "This is the map's warn:" << map.getWarn() << endl;
	cout << "Input a new map's warn or skip" << endl;
	cin >> modification;

	if (modification != "skip"){
		map.setWarn(modification == "true" ? true : false);
	}
	return map;
}

Map MapEditorComponent::EditContinents(Map map){
	string updateContinentNumber;
	cout << "Which continents would you like to edit ? Type exit otherwise" << endl;
	for (int i = 0; i < map.Continents.size(); i++)
	{
		cout << i + 1 << "- " << map.Continents[i].getName() << endl;
	}
	cin >> updateContinentNumber;
	while (updateContinentNumber != "exit"){
		string modification;

		cout << "This is the continents's name:" << map.Continents[stoi(updateContinentNumber) - 1].getName() << endl;
		cout << "Input a new continents's name or skip" << endl;
		cin >> modification;

		if (modification != "skip"){
			map.Continents[stoi(updateContinentNumber) - 1].setName(modification);
		}

		cout << "This is the continents's maximum number of units:" << map.Continents[stoi(updateContinentNumber) - 1].getUnit() << endl;
		cout << "Input a new continents's maximum number of units or skip" << endl;
		cin >> modification;

		if (modification != "skip"){
			map.Continents[stoi(updateContinentNumber) - 1].setUnit(stoi(modification));
		}

		cout << "Which continents would you like to edit ? Type exit otherwise" << endl;
		for (int i = 0; i < map.Continents.size(); i++)
		{
			cout << i + 1 << "- " << map.Continents[i].getName() << endl;
		}
		cin >> updateContinentNumber;
	}
	return map;
}

Map MapEditorComponent::EditTerritories(Map map){
	string updateTerritoryNumber;
	
	for (int i = 0; i < map.Continents.size(); i++)
	{
		cout << "Which territory would you like to edit ? Type next or exit otherwise" << endl;
		cout << "These are the territories for " << map.Continents[i].getName() << endl;
		for (int j = 0; j < map.Continents[i].Territories.size(); j++){
			cout << j + 1 << "- " << map.Continents[i].Territories[j].getName() << endl;
		}
		cin >> updateTerritoryNumber;
		if (updateTerritoryNumber == "exit"){
			break;
		}
		while (updateTerritoryNumber != "next"){
			string modification;

			cout << "This is the territory's name:" << map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].getName() << endl;
			cout << "Input a new territory's name or skip" << endl;
			cin >> modification;

			if (modification != "skip"){
				map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].setName(modification);
			}

			cout << "This is the territory's latitude:" << map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].getLatitude() << endl;
			cout << "Input a new territory's latitude or skip" << endl;
			cin >> modification;

			if (modification != "skip"){
				map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].setLatitude(stoi(modification));
			}

			cout << "This is the territory's longitude:" << map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].getLongitude() << endl;
			cout << "Input a new territory's longitude or skip" << endl;
			cin >> modification;

			if (modification != "skip"){
				map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].setLongitude(stoi(modification));
			}

			cout << "This is the territory's continent:" << map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].getContinent() << endl;
			cout << "Input a new territory's continent or skip" << endl;
			cin >> modification;

			if (modification != "skip"){
				
				map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].setLongitude(stoi(modification));
			}

			else if (modification == "skip")
				updateTerritoryNumber = "next";
			updateTerritoryNumber = "next";
		}
	}
	return map;
}

Map MapEditorComponent::addContinentAndTerritories(Map map, string continentName, int continentUnitCount){
	string addTerritory;
	string territoryName;
	double latitude;
	double longitude;
	int territoryCount = 1;
	string adjacentTerritory;
	
	Continent continent = Continent(continentName, continentUnitCount);
	cout << "Do you want to add a territory to " << continentName << " ?" << endl;
	cin >> addTerritory;
	while (addTerritory == "yes"){
		cout << "Name your territory #" << territoryCount << endl;
		cin >> territoryName;
		cout << "Please specify the latitude of " << territoryName << endl;
		cin >> latitude;
		cout << "Please specify the longitude of " << territoryName << endl;
		cin >> longitude;
		vector<string> adjacentTerritories;
		cout << "Please enter an adjacent territory or stop" << endl;
		cin >> adjacentTerritory;
		while (adjacentTerritory != "stop"){
			adjacentTerritories.push_back(adjacentTerritory);
			cout << "Please enter an adjacent territory or stop" << endl;
			cin >> adjacentTerritory;
		}
		Territories territory = Territories(territoryName, latitude, longitude, continentName, adjacentTerritories);
		continent.Territories.push_back(territory);
		territoryCount++;
		cout << "Do you want to add a territory to " << continentName << " ?" << endl;
		cin >> addTerritory;
	}
	map.Continents.push_back(continent);
	return map;
}

