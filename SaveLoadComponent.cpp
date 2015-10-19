#include<iostream>
#include<string>
#include <fstream>
#include "Continent.h"
#include "Territories.h"
#include "Map.h"
#include <sstream>

using namespace std;

void main()
{
	string line;
	ifstream myfile;
	myfile.open ("World.map", ios::out | ios::app | ios::binary); 
	if (myfile.is_open())
	{
		Map map;
		string author;
		string image;
		bool wrap;
		string scroll;
		bool warn;

		while (getline (myfile,line) )
		{
			if(line == "[Map]\r"){
				while(line != "\r")
				{
					getline (myfile,line);
					string delimiter = "=";
					string attribute = line.substr(0, line.find(delimiter));
					string value = line.substr(line.find(delimiter)+1);
					string delimiter2 = "\r";
					string value2 = value.substr(0, value.find(delimiter2));

					if(attribute=="author"){
						author = value2;
					}
					if(attribute=="image"){
						image = value2;
					}
					if(attribute=="wrap" ){
						wrap = value2 == "yes"? true : false;
					}
					if(attribute=="scroll"){
						scroll = value2;
					}
					if(attribute=="warn"){
						warn = value2 == "yes"? true: false;
					}
				}
				map = Map(author,image,wrap,scroll,warn); 
				cout << map.getAuthor() << endl;
				cout << map.getImage() << endl;
				cout << map.getWrap() << endl;
				cout << map.getScroll() << endl;
				cout << map.getWarn() << endl;
			}

			if(line == "[Continents]\r"){
				while(line != "\r")
				{
					getline (myfile,line);
					string delimiter = "=";
					string continentName = line.substr(0, line.find(delimiter));
					string value = line.substr(line.find(delimiter)+1);
					string delimiter2 = "\r";
					string units = value.substr(0, value.find(delimiter2));

					if(units!=""){
						Continent continent = Continent(continentName, atoi(units.c_str()));
						map.Continents.push_back(continent);
					}
				}
			}

			if(line == "[Territories]\r"){
				while(line != "\r")
				{
					string name;
					double latitude;
					double longitude;
					string continent;
					getline (myfile,line);

					string::size_type equal = line.find(',');
					name = line.substr(0,equal);
					cout << name << endl;
					line = line.substr(equal +1 , line.length());

					equal = line.find(',');
					string latitudeString = line.substr(0,equal);
					std::string::size_type sz;
					latitude = std::stod (latitudeString,&sz);
					cout << latitude << endl;
					line = line.substr(equal +1 , line.length());

					equal = line.find(',');
					string longitudeString = line.substr(0,equal);
					longitude = std::stod (longitudeString,&sz);
					cout << longitude << endl;
					line = line.substr(equal +1 , line.length());

					equal = line.find(',');
					continent = line.substr(0,equal);
					cout << continent << endl;
					line = line.substr(equal +1 , line.length());

					vector<string> adjacentTerritories;
					Territories Territory = Territories(name, latitude, longitude, continent, adjacentTerritories);
					cout << Territory.getName() << endl;
					cout << Territory.getLatitude() << endl;
					cout << Territory.getLongitude() << endl;
					cout << Territory.getContinent() << endl;
				}
			}
		  //cout << line << '\n';
		}
		std::cout << "myvector stores " << int(map.Continents.size()) << " numbers.\n";
		for(int i = 0; i < map.Continents.size(); i++) {
			cout << map.Continents[i].getName() << endl;
		}
		myfile.close();
	}

	else cout << "Unable to open file"; 

	Continent continent = Continent("America",2);
	//cout << continent.getName();

	/*getline(fileReader, mapLine);
    std::string::size_type equal = mapLine.find('=');
    map.author = mapLine.substr(equal + 1, mapLine.length());
    cout << map.author << endl;*/

	int j;
	cin >> j;
}
