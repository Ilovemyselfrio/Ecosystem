#include "Ecosystem.h"

void Ecosystem::setCreatureNum(int wolf, int sheep, int grass)
{
	numW = wolf;
	numS = sheep;
	numG = grass;
}

void Ecosystem::create() {
	for (int i = 0; i < numW; i++) {
		Creature* wolf = new Wolf(rand_name(), rand_sex(), rand() % 20, rand() % 101 + 10, rand() % 50, rand() % 50);
		creatures.push_back(wolf);
	}
	for (int i = 0; i < numS; i++) {
		Creature* sheep = new Sheep(rand_name(), rand_sex(), rand() % 15, rand() % 101 + 10, rand() % 50, rand() % 50);
		creatures.push_back(sheep);
		
	}
	for (int i = 0; i < numG; i++) {
		Creature* grass = new Grass(rand() % 10 + 1, rand() % 50, rand() % 50);
		creatures.push_back(grass);
		
	}
}

void Ecosystem::simulateEcosystem(int time) {
	cout << "-------------------------刚开始--------------------------------" << endl;
	for (Creature* creature : creatures) {
		creature->print();
	}

	for (int month = 1; month <= time; month++) {
		cout << "---------------------------------------------------------------" << endl;
		cout << "第" << month << "个月:" << endl;
		simDisaster();
		if (month % 12 == 0) {
			for (Creature* creature : creatures) {
				int age = creature->get_age();
				age++;
				creature->set_age(age);
			}
		}
		for (size_t i = 0; i < creatures.size();) {
			Creature* creature = creatures[i];
			creature->move();
			if (month % 3 == 0) {
				creature->breed(creatures);
			}
			if (month % 2 == 0) {
				if (dynamic_cast<Wolf*>(creature) != nullptr) {
					creature->set_vital(0);
				}
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
		simHumaInter();

	}
	cout << "------------------------------------经过时间的洗礼----------------------------------" << endl;
	for (Creature* creature : creatures) {
		creature->print();
	}
	saveTofile("ecobj.txt");
	for (Creature* creature : creatures) {
		delete creature;
	}
	creatures.clear();
}

void Ecosystem::saveTofile(const string& filename) {
	ofstream file(filename, ios::out);
	if (file.is_open()) {
		for (Creature* creature:creatures) {
			file << creature->serialize() << endl;
		}
		file.close();
		cout << "Saved to " << filename << endl;
	}
	else {
		cerr << "Unable to open file " << filename << endl;
	}
}

void Ecosystem::addCreature(Creature* creature)
{
	creatures.push_back(creature);
}

void Ecosystem::loadFromfile(const string& filename)
{
	ifstream file(filename);
	if (file.is_open()) {
		string line;
		
		while (getline(file, line)) {
			
			istringstream iss(line);
			string type;
			iss >> type;
			Creature* creature = NULL;
			if (type == "Wolf") {
				int age, amount_eat;
				double vitality, x, y;
				string gender, name;
				iss >> name >> age >> gender >> vitality >> amount_eat >> x >> y;
				Creature* wolf = new Wolf(name, gender, age, vitality, x, y);
				addCreature(wolf);
			}
			else if (type == "Sheep") {
				int age, amount_eat;
				double vitality, x, y;
				string gender, name;
				iss >> name >> age >> gender >> vitality >> amount_eat >> x >> y;
				Creature* sheep = new Sheep(name, gender, age, vitality, x, y);
				addCreature(sheep);
			}
			else if (type == "Grass") {
				double vitality, x, y;
				iss >> vitality >> x >> y;
				Creature* grass = new Grass(vitality, x, y);
				addCreature(grass);
			}
		}
		file.close();
		cout << "Data loaded from file:" << filename << endl;
	}
	else {
		cerr << "Unable to open file:" << filename << endl;
	}	
}

void Ecosystem::Eco_print()
{
	for (Creature* creature : creatures) {
		creature->print();
	}
}

string Ecosystem::rand_sex()
{
	int n = rand() % 2;
	if (n) {
		return "female";
	}
	else return "male";
}

string Ecosystem::rand_name()
{
	int len = 5;
	string ran_nam;
	char c;
	for (int i = 0; i < len; i++) {
		c = 'a' + rand() % 26;
		ran_nam.push_back(c);
	}
	return ran_nam;
}

void Ecosystem::removeObj(Creature* creature)
{
	auto it = find(creatures.begin(), creatures.end(), creature);
	if (it != creatures.end()) {
		creatures.erase(it);
		delete creature;
	}
	
}

void Ecosystem::simHumaInter()
{
	cout << "请输入您想进行的操作:" << endl;
	cout << "1:添加生物   2:捕食生物  3:不进行人为干预" << endl;
	int fchoice;
	cin >> fchoice;
	if (fchoice == 1) {
		cout << "请输入您想要添加的生物:" << endl;
		cout << "1:增加狼的数量  2:增加羊的数量  " << endl;
		int schoice;
		cin >> schoice;
		switch (schoice) {
		case 1: {
			cout << "请输入添加狼的数量:" << endl;
			int cnt;
			cin >> cnt;
			for (int i = 1; i <= cnt; i++) {
				Creature* wolf = new Wolf(rand_name(), rand_sex(), rand() % 10, rand() % 100, rand() % 50, rand() % 50);
				addCreature(wolf);
			}
			break;
		}
		case 2: {
			cout << "请输入添加羊的数量:" << endl;
			int cnt;
			cin >> cnt;
			for (int i = 1; i <= cnt; i++) {
				Creature* sheep = new Sheep(rand_name(), rand_sex(), rand() % 10, rand() % 100, rand() % 50, rand() % 50);
				addCreature(sheep);
			}
			break;
		}
		default:
			cout << "无效输入！" << endl;
}
	}
	else if (fchoice == 2) {
		cout << "请输入您想要捕捉的生物:" << endl;
		cout << "1:捕食狼  2:捕食羊 " << endl;
		int schoice;
		cin >> schoice;
		switch (schoice) {
		case 1: {
			cout << "请决定捕食狼的数量:" << endl;
			int cnt;
			cin >> cnt;
			for (int i = 1; i <= cnt; i++) {
				bool wolfFound = false;
				Wolf* wolfT = NULL;
				for (Creature* creature : creatures) {
					Wolf* wolf = dynamic_cast<Wolf*>(creature);
					if (wolf) {
						wolfT = wolf;
						wolfFound = true;
						break;
					}
				}
				if (wolfFound) {
					cout << "成功捕食第" << i << "头狼" << endl;
					removeObj(wolfT);
				}
				else {
					cout << "找不到狼了......" << endl;
				}
			}
			break;
		}
		case 2: {
			cout << "请决定捕食羊的数量:" << endl;
			int cnt;
			cin >> cnt;
			for (int i = 1; i <= cnt; i++) {
				bool sheepFound = false;
				Sheep* sheepT = NULL;
				for (Creature* creature : creatures) {
					Sheep* sheep = dynamic_cast<Sheep*>(creature);
					if (sheep) {
						sheepT = sheep;
						sheepFound = true;
						break;
					}
				}
				if (sheepFound) {
					cout << "成功捕食第" << i << "头羊" << endl;
					removeObj(sheepT);
				}
				else {
					cout << "找不到羊了......" << endl;
				}
			}
			break;
	        }			
		}
	}
	else if (fchoice == 3) {
		return;
	}
}

void Ecosystem::simDisaster()
{
	int chance = rand() % 100;
	if (chance < 30) {
		for (Creature* creature : creatures) {
			Wolf* wolf = dynamic_cast<Wolf*>(creature);
			Sheep* sheep = dynamic_cast<Sheep*>(creature);
			if (wolf) {
				int vit = wolf->get_vital();
				wolf->set_vital( vit - 4);
				cout << "狼受到了雷电的惊吓，活力下降..." << endl;
			}
			if (sheep) {
				int vit = sheep->get_vital();
				sheep->set_vital(vit - 5);
				cout << "羊受到了雷电的惊吓，活力下降..." << endl;
			}
		}
	}
	else if (chance < 10) {
		int num = rand() % 5 + 1;
		for (int i = 1; i <= num; i++) {
			for (Creature* creature : creatures) {
				Wolf* wolf = dynamic_cast<Wolf*>(creature);
				Sheep* sheep = dynamic_cast<Sheep*>(creature);
				if (wolf) {
					wolf->set_vital(0);
					cout << "有只狼被不幸被雷劈死了!" << endl;
				}
				if (sheep) {
					sheep->set_vital(0);
					cout << "有只羊被不幸被雷劈死了!" << endl;
				}
			}
		}
	}
}

