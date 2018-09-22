#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include<regex>
#include<list>
using namespace std;
typedef list<string> List;

//���ֵ��ʼ�����ָ�������
class Word
{
public:
	string name;
	int count;
	bool operator < (Word& w1)//����<�����
	{
		return count > w1.count;
	}
};
typedef list<Word> Wordlist;
//�ļ��࣬ʵ�ָ�������ļ��Ĳ���
class File
{
public:
	File();
	~File();
	void Infile(string filename);
	void Outfile();
	void Wordscount(string filename);
	void Wordsway();
private:
	int charcount;
	int wordscount;
	int line;
	List words;
	Wordlist words_count;
};