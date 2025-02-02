#include <iostream>
#include <fstream>
#include "extrafile.h"
#include <vector>
using namespace std;

int main()
{
	ifstream inFS;
	cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;

	if (option == 1) {
		inFS.open("friendlyships.shp");
		cout << "opened friendly" << endl;
	}
	else if (option == 2) {
		inFS.open("enemyships.shp");
		cout << "opened enemy" << endl;
	}
	else if (option == 3) {
		inFS.open("friendlyships.shp");
		inFS.open("enemyships.shp");
		cout << "opened both" << endl;
	}

	cout << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;

	cin >> option;

	int count;
	vector<Starships> starships;


	inFS.read(reinterpret_cast<char*>(&count), 4);

	int nameLength;
	int shipClassLength;
	short length;
	int shieldCapacity;
	float maxWarp;
	int weaponsCount;
	int weaponNameLength;
	int powerRating;
	float powerConsumption;
	for (int i = 0; i < count; i++) {
		Starships ship1;
		inFS.read(reinterpret_cast<char*>(&nameLength), 4);
		//cout<<nameLength<<endl;
		char* name = new char[nameLength];
		inFS.read(name, nameLength);
		//cout<<name<<endl;
		string strName = name;
		//cout<<strName<<endl;
		ship1.setName(strName);
		//delete[] name;
		//cout<<typeid(name).name()<<endl;
		inFS.read(reinterpret_cast<char*>(&shipClassLength), 4);
		//cout<<shipClassLength<<endl;
		char* shipClass = new char[shipClassLength];
		inFS.read(shipClass, shipClassLength);
		//cout<<shipClass<<endl;
		string strClassName = shipClass;
		ship1.setClass(strClassName);
		//delete[] shipClass;
		inFS.read(reinterpret_cast<char*>(&length), 2);
		//cout<<length<<endl;
		ship1.setLength(length);
		inFS.read(reinterpret_cast<char*>(&shieldCapacity), 4);
		//cout<<shieldCapacity<<endl;
		ship1.setShieldCapacity(shieldCapacity);
		inFS.read(reinterpret_cast<char*>(&maxWarp), 4);
		//cout<<maxWarp<<endl;
		ship1.setMaxWarp(maxWarp);
		inFS.read(reinterpret_cast<char*>(&weaponsCount), 2);
		//cout<<weaponsCount<<endl;
		for (int i = 0; i < weaponsCount; i++) {
			inFS.read(reinterpret_cast<char*>(&weaponNameLength), 4);
			//cout<<weaponNameLength<<endl;
			char* weaponName = new char[weaponNameLength];
			inFS.read(weaponName, weaponNameLength);
			string strWeaponName = weaponName;
			//cout<<weaponName<<endl;
			inFS.read(reinterpret_cast<char*>(&powerRating), 4);
			//cout<<powerRating<<endl;
			inFS.read(reinterpret_cast<char*>(&powerConsumption), 4);
			//cout<<powerConsumption<<endl;
			ship1.addWeapon(strWeaponName, powerRating, powerConsumption);
			//delete[] weaponName;
		}
		starships.push_back(ship1);
	}

	for (long unsigned int i = 0; i < starships.size(); i++) {
		starships.at(i).printShip();
	}


	inFS.close();
	return 0;
}