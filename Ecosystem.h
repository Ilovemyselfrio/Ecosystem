#pragma once
#include "creature.h"
#include "wolf.h"
#include "sheep.h"
#include "grass.h"
#include <iostream>
#include <random>
#include <vector>
using namespace std;
string rand_sex() {
	int n = rand() % 2;
	if (n) {
		return "female";
	}
	else return "male";
}
string rand_name() {
	int len = 5;
	string ran_nam;
	char c;
	for (int i = 0; i < len; i++) {
		c = 'a' + rand() % 26;
		ran_nam.push_back(c);
	}
	return ran_nam;
}
void create(vector<Creature*>& creatures, int n_wolf, int n_sheep, int n_grass) {
	for (int i = 0; i < n_wolf; i++) {
		Creature* wolf = new Wolf(rand_name(), rand_sex(), rand() % 20, rand() % 101 + 10, rand() % 50, rand() % 50);
		creatures.push_back(wolf);
	}
	for (int i = 0; i < n_sheep; i++) {
		Creature* sheep = new Sheep(rand_name(), rand_sex(), rand() % 15, rand() % 101 + 10, rand() % 50, rand() % 50);
		creatures.push_back(sheep);
	}
	for (int i = 0; i < n_grass; i++) {
		Creature* grass = new Grass(rand() % 10 + 1, rand() % 50, rand() % 50);
		creatures.push_back(grass);
	}
}
static void simulateEcosystem(vector<Creature*>& creatures, int time) {
	cout << "-------------------------刚开始--------------------------------" << endl;
	for (Creature* creature : creatures) {
		creature->print();
	}
	
	for (int month = 1; month <= time; month++) {
		cout << "---------------------------------------------------------------" << endl;
		cout << "第" << month << "个月:" << endl;
		if (month % 12 == 0) {
			for (size_t i = 0; i < creatures.size(); i++) {
				creatures[i]->ageadd();
			}
		}
		for (size_t i = 0; i < creatures.size();) {
			Creature* creature = creatures[i];
			creature->move();
			if (month % 3 == 0) {
				creature->breed(creatures);
			}
			if (creature->Isdie()) {
				delete creature;
				creatures.erase(creatures.begin() + i);
			}
			else {
				bool eaten = false;
				for (size_t j = 0; j < creatures.size(); ++j) {
					if (i != j) {
						Creature* other = creatures[j];
						if (creature->Ishungary() && creature->Judge(other)) {
							creature->eat(other);
							delete other;
							creatures.erase(creatures.begin() + j);
							eaten = true;
							break; // 退出内层循环
						}
					}
				}
				if (!eaten) {
					++i;
				}
			}
		}

		system("pause");
		system("cls");

	}
	cout << "------------------------------------经过时间的洗礼----------------------------------" << endl;
	for (Creature* creature : creatures) {
		creature->print();
	}
	for (Creature* creature : creatures) {
		delete creature;
	}
	creatures.clear();
}
vector<Creature*> creatures;
void run() {
	srand((unsigned int)time(NULL));
	int Time;
	cout << "请输入运行时间：" << endl;
	cin >> Time;
	int n_wolf, n_sheep, n_grass;
	cout << "输入狼的数量：";
	cin >> n_wolf;
	cout << endl;
	cout << "输入羊的数量：";
	cin >> n_sheep;
	cout << endl;
	cout << "输入草的数量：";
	cin >> n_grass;
	cout << endl;
	create(creatures, n_wolf, n_sheep, n_grass);
	simulateEcosystem(creatures, Time);
	system("pause");

}




