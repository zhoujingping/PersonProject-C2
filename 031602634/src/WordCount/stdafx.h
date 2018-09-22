#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
#include<ctype.h>
#include<algorithm>
#include<map>
#include<vector>


using namespace std;

typedef pair<string, int> PAIR;
struct cmpmap
{
	bool operator()(PAIR& lhs, PAIR& rhs) 
	{
		return lhs.second > rhs.second;
	}
};


class myfile
{
public:
	myfile();
	~myfile();
	void countchar(FILE *f);									//统计字符数
	void countline(FILE *f);									//统计行数
	void countword(FILE *f);									//统计单词数	
	void frequencycount(FILE *f);								//统计出出现次数最多的前十个
	int getchars()												//得到字符数，为单元测试使用
	{
		return chars;
	}
	int getwords()												//得到单词数，为单元测试使用
	{
		return words;
	}
	int getlines()												//得到行数，为单元测试使用
	{
		return lines;
	}
public:
	int chars, lines, words;
};

bool isnum(char c);												//判断是不是数字
bool ischar(char c);											//判断是不是字符

