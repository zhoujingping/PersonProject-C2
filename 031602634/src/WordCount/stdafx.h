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
	void countchar(FILE *f);									//ͳ���ַ���
	void countline(FILE *f);									//ͳ������
	void countword(FILE *f);									//ͳ�Ƶ�����	
	void frequencycount(FILE *f);								//ͳ�Ƴ����ִ�������ǰʮ��
	int getchars()												//�õ��ַ�����Ϊ��Ԫ����ʹ��
	{
		return chars;
	}
	int getwords()												//�õ���������Ϊ��Ԫ����ʹ��
	{
		return words;
	}
	int getlines()												//�õ�������Ϊ��Ԫ����ʹ��
	{
		return lines;
	}
public:
	int chars, lines, words;
};

bool isnum(char c);												//�ж��ǲ�������
bool ischar(char c);											//�ж��ǲ����ַ�

