#include "stdafx.h"


bool isnum(char c)
{
	if (c >= '0' && c <= '9') return true;
	else return false;
}

bool ischar(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
	else return false;
}


myfile::myfile()
{
	chars = 0;
	lines = 0;
	words = 0;
}

void myfile::countchar(FILE *f)
{
	while (getc(f) != EOF)
	{
		chars++;
	}
}

void myfile::countline(FILE *f)
{
	char ch;
	int flag = 0;
	while ((ch = getc(f)) != EOF)								//统计行数
	{
		if (flag == 0 && !isspace(ch)) flag = 1;
		if (ch == '\n' && flag == 1)
		{
			lines++;
			flag = 0;
		}
	}
}

void myfile::countword(FILE  *f)
{
	char ch;
	int flag1 = 1;
	int flag2 = 0;
	int x = 0;
	while ((ch = getc(f)) != EOF)								//读单词写入结构体，并统计单词个数
	{
		if (!isnum(ch) && !ischar(ch)) 							//表示下一个是单词的开始
		{
			if (flag2 == 1)
			{
				words++;
				flag2 = 0;
			}
			x = 0;
			flag1 = 1;
		}
		else if (isnum(ch) && flag2 == 0)											
		{
			flag1 = 0;
		}
		else if (flag1 == 1)
		{														
			x++;
			if (x > 3)	
			{
				flag2 = 1;
			}
		}
	}
}

void myfile::frequencycount(FILE *f)
{
	char ch;
	int states = 0;		
	int x = 0;
	string s;
	map<string, int> word_num_map;
	while ((ch = getc(f)) != EOF)
	{
		switch (states)
		{
			case 0: if (ischar(ch)) { states = 1; s += tolower(ch);}
					else { s = ""; }
					break;
			case 1: if (ischar(ch)) { states = 2; s += tolower(ch); }
					else { s = ""; states = 0; }
					break;
			case 2:if (ischar(ch)) { states = 3; s += tolower(ch); }
				   else { s = ""; states = 0; }
				   break;
			case 3:if (ischar(ch)) { states = 4; s += tolower(ch); }
				   else { s = ""; states = 0; }
				   break;
			case 4:if (ischar(ch) || isnum(ch)) { states = 4; s += tolower(ch); }
				   else { word_num_map[s]++; s = ""; states = 0; }
				   break;
		}
	}
	if (states == 4) word_num_map[s]++;


	vector <PAIR> word_num_vec(word_num_map.begin(), word_num_map.end());
	sort(word_num_vec.begin(), word_num_vec.end(), cmpmap());


	fstream File("result.txt", ios::out);
	File << "characters: " << chars << endl;
	File << "words: " << words << endl;
	File << "lines: " << lines << endl;
	if (word_num_vec.size() < 10)
	{
		for (int i = 0; i != word_num_vec.size(); i++)
		{
			File << "<" << word_num_vec[i].first << ">: " << word_num_vec[i].second << endl;
		}
	}
	else
	{
		for (int i = 0; i != 10; i++)
		{
			File << "<" << word_num_vec[i].first << ">: " << word_num_vec[i].second << endl;
		}
	}
}

myfile::~myfile()
{

}
