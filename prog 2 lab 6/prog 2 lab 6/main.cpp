#include <iostream>
#include <map>
#include <random>
#include <ctime>
using namespace std;

mt19937 random_mt;

int Random(int min, int max)
{
	uniform_int_distribution<int> dist(min, max);
	return dist(random_mt);
}

void rollDice(int numberofRolls, int numberOfSides) {
	map<int, int> rollsMap;
	//map<int, int>::iterator iter = rollsMap.begin();

	for (int i = 1; i <= numberOfSides; i++) {
		rollsMap[i] = 0;
		//cout << i << ", " << rollsMap[i] << endl;
	}

	for (int i = 0; i < numberofRolls; i++) {
		int currRoll = Random(1, numberOfSides);
		//cout << "curr roll" << currRoll << endl;
		for (int j = 1; j <= numberOfSides; j++) {
			if (currRoll == j) {
				rollsMap[j]++;
				//cout << j << ", " << rollsMap[j] << endl;
			}
		}
	}

	for (int i = 1; i <= numberOfSides; i++) {
		cout << i << ": " << rollsMap[i] << endl;
	}
}

class States {
	string name;
	int income;
	int pop;
	int houseIncome;
	int numHouseholds;
	States(string name, int income, int pop, int houseIncome, int numHouseholds) {
		this->name = name;
		this->income = income;
		this->pop = pop;
		this->houseIncome = houseIncome;
		this->numHouseholds = numHouseholds;
	}
};

int main()
{
	cout << "1. Random Numbers\n";
	cout << "2. State Info\n";

	int option;
	cin >> option;

	if (option == 1)
	{
		int randomSeed;
		cout << "Random seed value: ";
		cin >> randomSeed;
		random_mt.seed(randomSeed);

		int numRolls;
		int numSides;


		cout << "Number of times to roll the die: ";
		// user input
		cin >> numRolls;

		cout << "Number of sides on this die: ";
		// user input
		cin >> numSides;

		
		rollDice(numRolls, numSides);
		
	}
	else if (option == 2)
	{
		// Load the states
		
		// Get input for option 1 (show all states) or 2 (do a search for a particular state)

	}

	return 0;
}
