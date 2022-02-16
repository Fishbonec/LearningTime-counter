#include <iostream>
#include "timecounter.h"

int main() {

	Manager datam;

	int choice = 0;

	while (true)
	{
		datam.showTotalTime();
		datam.showMenu();

		cout << "请输入选项" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:	//添加学习记录
			datam.addRecord();
			break;
		case 2:	//删除学习记录
			datam.deleteRecord();
			break;
		case 3:	//查看学习记录
			datam.showRecord();
			break;
		case 0:	//退出计数程序
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