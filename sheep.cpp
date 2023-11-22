#include "sheep.h"
string Sheep::rand_sex()
{
	int n = rand() % 2;
	if (n) {
		return "female";
	}
	else return "male";
}

string Sheep::rand_name()
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

void Sheep::eat(Creature* part)
{

	cout << "羊" << this->name << "正在吃草" << endl;
	this->amount_eat++;
	cout << "到目前为止，它已经吃掉了" << amount_eat << "捆草" << endl;
	this->plus_Vital();
}

void Sheep::breed(vector<Creature*>& creatures) {
	vector<Creature*> Newsheep;
	for (Creature* creature : creatures) {
		if (creature != this) {
			if (dynamic_cast<Sheep*>(creature) != nullptr) {
				if (this->age >= 3 && creature->get_age() >= 3 && creature->get_gend() != this->gender) {
					int chance = rand() % 100;
					if (chance < 90) {
						Creature* newSheep = new Sheep(rand_name(), rand_sex(), 0, 10, rand() % 50, rand() % 50);
						Newsheep.push_back(newSheep);
						cout << "A new sheep is born!" << endl;
						break;
					}
				}
			}
		}
	}
	for (Creature* creature : Newsheep) {
		creatures.push_back(creature);
	}
}

void Sheep::move() {
	int direction = rand() % 4;
	switch (direction) {
	case 0: x += 8; break;
	case 1: x -= 8; break;
	case 2: y += 8; break;
	case 3: y -= 8; break;
	}
}

bool Sheep::Isdie() {
	if (this->age > 10 || this->vitality <= 0) {
		cout << "羊" << this->name << "已经死亡" << endl;
		return true;
	}
	else {
		return false;
	}
}

bool Sheep::Judge(Creature* part) {
	if (dynamic_cast<Grass*>(part) != nullptr) {
		if (this->x < part->get_x() + 20 || this->y < part->get_y() + 20) {
			this->set_x(part->get_x());
			this->set_y(part->get_y());
			return true;
		}
		else {
			//cout << "可惜附近没有青草..." << endl;
			return false;
		}
	}
	else return false;
}

bool Sheep::Ishungary() {
	if (this->vitality < 40.0) {
		/*cout << "羊" << this->name << "现在有些饿，" << "咩咩咩~它想吃草啦...";
		cout << this->name << "现在的活力是" << this->vitality << "  " << "位置是" << *this << endl;*/
		//cout << "草的位置是" << *part << endl;
		return true;
	}
	else {
		return false;
	}
}

void Sheep::plus_Vital() {
	this->set_vital(this->get_vital() + 20.0);
	cout << "它现在的活力是" << this->get_vital() << endl;
}

void Sheep::print() {
	cout << "羊" << name << "的信息：" << "年龄:" << age << ", 性别:" << gender << ", 活力值:" << vitality;
	cout << ", 吃草数:" << amount_eat << "，位置:" << *this << endl;
}
