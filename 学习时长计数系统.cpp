#include <iostream>
#include "timecounter.h"

int main() {

	Manager datam;

	int choice = 0;

	while (true)
	{
		datam.showTotalTime();
		datam.showMenu();

		cout << "������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:	//���ѧϰ��¼
			datam.addRecord();
			break;
		case 2:	//ɾ��ѧϰ��¼
			datam.deleteRecord();
			break;
		case 3:	//�鿴ѧϰ��¼
			datam.showRecord();
			break;
		case 0:	//�˳���������
			datam.exitSystem();
			break;
		default:
			system("cls");
			break;
		}


	}

	system("pause");
	return 0;
}