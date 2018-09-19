#pragma once
#include<fstream>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class FileWordCounter
{
private:
	int line;
	unordered_map<string, int>  mp;
	int charNum;
	char s[1000000];
	//string s;
	int wordNum;
public:
	void init(ifstream& in);
	int getLine();
	int getCharNum();
	int getWordNum();
	bool isDigit(char ch);
	bool isLetter(char ch);
	vector<pair<int, string> > getVe();
	FileWordCounter();
	~FileWordCounter();
};

