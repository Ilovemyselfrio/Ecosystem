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
	cout << "����������ʱ�䣺" << endl;
	cin >> Time;
	Ecosystem ecosystem;
	if (isFirstrun()) {
		int n_wolf, n_sheep, n_grass;
		cout << "�����ǵ�������";
		cin >> n_wolf;
		cout << endl;
		cout << "�������������";
		cin >> n_sheep;
		cout << endl;
		cout << "����ݵ�������";
		cin >> n_grass;
		cout << endl;
		ecosystem.setCreatureNum(n_wolf, n_sheep, n_grass);
		ecosystem.create();//�������󲢳�ʼ����Ϣ
		NoFirstrun();
	}
	else {
		ecosystem.loadFromfile("ecobj.txt");
	}
	ecosystem.simulateEcosystem(Time);//��ʼģ��
	//ecosystem.Eco_print();
	system("pause");
	return 0;
}