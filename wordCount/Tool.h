#pragma once
#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<unordered_map>
using namespace std;



class Tool
{
public:
	void init(ifstream & txt);
	bool isDigit(char ch);
	bool isBEng(char ch);
	bool isEng(char ch);
	char lowEng(char ch);
	int GetCharNum();
	int GetWordNum();
	int GetLines();
	vector<pair<int, string> > GetVe();
	Tool();
	~Tool();
private:
	int CharNum;
	int WordNum;
	int Lines;
	unordered_map<string, int> mp;
};

