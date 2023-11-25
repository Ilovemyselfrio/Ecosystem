#pragma once
#include <iostream>
#include <string>
#include "creature.h"
#include "grass.h"
using namespace std;
class Sheep :public Creature
{
public:
	Sheep(string sname, string sgend, int sage, double svital,
		double sx, double sy) : Creature(sname, sgend, sage, svital, sx, sy) { }
	~Sheep() { };
	string rand_sex();
	string rand_name();
public:
	void eat(Creature* part) override;
	void breed(vector<Creature*>& creatures) override;
	void move() override;
	bool Isdie() override;
	bool Ishungary() override;
	void plus_Vital();
	void print() override;
	bool Judge(Creature* part) override;
	string serialize() const override;
private:
	int amount_eat = 0;
};
