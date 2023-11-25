#include "wolf.h"
using namespace std;
string Wolf::rand_sex()
{
	int n = rand() % 2;
	if (n) {
		return "female";
	}
	else return "male";
}

string Wolf::rand_name()
{
	int len = 5;
	string ran_nam;
	char c;
	char b[11] = "Newborn:";
	for (int i = 0; i < 8; i++) {
		ran_nam.push_back(b[i]);
	}
	for (int i = 0; i < len; i++) {
		c = 'a' + rand() % 26;
		ran_nam.push_back(c);
	}
	return ran_nam;
}

bool Wolf::Judge(Creature* part) {
	if (dynamic_cast<Sheep*>(part) != nullptr) {
		double sp_health;
		if (this->x < part->get_x() + 20 || this->y < part->get_y() + 20) {
			this->vitality -= 10;
			part->set_vital(part->get_vital() - 11);
			sp_health =part->get_vital() - this->vitality;
			if (sp_health <= 0) {
				part->move();
				this->set_x(part->get_x());
				this->set_y(part->get_y());
				return true;

			}
			else {
				cout << "�������" << part->get_nam() << "�ӵ���......" << endl;
				return false;
			}
		}
		else {
			cout << "��ϧ̫Զ��" << endl;
			return false;
		}
	}
	else return false;
}

void Wolf::eat(Creature* part)
{       
	    cout << "��" << this->name << "�Ե���С��" << part->get_nam() << endl;
		this->amount_eat++;
		cout << "��ĿǰΪֹ�����Ѿ��Ե���" << amount_eat << "ֻС��" << endl;
		this->plus_Vital();
}

void Wolf::plus_Vital() {
	this->set_vital(110);
	cout << "�����ڵĻ�����" << this->get_vital() << endl;
}

void Wolf::breed(vector<Creature*>& creatures)
{
	for (Creature* creature: creatures) {
		if (creature != this) {
			if (dynamic_cast<Wolf*>(creature) != nullptr) {
				if (this->age >= 4 && creature->get_age() >= 4 && creature->get_gend() != this->gender) {
					int chance = rand() % 100;
					if (chance < 60) {
						Creature* newWolf = new Wolf(rand_name(), rand_sex(), 0, 10, rand() % 50, rand() % 50);
						creatures.push_back(newWolf);
						cout << "A new wolf is born!" << endl;
						break;
					}
				}
			}
		}
	}
}

void Wolf::move()
{
	int direction = rand() % 4;
	switch (direction) {
	case 0: x += 10, vitality -= 10; break;
	case 1: x -= 10, vitality -= 10; break;
	case 2: y += 10, vitality -= 10; break;
	case 3: y -= 10, vitality -= 10; break;
	}
}

bool Wolf::Isdie()
{
	if (this->age > 15 || this->vitality <= 0) {
		cout << "��" << this->name << "�Ѿ�����" << endl;
		return true;
	}
	else {
		return false;
	}
}

bool Wolf:: Ishungary() {
	if (this->vitality < 60.0) {
		return true;
	}
	else {
		return false;
	}
}

void Wolf::print() {
	cout << "��" << name << "����Ϣ��" << "����:" << age << ", �Ա�:" << gender << ", ����ֵ:" << vitality;
	cout << ", ������:" << amount_eat << "��λ��:" << *this << endl;
}

string Wolf::serialize() const
{
	ostringstream oss;
	oss << "Wolf" << " " << this->name << " " << this->age << " " << this->gender << " " << this->vitality << " " << this->amount_eat 
		<< " " << this->x << " " << this->y;
	return oss.str();
}

