#include<iostream>
#include<string>
#include <fstream>
#include "Continent.h"
#include "Territories.h"
#include "Map.h"
#include <sstream>
#include "SaveLoadComponent.h"

using namespace std;

Map SaveLoadComponent::readMap(string mapName){
	string line;
	ifstream myfile;
	myfile.open(mapName, ios::out | ios::app | ios::binary);
	if (myfile.is_open())
	{
		Map map;
		string author;
		string image;
		bool wrap;
		string scroll;
		bool warn;

		while (getline(myfile, line))
		{
			if (line == "[Map]\r"){
				while (line != "\r")
				{
					getline(myfile, line);
					string delimiter = "=";
					string attribute = line.substr(0, line.find(delimiter));
					string value = line.substr(line.find(delimiter) + 1);
					string delimiter2 = "\r";
					string value2 = value.substr(0, value.find(delimiter2));

					if (attribute == "author"){
						author = value2;
					}
					if (attribute == "image"){
						image = value2;
					}
					if (attribute == "wrap"){
						wrap = value2 == "yes" ? true : false;
					}
					if (attribute == "scroll"){
						scroll = value2;
					}
					if (attribute == "warn"){
						warn = value2 == "yes" ? true : false;
					}
				}
				map = Map(author, image, wrap, scroll, warn);
			}

			if (line == "[Continents]\r"){
				while (line != "\r")
				{
					getline(myfile, line);
					string delimiter = "=";
					string continentName = line.substr(0, line.find(delimiter));
					string value = line.substr(line.find(delimiter) + 1);
					string delimiter2 = "\r";
					string units = value.substr(0, value.find(delimiter2));

					if (units != ""){
						Continent continent = Continent(continentName, atoi(units.c_str()));
						map.Continents.push_back(continent);
					}
				}
			}

			if (line == "[Territories]\r"){
				while (getline(myfile, line))
				{
					string name;
					double latitude;
					double longitude;
					string continent;
					if (line != "\r"){
						string::size_type equal = line.find(',');
						name = line.substr(0, equal);
						line = line.substr(equal + 1, line.length());

						equal = line.find(',');
						string latitudeString = line.substr(0, equal);
						std::string::size_type sz;
						latitude = std::stod(latitudeString, &sz);
						line = line.substr(equal + 1, line.length());

						equal = line.find(',');
						string longitudeString = line.substr(0, equal);
						longitude = std::stod(longitudeString, &sz);
						line = line.substr(equal + 1, line.length());

						equal = line.find(',');
						continent = line.substr(0, equal);
						line = line.substr(equal + 1, line.length());

						vector<string> adjacentTerritories;

						while (line.find(',') != std::string::npos || line.find("\r") != std::string::npos)
						{
							if (line.find(',') == std::string::npos)
							{
								equal = line.find("\r");
							}
							else
							{
								equal = line.find(',');
							}
							string adjacentTerritory = line.substr(0, equal);
							line = line.substr(equal + 1, line.length());
							adjacentTerritories.push_back(adjacentTerritory);
						}

						Territories Territory = Territories(name, latitude, longitude, continent, adjacentTerritories);
						for (int i = 0; i < map.Continents.size(); i++) {
							if (map.Continents[i].getName() == continent)
							{
								map.Continents[i].Territories.push_back(Territory);
							}
						}
					}
				}
			}
		}

		/*std::cout << "myvector stores " << int(map.Continents.size()) << " numbers.\n";
		cout << "This is your map :" << map.getImage() << endl;
		for (int i = 0; i < map.Continents.size(); i++) {
			cout << "Continent :" << "#" << i + 1 << endl;
			cout << map.Continents[i].getName() << endl;
			cout << "These are your territories :" << endl;
			for (int j = 0; j < map.Continents[i].Territories.size(); j++) {
				cout << map.Continents[i].Territories[j].getName() << endl;
			}
		}*/
		myfile.close();
		return map;
	}
	else cout << "Unable to open file";
}

void SaveLoadComponent::saveMap(string saveMapName, Map map)
{
	ofstream myfile;
	myfile.open(saveMapName, ios::out | ios::app | ios::binary);
	myfile << "[Map]" << "\r" <<endl;
	myfile << "author=" << map.getAuthor() << "\r"<< endl;
	myfile << "image=" << map.getImage() << "\r"<< endl;
	myfile << "wrap=" << (map.getWrap()==true?"yes":"no")<< "\r" << endl;
	myfile << "scroll=" << map.getScroll() << "\r"<< endl;
	myfile << "warn=" << (map.getWarn() == true ? "yes" : "no") << "\r"<< endl;
	myfile << "\r" << endl;

	//CONTINENTS
	myfile << "[Continents]" << "\r"<< endl;
	for (int i = 0; i < map.Continents.size(); i++) {
		myfile << map.Continents[i].getName() << "=" << map.Continents[i].getUnit() << "\r" << endl;
	}
	myfile << "\r" << endl;


	//TERRITORIES
	myfile << "[Territories]" << "\r"<< endl;
	for (int i = 0; i < map.Continents.size(); i++) {
		for (int j = 0; j < map.Continents[i].Territories.size(); j++) {
			myfile << map.Continents[i].Territories[j].getName() << "," << map.Continents[i].Territories[j].getLatitude() << "," << map.Continents[i].Territories[j].getLongitude() << "," << map.Continents[i].getName();
			for (int k = 0; k < map.Continents[i].Territories[j].adjacentTerritories.size(); k++) {
				myfile << ",";
				myfile << map.Continents[i].Territories[j].adjacentTerritories[k];
			}
			myfile << "\r" << endl;
		}
		myfile << "\r" << endl;
	}
	myfile << "\r" << endl;

	myfile.close();
}

