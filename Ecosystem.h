#pragma once
#include "creature.h"
#include "wolf.h"
#include "sheep.h"
#include "grass.h"
#include <iostream>
#include <random>
#include <vector>
using namespace std;
 
class Ecosystem {
public:
	void setCreatureNum(int wolf, int sheep, int grass);
	void create();
	void simulateEcosystem(int time);
	void saveTofile(const string& filename);
	void addCreature(Creature* creature);
	void loadFromfile(const string& filename);
	void Eco_print();
	string rand_sex();
	string rand_name();
	void removeObj(Creature* creature);
	void simHumaInter();
	void simDisaster();
private:
	vector<Creature*> creatures;
	int numW;
	int numS;
	int numG;
};







