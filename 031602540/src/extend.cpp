#include "pch.h"
#include <iostream>
#include<map>
#include<string>
#include<stdio.h>
#include"extend.h"
using namespace std;
Zsn::Zsn(string name)
{
	fname = name;
}
int Zsn::charact()
{
	FILE *fin;
	int countcharact = 0;
	char achar;
	fopen_s(&fin, fname.c_str(), "r");
	int getchar = fread(&achar, sizeof(char), 1, fin);
	while (getchar)
	{
		countcharact++;
		getchar = fread(&achar, 1, 1, fin);
	}
	fclose(fin);
	FILE *fo;
	fopen_s(&fo, "result.txt", "w");
	char characters[50];
	sprintf_s(characters,"characters: %d\n", countcharact);
	fwrite(characters, strlen(characters), 1, fo);
	fclose(fo);
	return countcharact;
}
int Zsn::line()
{
	FILE *fin;
	int countline = 0;
	char achar;
	bool isline = false;
	fopen_s(&fin, fname.c_str(), "r");
	int getchar = fread(&achar, 1, 1, fin);
	while (getchar)
	{
		if (achar >= 33)	isline = true;
		if (achar == '\n'&&isline == true)
		{
			countline++;
			isline = false;
		}
		getchar = fread(&achar, 1, 1, fin);
	}
	if (isline == true)
	{
		countline++;
		isline = false;
	}
	fclose(fin);
	FILE *fo;
	fopen_s(&fo, "result.txt", "a+");
	char lines[50];
	sprintf_s(lines,"lines: %d\n", countline);
	fwrite(lines, strlen(lines), 1, fo);
	fclose(fo);
	return countline;
}
int Zsn::word()
{

	FILE *fin;
	int countword = 0;
	char achar;
	bool wordjudge = false;
	fopen_s(&fin, fname.c_str(), "r");
	int i = 0, j = 0;
	int getchar = fread(&achar, 1, 1, fin);
	while (getchar)
	{
		if ((achar <= 57 && achar >= 48) || (achar >= 65 && achar <= 90) || (achar >= 97 && achar <= 122))//
		{
			j++;
			if ((achar >= 65 && achar <= 90) || (achar >= 97 && achar <= 122))
			{
				i++;
			}
			if (j == 4 && i == 4)
			{
				wordjudge = true;
			}//ÅÐ¶ÏÊÇ·ñÎªµ¥´Ê 

		}
		else
		{
			if (wordjudge == true)
			{
				countword++;
				wordjudge = false;
			}
			i = j = 0;
		}
		getchar = fread(&achar, 1, 1, fin);
	}
	if (wordjudge == true)
	{
		countword++;
		wordjudge = false;
		i = j = 0;
	}
	fclose(fin);
	FILE *fo;
	fopen_s(&fo, "result.txt", "a+");
	char words[50];
	sprintf_s(words, "words: %d\n", countword);
	fwrite(words,strlen(words),1,fo);
	fclose(fo);
	return countword;
}
void Zsn::top10()
{
	FILE *fin;
	char achar;
	bool wordjudge = false;
	char ex[2];
	char word[100];memset(word, '\0', 100);
	fopen_s(&fin, fname.c_str(), "r");
	map<string, int>map1;
	int i = 0, j = 0;
	int getchar = fread(&achar, 1, 1, fin);
	while (getchar)
	{
		if ((achar <= 57 && achar >= 47) || (achar >= 65 && achar <= 90) || (achar >= 97 && achar <= 122))//
		{
			++j;
			if ((achar >= 65 && achar <= 90) || (achar >= 97 && achar <= 122))
			{
				if (achar >= 65 && achar <= 90)
				{
					achar += 32;
				}
				i++;
			}
			if (j == 4 && i == 4)
			{
				wordjudge = true;
			}//ÅÐ¶ÏÊÇ·ñÎªµ¥´Ê 
			memset(ex, '\0', 2);
			ex[0] = achar;
			strcat_s(word, strlen(word) + strlen(ex) + 1, ex);
		}
		else
		{
			if (wordjudge == true)
			{
				if (!map1[word])
				{
					map1[word] = 1;
				}
				else
				{
					map1[word]++;
				}
				wordjudge = false;
			}
			i = j = 0;
			memset(word, '\0', 100);
		}
		getchar = fread(&achar, 1, 1, fin);
	}
	if (wordjudge == true)
	{
		if (!map1[word])
		{
			map1[word] = 1;
		}
		else
		{
			map1[word]++;
		}
		wordjudge = false;
	}
	fclose(fin);
	//ÅÅÐò
	map<string, int>::iterator iter1;
	map<string, int>::iterator iter2;

	iter1 = map1.begin();

	char wordf[100];
	FILE *fo;
	fopen_s(&fo,"result.txt","a+");
	for (i = 1;i <= 10;i++)
	{

		if (map1.size() < i) break;
		for (iter2 = map1.begin();iter2 != map1.end();iter2++)
		{
			if (iter2->second > iter1->second)
			{
				iter1 = iter2;
			}
		}
		sprintf_s(wordf,"<%s>: %d\n", iter1->first.c_str(),iter1->second);
		fwrite(wordf,strlen(wordf),1,fo);
		iter1->second = 0;
		iter1 = map1.begin();
	}
	fclose(fo);
}