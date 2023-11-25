#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "creature.h"
#include "sheep.h"
using namespace std;
class Wolf:public Creature
{
public:
	Wolf(string name, string gend, int age, double vital,
		double x, double y) : Creature(name, gend, age, vital, x, y) { }
	~Wolf() { };
	string rand_sex();
	string rand_name();
public:
	 bool Judge(Creature* part) override;
	 void eat(Creature* part) override;
	 void breed(vector<Creature*>& creatures) override;
	 void move() override;
	 bool Isdie() override;
	 bool Ishungary() override;
	 void plus_Vital() ;
	 void print() override;
	 string serialize() const override;
private:
	int amount_eat = 0;
};
