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
	//���캯��
	Manager();
	
	//��ʾѧϰ��ʱ��
	void showTotalTime();

	//��ʾ�˵�
	void showMenu();

	//�˳�����
	void exitSystem();

	//���ѧϰ��¼
	void addRecord();

	//����vector������������
	vector<Data> vRecorder;

	//�����ļ�
	void save();

	//��ʼ������
	void initRecorder();

	//��ʾ��¼
	void showRecord();

	//ɾ����¼
	void deleteRecord();

	//�����ڽ�������
	void sortDate();

	//��������
	~Manager()
	{

	}
	
};


