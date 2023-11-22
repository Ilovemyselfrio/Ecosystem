#pragma once
#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Creature
{
public:
	Creature(string cname, string cgender, int cage, double vital, double x, double y)
		:name(cname), gender(cgender), age(cage), vitality(vital), x(x), y(y)
	{ }
	~Creature();
public:
	virtual void print() = 0;
	virtual void move() = 0;
	virtual bool Isdie() = 0;
	virtual void eat(Creature* part) {}
	virtual void breed(vector<Creature*>& creatures) {}
	virtual bool Ishungary();
	virtual bool Judge(Creature* part);

	friend ostream& operator << (ostream& os, Creature& creature);
	string get_nam() const;
	int get_age() const;
	void ageadd();
	string get_gend() const;
public:

	void set_vital(const double& vitality);
	void set_x(const double& x);
	void set_y(const double& y);
	double get_vital() const;
	double get_x() const;
	double get_y() const;

protected:
	double vitality;
	double x;
	double y;
	string name;
	string gender;
	int age;
};


