#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


class Starships {
    class Weapons {
    private:
        string weaponName;
        int powerRating;
        float powerConsumption;
    public:
        Weapons(string& name1, int& powerRating1, float& powerConsumption1) {
            weaponName = name1;
            powerRating = powerRating1;
            powerConsumption = powerConsumption1;
        }
        string getWeaponName() {
            return weaponName;
        }
        int getPowerRating() {
            return powerRating;
        }
        float getPowerConsumption() {
            return powerConsumption;
        }
    };
private:
    string _name;
    string _shipClass;
    short _length;
    int _shieldCapacity;
    float _maxWarp;
    vector<Weapons> weaponsList;

public:
    ~Starships() {
        cout << "starships deleted" << endl;
    }
    void setName(string& name) {
        _name = name;
    }
    void printName() {
        cout << _name;
    }
    void setClass(string& shipClass) {
        _shipClass = shipClass;
    }
    void setLength(short& length) {
        _length = length;
    }
    void setShieldCapacity(int& shieldCapacity) {
        _shieldCapacity = shieldCapacity;
    }
    void setMaxWarp(float& maxWarp) {
        _maxWarp = maxWarp;
    }
    void addWeapon(string& name, int& powerRating, float& powerConsumption) {
        Weapons weapon1(name, powerRating, powerConsumption);
        weaponsList.push_back(weapon1);
    }
    void printShip() {
        cout << "Name: " << _name << endl;
        cout << "Class: " << _shipClass << endl;
        cout << "Length: " << _length << endl;
        cout << "Shield capacity: " << _shieldCapacity << endl;
        cout << "Maximum Warp: " << _maxWarp << endl;
        cout << "Armaments:" << endl;
        if (weaponsList.size() == 0) {
            cout << "Unarmed:" << endl;
        }
        else {
            for (long unsigned int i = 0; i < weaponsList.size(); i++) {
                cout << weaponsList.at(i).getWeaponName() << ", " << weaponsList.at(i).getPowerRating() << ", " << weaponsList.at(i).getPowerConsumption() << endl;
            }
        }
    }
};