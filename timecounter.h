#pragma once
#include <iostream>
using namespace std;

#include"data.h"
#include <fstream>
#include <algorithm>
#include <vector>

class Manager
{
public:
	//构造函数
	Manager();
	
	//显示学习总时长
	void showTotalTime();

	//显示菜单
	void showMenu();

	//退出程序
	void exitSystem();

	//添加学习记录
	void addRecord();

	//创建vector容器保存数据
	vector<Data> vRecorder;

	//保存文件
	void save();

	//初始化容器
	void initRecorder();

	//显示记录
	void showRecord();

	//删除记录
	void deleteRecord();

	//对日期进行排序
	void sortDate();

	//析构函数
	~Manager()
	{

	}
	
};


