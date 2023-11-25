#include "creature.h"
#include "wolf.h"
#include "sheep.h"
#include "grass.h"
using namespace std;

bool Creature::Ishungary()
{
	return false;
}

bool Creature::Judge(Creature* part)
{
	return false;
}

string Creature::get_nam() const
{
	return name;
}

int Creature::get_age() const
{
	return age;
}

void Creature::set_age(const int& cage)
{
	age = cage;
}


string Creature::get_gend() const
{
	return gender;
}

Creature::~Creature() { }

//void Creature::save()
//{
//	ofstream ofs;
//	ofs.open(FILENAME, ios::out);
//	for (int i = 0; i < 5; i++) {
//		ofs << this->name << " "
//			<< this->gender << " "
//			<< this->age << " "
//			<< this->vitality << " "
//			<< this->x << " " << this->y << endl;
//	}
//}

void Creature::set_vital(const double& c_vitality) { vitality = c_vitality; }
void Creature::set_x(const double& c_x) { x = c_x; }
void Creature::set_y(const double& c_y) { y = c_y; }
double Creature::get_vital() const { return vitality; }
double Creature::get_x() const { return x; }
double Creature::get_y() const { return y; }

ostream& operator<<(ostream& os, Creature& creature)
{
	os << "(" << creature.get_x() << "," << creature.get_y() << ")" << endl;
	return os;
}
