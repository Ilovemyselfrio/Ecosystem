#include "Ecosystem.h"
int main()
{
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
	srand((unsigned int)time(NULL));
	int Time;
	cout << "请输入运行时间：" << endl;
	cin >> Time;

	Ecosystem ecosystem;
	ecosystem.setCreatureNum(n_wolf, n_sheep, n_grass);
	ecosystem.create();//创建对象并初始化信息
	//ecosystem.saveTofile("ecobj.txt");//将对象的信息写入文档
	ecosystem.simulateEcosystem(Time);//开始模拟
	//ecosystem.loadFromfile("ecobj.txt");
	//ecosystem.Eco_print();
	system("pause");
	return 0;
}