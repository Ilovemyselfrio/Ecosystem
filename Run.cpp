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
		ecosystem.loadFromfile("ecobj.txt");
	}
	ecosystem.simulateEcosystem(Time);//开始模拟
	//ecosystem.Eco_print();
	system("pause");
	return 0;
}