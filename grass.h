#pragma once
#include <iostream>
#include <string>
#include "creature.h"
using namespace std;
class Grass:public Creature
{
public:
	Grass(double vital = 0, double x = 0, double y = 0) : Creature(vital, x, y) { }
	string serialize() const override;
	void print()override;
	void move();
	 bool Isdie();
};

