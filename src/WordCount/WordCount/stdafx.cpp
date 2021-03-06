// stdafx.cpp : 只包括标准包含文件的源文件
// WordCount.pch 将作为预编译标头
// stdafx.obj 将包含预编译类型信息
#include "stdafx.h"

// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用

bool cmp(const pair<string, int> &n1, const pair<string, int> &n2) 
{
	if (n1.second == n2.second)
		return n1.first < n2.first;
	else
		return n1.second > n2.second;
}
Word::Word()
{
	mapword.clear();
	//初始化
	linesnum = 0;
	characters = 0;
	words = 0;
	initans = 0;//代表是否进行过初始化
}
int Word::init(char *argv)
{
	map<string, int>::iterator iter;
	__int64 wordpos = 0,answord = 0;
	FILE *Fileread;
	char word;
	string str;
	bool anslint = 0, trueword = 1;
	freopen_s(&Fileread, argv, "rb", stdin);
	if (Fileread == NULL)
	{
		printf("file isn't exist\n");
		return -1;
	}

	while (word = getchar())
	{
		if (word == -1)
			break;
		fileword.append(1, word);
		if (anslint == 1&& word == '\n')
		{
			anslint = 0;
			linesnum++;
		}
		if (word != 0x9 && word != 0xd && word != 0xa && word != 0x20)
		{
			anslint = 1;//标记； 
		}
		if (97 <= word && word <= 122)
		{	
			answord++;
		}
		else if (65 <= word && word <= 90)
		{		
			fileword[characters] += 32;//大小写转化
			answord++;
		}
		else if ('0' <= word && word <= '9')
		{
			if (answord <4)
				trueword = 0;
		}
		else
		{
			if (answord >= 4 && trueword==1)
			{
				str = fileword.substr(wordpos, (const unsigned int)characters - wordpos);
				mapword[str]++;
				//取词
				words++;
			}
			wordpos = (1+characters);
			answord = 0;
			trueword = 1;
		}
		characters++;
		//统计字符数 	
	}
	if (answord >= 4 && trueword == 1)
	{
		str = fileword.substr(wordpos, (const unsigned int)characters - wordpos);
		mapword[str]++;
		//取词
		words++;
	}
	fclose(Fileread);
	//初始化完成；
	initans = 1;
	return 0;
}
int Word::Countlines(char *argv)
{
	//统计非空白行
	if (!initans)
		init(argv);
	return linesnum;
}
int Word::Countwords(char *argv)
{
	if (!initans)
		init(argv);
	return words;
}
int Word::Countcharacters(char *argv)
{
	//统计ascll码的数量
	if (!initans)
		init(argv);
	return characters;
}
vector<pair<string, int>> Word::Counttop10(char *argv)
{
	__int64 num;
	vector<pair<string, int>>top(mapword.begin(), mapword.end()),top10;
	sort(top.begin(), top.end(), cmp);
	num = 0;
	for(int i=0;i < top.size() ; i++ )
	{
		num++;
		top10.insert(top10.end(),top[i]);
		if (num == 10)
			break;
	}
	return top10;
}
File::File() {}
int File::FileTest(char *argv[])
{
	if (argv[1] == NULL)
	{
		printf("no file\n");
		return 0;
	}
	else if (argv[2] != NULL)
	{
		printf("too much\n");
		return 0;
	}
	fstream Fileread;
	Fileread.open(argv[1], std::ios::in);
	if (Fileread.fail())
	{
		printf("file isn't exist\n");
		return 0;
	}
	Fileread.close();
	return 1;
}