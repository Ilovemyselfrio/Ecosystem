#include "Ecosystem.h"
bool isFirstrun() {
	ifstream checkfile("flag.txt");
	return !checkfile.good();
}
void NoFirstrun() {
	ofstream flagfile("flag.txt");
	if (flagfile.is_open()) {
		flagfile << "Flag is here!" << endl;
		flagfile.close();
	}
}
int main()
{
	
	srand((unsigned int)time(NULL));
	int Time;
	cout << "请输入运行时间：" << endl;
	cin >> Time;
	Ecosystem ecosystem;
	if (isFirstrun()) {
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
		ecosystem.setCreatureNum(n_wolf, n_sheep, n_grass);
		ecosystem.create();//创建对象并初始化信息
		NoFirstrun();
	}
	else {
		cout << "请做出以下决定:" << endl;
		cout << "输入1:生物在上一次的基础上进行活动" << endl;
		cout << "输入2:重新投放生物" << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:ecosystem.loadFromfile("ecobj.txt"); break;
		case 2: {
			const char* filename = "flag.txt";
			if (remove(filename) != 0) {
				cout << "No deleting" << endl;
			}
			else {
				cout << "deleting successfully" << endl;
			}
			if (isFirstrun()) {
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
				ecosystem.setCreatureNum(n_wolf, n_sheep, n_grass);
				ecosystem.create();//创建对象并初始化信息
				NoFirstrun();
			}
		}
			  break;
		default:
			cout << "无效输入！" << endl;
			return 0;
		}
		
	}
	ecosystem.simulateEcosystem(Time);//开始模拟
	//ecosystem.Eco_print();
	system("pause");
	return 0;
}