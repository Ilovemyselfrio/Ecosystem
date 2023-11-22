#pragma once
#include <iostream>
#include <string>
#include "creature.h"
using namespace std;
class Grass:public Creature
{
public:
	Grass(double vital = 0, double x = 0, double y = 0) : Creature("", "", 0, vital, x, y) { }
	void print();
	void move();
	 bool Isdie();
};

