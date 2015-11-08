#include<iostream>
#include<string>
#include <fstream>
#include "Continent.h"
#include "Territories.h"
#include "Map.h"
#include <sstream>
#include "MapEditorComponent.h"

using namespace std;

Map MapEditorComponent::CreateMap(){
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

	cout << "Is the map wrap?[Y/N]" << endl;
	cin >> wrap;

	cout << "Is the map vertical or horizontal?[Y/H]" << endl;
	cin >> scroll;

	cout << "Is the map warn?[Y/N]" << endl;
	cin >> warn;

	map = Map(author, image, wrap=="Y"?true:false, scroll, warn=="Y"?true:false);
	return map;
}

Map MapEditorComponent::EditMap(Map map){
	string modification="";
	while (modification != "0"){
		cout << "What would you like to edit ?[1,2,3,4,5] 0 to exit" << endl;
		cout << "1 - Author's Name " << endl;
		cout << "2 - Image's Filename " << endl;
		cout << "3 - Map's Wrap " << endl;
		cout << "4 - Map's Scroll " << endl;
		cout << "5 - Map's Warn " << endl;
		cout << "0 - Exit" << endl;
		cin >> modification;

		if (modification == "1"){
			cout << "This is the author's name:" << map.getAuthor() << endl;
			cout << "Input a new author's name or skip" << endl;
			cin >> modification;

			if (modification != "skip"){
				map.setAuthor(modification);
			}
		}
		else if (modification == "2"){
			cout << "This is the image's filename:" << map.getImage() << endl;
			cout << "Input a new image's filename or skip" << endl;
			cin >> modification;

			if (modification != "skip"){
				map.setImage(modification);
			}
		}
		else if (modification == "3"){
			cout << "This is the map's wrap:" << map.getWrap() << endl;
			cout << "Input a new map's wrap or skip" << endl;
			cin >> modification;

			if (modification != "skip"){
				map.setWrap(modification == "true" ? true : false);
			}
		}
		else if (modification == "4"){
			cout << "This is the map's scroll:" << map.getScroll() << endl;
			cout << "Input a new map's scroll or skip" << endl;
			cin >> modification;

			if (modification != "skip"){
				map.setScroll(modification);
			}
		}
		else if (modification == "5"){
			cout << "This is the map's warn:" << map.getWarn() << endl;
			cout << "Input a new map's warn or skip" << endl;
			cin >> modification;

			if (modification != "skip"){
				map.setWarn(modification == "true" ? true : false);
			}
		}
		else{
			break;
		}
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
		string modification = "";
		while (modification != "0"){
			cout << "What would you like to edit ?[1,2] 0 to exit" << endl;
			cout << "1 - Continent's Name " << endl;
			cout << "2 - Continent's Maximum Number of Units " << endl;
			cout << "0 - Exit" << endl;
			cin >> modification;
			if (modification == "1"){
				cout << "This is the continents's name:" << map.Continents[stoi(updateContinentNumber) - 1].getName() << endl;
				cout << "Input a new continents's name or skip" << endl;
				cin >> modification;

				if (modification != "skip"){
					map.Continents[stoi(updateContinentNumber) - 1].setName(modification);
				}
			}
			else if (modification == "2"){
				cout << "This is the continents's maximum number of units:" << map.Continents[stoi(updateContinentNumber) - 1].getUnit() << endl;
				cout << "Input a new continents's maximum number of units or skip" << endl;
				cin >> modification;

				if (modification != "skip"){
					map.Continents[stoi(updateContinentNumber) - 1].setUnit(stoi(modification));
				}
			}
			else{
				break;
			}
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

			cout << "What would you like to edit ?[1,2,3,4,5] 0 to exit" <<  endl;
			cout << "1 - Name " << endl;
			cout << "2 - Latitude " << endl;
			cout << "3 - Longitude " << endl;
			cout << "4 - Continent " << endl;
			cout << "5 - Adjacent Territories " << endl;
			cout << "0 - Exit" << endl;
			cin >> modification;

			if(modification == "1"){
				cout << "This is the territory's name:" << map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].getName() << endl;
				cout << "Input a new territory's name" << endl;
				cin >> modification;

				if (modification != "skip"){
					map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].setName(modification);
				}
			}
			else if(modification == "2"){
				cout << "This is the territory's latitude:" << map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].getLatitude() << endl;
				cout << "Input a new territory's latitude" << endl;
				cin >> modification;

				if (modification != "skip"){
					map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].setLatitude(stoi(modification));
				}
			}
			else if(modification == "3"){
				cout << "This is the territory's longitude:" << map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].getLongitude() << endl;
				cout << "Input a new territory's longitude" << endl;
				cin >> modification;

				if (modification != "skip"){
					map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].setLongitude(stoi(modification));
				}
			}
			else if(modification == "4"){
				cout << "This is the territory's continent:" << map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].getContinent() << endl;
				cout << "Input a new territory's continent" << endl;
				cin >> modification;

				if (modification != "skip"){
					if (modification != map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].getContinent()){
						map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].setContinent(modification);
					}
				}
			}
			else if (modification == "5"){
				cout << "This is the territory's adjacent countries:" << endl;
				for(int k=0;k< map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].adjacentTerritories.size();k++){
					cout << k+1 << "-" << map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].adjacentTerritories[k] << endl;
				}
				cout << "Do you want to add or remove adjacent country?" << endl;
				cin >> modification; 
				if(modification == "add"){
					cout << "Type the name of adjacent country you want to add" << endl;
					cin >> modification; 
					map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].adjacentTerritories.push_back(modification);
				}
				else if(modification=="remove"){
					cout << "Type the name of adjacent country you want to remove" << endl;
					cin >> modification; 
					for(int a=0;a< map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].adjacentTerritories.size();a++){
						if(map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].adjacentTerritories[a] == modification){
							map.Continents[i].Territories[stoi(updateTerritoryNumber) - 1].adjacentTerritories[a].erase();
						}
					}
				}
			}
			else if (modification == "0"){
				updateTerritoryNumber = "next";
			}
			else{ 
				break; 
			}
		}
	}
	return map;
}

bool MapEditorComponent::ValidateMap(Map map){
	bool isValid = true;

	for (int i = 0; i < map.Continents.size(); i++){
		//CHECK CONTINENTS NAMES
		string continentName = map.Continents[i].getName();
		for (int j = i+1; j < map.Continents.size(); j++){
			if (map.Continents[j].getName() == continentName){
				isValid = false;
			}
		}
		
		//CHECK TERRITORIES NAMES
		for (int k = 0; k < map.Continents[i].Territories.size(); k++){
			string territoryName = map.Continents[i].Territories[k].getName();
			for (int l = k+1; l < map.Continents[i].Territories.size(); l++){
				if (territoryName == map.Continents[i].Territories[l].getName()){
					isValid = false;
				}
			}
		}
	}
	return isValid;
}

Map MapEditorComponent::AddTerritory(Map map){
	string addTerritory;
	string territoryName;
	double latitude;
	double longitude;
	int territoryCount = 1;
	string adjacentTerritory;
	string continentName;

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
	cout << "Which continent do you want your territory to be added to?" << endl;
	cin >> continentName;
	Territories territory = Territories(territoryName, latitude, longitude, continentName, adjacentTerritories);
	for (int i = 0; i < map.Continents.size(); i++){
		if (map.Continents[i].getName() == continentName){
			map.Continents[i].Territories.push_back(territory);
		}
	}
	return map;
}

Map MapEditorComponent::AddContinentAndTerritories(Map map, string continentName, int continentUnitCount){
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

