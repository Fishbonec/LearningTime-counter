#include "timecounter.h"

//构造函数
Manager::Manager()
{
	//初始化容器
	initRecorder();
	//测试代码
	//for (int i = 0; i < vRecorder.size(); i++)
	//{
	//	cout << vRecorder[i].m_Date << " "
	//		<< vRecorder[i].m_Time << endl;
	//}
}

//显示学习总时长
void Manager::showTotalTime()
{
	double sum = 0;
	for (vector<Data>::iterator it = vRecorder.begin(); it != vRecorder.end(); it++)
	{
		sum += it->m_Time;//计算总时长
	}
	
	//表格特殊符号╔  ╗═║╚  ╝
	cout << "╔══════════════════════════════════════════╗" << endl; 
	cout << "║              学习时长计数系统            ║" << endl;

	if (sum < 100)
	{
		cout << "║ ----------  学习总时长: 0" << sum << "h ----------║" << endl;
	}
	else if (sum > 100)
	{
		cout << "║ ----------  学习总时长: " << sum << "h ----------║" << endl;
	}
	
}

//显示菜单
void Manager::showMenu()
{
	cout << "║              1.添加学习记录              ║" << endl;
	cout << "║              2.删除学习记录              ║" << endl;
	cout << "║              3.查看学习记录              ║" << endl;
	cout << "║              0.退出计数程序              ║" << endl;
	cout << "╚══════════════════════════════════════════╝" << endl;
	cout << endl;
}

//退出程序
void Manager::exitSystem()
{
	system("pause");
	exit(0);
}

//添加学习记录

//内置数据类型
int finddate;//该变量可以用于设定比较值

class findDate//查找指定日期
{
public:
	bool operator()(Data &data)
	{
		if (data.m_Date == finddate)
			return true;
		else
			return false;
	}
};

void Manager::addRecord()
{
	//实例化需要记录的数据对象
	Data data;

	//获取要添加的数据
	cout << "输入日期：" << endl;
	cin >> data.m_Date;

	//判断输入的日期是否有重复
	finddate = data.m_Date;
	vector<Data>::iterator it = find_if(vRecorder.begin(), vRecorder.end(), findDate());

	while(true)
	{
		if (it == vRecorder.end())
		{
			//没有重复则继续执行下面的添加
			cout << "输入学习时长(h)" << endl;
			cin >> data.m_Time;

			//将新数据存入vector容器
			vRecorder.push_back(data);

			//打印提示
			cout << "添加记录成功" << endl;

			//排序并保存文件
			sortDate();
			save();

			//清一下屏
			system("pause");
			system("cls");
			break;
		}
		else
		{
			cout << "该日期已记录，请重新输入: " << endl;
			cin >> data.m_Date;
			finddate = data.m_Date;

			it = find_if(vRecorder.begin(), vRecorder.end(), findDate());//重新找一次
		}
	}
	

}

//保存文件
void Manager::save()
{
	ofstream ofs;
	ofs.open("record.txt", ios::out);


	for (int i = 0; i < vRecorder.size(); i++)
	{
		ofs << vRecorder[i].m_Date << " "
			<< vRecorder[i].m_Time << endl;
	}

	ofs.close();
}

//初始化容器
void Manager::initRecorder()
{
	ifstream ifs;
	ifs.open("record.txt", ios::in);

	int date;
	double time;

	//创建一个vector容器接收

	while (ifs >> date && ifs >> time)
	{
		Data data;
		data.m_Date = date;
		data.m_Time = time;

		//存入容器
		vRecorder.push_back(data);

	}

}

//显示记录

//内置数据类型
int month;//该变量可以用于设定比较值

class findMonthL//对应下区间
{
public:
	bool operator()(Data &data)
	{
		return data.m_Date > 220000+month*100;
	}
};

class findMonthH//对应上区间
{
public:
	bool operator()(Data &data)
	{
		return data.m_Date > 220000 + (month+1) * 100;
	}
};

void Manager::showRecord()
{
	//设置多种显示方式
	cout << "╔══════════════════════════════════════════╗" << endl;
	cout << "║              1.显示所有记录              ║" << endl;
	cout << "║              2.显示指定月份              ║" << endl;
	cout << "╚══════════════════════════════════════════╝" << endl;
	cout << endl;

	int choice;
	cout << "请输入显示方式" << endl;
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 1:	//显示所有记录
	{
		cout << "日期" << "\t  " << "时长" << endl;
		for (vector<Data>::iterator it1 = vRecorder.begin(); it1 != vRecorder.end(); it1++)
		{
			cout << it1->m_Date << "    " << it1->m_Time << endl;
		}
	}
	break;
	case 2:	//显示指定月份
	{
		
		cout << "请输入月份" << endl;
		cin >> month;
		if (month < 2 || month>12)//检测有无输入错误
		{
			cout << "请重新输入月份：" << endl;
			cin >> month;
		}

		//找到对应月份所在的区间
		vector<Data>::iterator itL = find_if(vRecorder.begin(), vRecorder.end(), findMonthL());
		vector<Data>::iterator itH = find_if(vRecorder.begin(), vRecorder.end(), findMonthH());

		cout << "日期" << "\t  " << "时长" << endl;
		for (vector<Data>::iterator it = itL; it != itH; it++)
		{
			cout << it->m_Date << "    " << it->m_Time << endl;
		}
	}
		break;
	default:
		system("cls");
		break;
	}
	cout << endl;
	//清一下屏
	system("pause");
	system("cls");
}

//删除记录
void Manager::deleteRecord()
{
	
	cout << "请输入要删除的日期" << endl;
	cin >> finddate;
	//查找容器中是否有该日期
	vector<Data>::iterator it = find_if(vRecorder.begin(), vRecorder.end(), findDate());
	if (it == vRecorder.end())
	{
		cout << "没有找到该日期!" << endl;
	}
	else
	{
		vRecorder.erase(it);
		cout << "删除成功" << endl;
	}

	//排序并保存文件
	sortDate();
	save();

	//清一下屏
	system("pause");
	system("cls");
}

//对日期进行排序

//内置数据类型

class sortdate
{
public:
	bool operator()(Data &data1, Data &data2)
	{
		return data1.m_Date < data2.m_Date;
	}
};

void Manager::sortDate()
{
	sort(vRecorder.begin(), vRecorder.end(), sortdate());
}