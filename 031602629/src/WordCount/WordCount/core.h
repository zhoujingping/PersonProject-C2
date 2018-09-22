#pragma once
//#include "core.h"
#include<string>
#include<map>
#include<iterator>
#include <vector>
//有string类型要加这句
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
	//按字典排序
	int zdsort(string word[], int wordc[], int k);
	//排序
	void csort();
	//统计字符
	int countzf();
	//统计行数
	int counths();
	//统计单词数
	int countdc();
	//排序单词词频
	int write();
};