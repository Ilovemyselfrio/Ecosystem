#include "Ecosystem.h"
int main()
{
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
	srand((unsigned int)time(NULL));
	int Time;
	cout << "����������ʱ�䣺" << endl;
	cin >> Time;

	Ecosystem ecosystem;
	ecosystem.setCreatureNum(n_wolf, n_sheep, n_grass);
	ecosystem.create();//�������󲢳�ʼ����Ϣ
	//ecosystem.saveTofile("ecobj.txt");//���������Ϣд���ĵ�
	ecosystem.simulateEcosystem(Time);//��ʼģ��
	//ecosystem.loadFromfile("ecobj.txt");
	//ecosystem.Eco_print();
	system("pause");
	return 0;
}