#pragma once
//#include "core.h"
#include<string>
#include<map>
#include<iterator>
#include <vector>
//��string����Ҫ�����
using namespace std;
class tjb
{
private:
	string wj;
	int characters=0;
	int words=0;
	int lines=0;
	map<string, int> mm;
	vector<pair<string, int>> v;
public:
	void readwj(FILE *fp);
	int getcharacters();
	int getwords();
	int getlines();
	int plsort(string word[], int wordc[], int k);
	//���ֵ�����
	int zdsort(string word[], int wordc[], int k);
	//����
	void csort();
	//ͳ���ַ�
	int countzf();
	//ͳ������
	int counths();
	//ͳ�Ƶ�����
	int countdc();
	//���򵥴ʴ�Ƶ
	int write();
};