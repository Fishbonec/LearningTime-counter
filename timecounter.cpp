#include "timecounter.h"

//���캯��
Manager::Manager()
{
	//��ʼ������
	initRecorder();
	//���Դ���
	//for (int i = 0; i < vRecorder.size(); i++)
	//{
	//	cout << vRecorder[i].m_Date << " "
	//		<< vRecorder[i].m_Time << endl;
	//}
}

//��ʾѧϰ��ʱ��
void Manager::showTotalTime()
{
	double sum = 0;
	for (vector<Data>::iterator it = vRecorder.begin(); it != vRecorder.end(); it++)
	{
		sum += it->m_Time;//������ʱ��
	}
	
	//���������ŨX  �[�T�U�^  �a
	cout << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << endl; 
	cout << "�U              ѧϰʱ������ϵͳ            �U" << endl;

	if (sum < 100)
	{
		cout << "�U ----------  ѧϰ��ʱ��: 0" << sum << "h ----------�U" << endl;
	}
	else if (sum > 100)
	{
		cout << "�U ----------  ѧϰ��ʱ��: " << sum << "h ----------�U" << endl;
	}
	
}

//��ʾ�˵�
void Manager::showMenu()
{
	cout << "�U              1.���ѧϰ��¼              �U" << endl;
	cout << "�U              2.ɾ��ѧϰ��¼              �U" << endl;
	cout << "�U              3.�鿴ѧϰ��¼              �U" << endl;
	cout << "�U              0.�˳���������              �U" << endl;
	cout << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << endl;
	cout << endl;
}

//�˳�����
void Manager::exitSystem()
{
	system("pause");
	exit(0);
}

//���ѧϰ��¼

//������������
int finddate;//�ñ������������趨�Ƚ�ֵ

class findDate//����ָ������
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
	//ʵ������Ҫ��¼�����ݶ���
	Data data;

	//��ȡҪ��ӵ�����
	cout << "�������ڣ�" << endl;
	cin >> data.m_Date;

	//�ж�����������Ƿ����ظ�
	finddate = data.m_Date;
	vector<Data>::iterator it = find_if(vRecorder.begin(), vRecorder.end(), findDate());

	while(true)
	{
		if (it == vRecorder.end())
		{
			//û���ظ������ִ����������
			cout << "����ѧϰʱ��(h)" << endl;
			cin >> data.m_Time;

			//�������ݴ���vector����
			vRecorder.push_back(data);

			//��ӡ��ʾ
			cout << "��Ӽ�¼�ɹ�" << endl;

			//���򲢱����ļ�
			sortDate();
			save();

			//��һ����
			system("pause");
			system("cls");
			break;
		}
		else
		{
			cout << "�������Ѽ�¼������������: " << endl;
			cin >> data.m_Date;
			finddate = data.m_Date;

			it = find_if(vRecorder.begin(), vRecorder.end(), findDate());//������һ��
		}
	}
	

}

//�����ļ�
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

//��ʼ������
void Manager::initRecorder()
{
	ifstream ifs;
	ifs.open("record.txt", ios::in);

	int date;
	double time;

	//����һ��vector��������

	while (ifs >> date && ifs >> time)
	{
		Data data;
		data.m_Date = date;
		data.m_Time = time;

		//��������
		vRecorder.push_back(data);

	}

}

//��ʾ��¼

//������������
int month;//�ñ������������趨�Ƚ�ֵ

class findMonthL//��Ӧ������
{
public:
	bool operator()(Data &data)
	{
		return data.m_Date > 220000+month*100;
	}
};

class findMonthH//��Ӧ������
{
public:
	bool operator()(Data &data)
	{
		return data.m_Date > 220000 + (month+1) * 100;
	}
};

void Manager::showRecord()
{
	//���ö�����ʾ��ʽ
	cout << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << endl;
	cout << "�U              1.��ʾ���м�¼              �U" << endl;
	cout << "�U              2.��ʾָ���·�              �U" << endl;
	cout << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << endl;
	cout << endl;

	int choice;
	cout << "��������ʾ��ʽ" << endl;
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 1:	//��ʾ���м�¼
	{
		cout << "����" << "\t  " << "ʱ��" << endl;
		for (vector<Data>::iterator it1 = vRecorder.begin(); it1 != vRecorder.end(); it1++)
		{
			cout << it1->m_Date << "    " << it1->m_Time << endl;
		}
	}
	break;
	case 2:	//��ʾָ���·�
	{
		
		cout << "�������·�" << endl;
		cin >> month;
		if (month < 2 || month>12)//��������������
		{
			cout << "�����������·ݣ�" << endl;
			cin >> month;
		}

		//�ҵ���Ӧ�·����ڵ�����
		vector<Data>::iterator itL = find_if(vRecorder.begin(), vRecorder.end(), findMonthL());
		vector<Data>::iterator itH = find_if(vRecorder.begin(), vRecorder.end(), findMonthH());

		cout << "����" << "\t  " << "ʱ��" << endl;
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
	//��һ����
	system("pause");
	system("cls");
}

//ɾ����¼
void Manager::deleteRecord()
{
	
	cout << "������Ҫɾ��������" << endl;
	cin >> finddate;
	//�����������Ƿ��и�����
	vector<Data>::iterator it = find_if(vRecorder.begin(), vRecorder.end(), findDate());
	if (it == vRecorder.end())
	{
		cout << "û���ҵ�������!" << endl;
	}
	else
	{
		vRecorder.erase(it);
		cout << "ɾ���ɹ�" << endl;
	}

	//���򲢱����ļ�
	sortDate();
	save();

	//��һ����
	system("pause");
	system("cls");
}

//�����ڽ�������

//������������

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