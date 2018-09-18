#include"pch.h"
#include"readword.h"
#include<fstream>

using namespace std;

/****************************≈≈–Ú***********************/
int sort(map<string,int> words_m)
{
	
	/*struct word *q;
	struct word *a[10];
	struct word *q1 = new word;
	int i;
	char s[30] = { 0 };
	for (i = 0;i < 10;i++)
	{
		a[i] = new word;
		a[i]->num = 0;
		strcpy_s(a[i]->name, s);
	}
	for (i = 0;i < 10;i++)
	{
		q = head->next;
		while (q != NULL)
		{
			if (q->num == a[i]->num)
			{
				if (_stricmp(q->name, a[i]->name) < 0)
				{
					strcpy_s(a[i]->name, q->name);
					a[i]->num = q->num;
					q1 = q;
				}
			}
			else if (q->num > a[i]->num)
			{
				strcpy_s(a[i]->name, q->name);
				a[i]->num = q->num;
				q1 = q;
			}
			q = q->next;
		}
		q1->num = 0;
	}
	for (i = 0;i < 10;i++)
	{
		if (a[i]->num != 0)
		{
			std::ofstream openfile("result.txt", std::ios::app);
			openfile << "<" << a[i]->name << ">:" << a[i]->num << endl;
			openfile.close();
		}
	}*/
	int i = 0;
	int a[10];
	string b[10];
	for (i = 0;i < 10;i++)
	{
		a[i] = 0;
		b[i] = '0';
	}
	for (i = 0;i < 10;i++)
	{
		map<string, int>::iterator iter;
		for (iter = words_m.begin(); iter != words_m.end(); iter++)
		{
			if (a[i] < iter->second)
			{
				b[i] = iter->first;
				a[i] = iter->second;
			}
			else if (a[i] == iter->second)
			{
				if (cmp(b[i], iter->first) < 0)
				{
					b[i] = iter->first;
					a[i] = iter->second;
				}
			}

		}
		words_m[b[i]] = 0;
		const char *b_str = b[i].c_str();
		std::ofstream openfile("result.txt", std::ios::app);
		openfile << "<" << b_str << ">: " << a[i] << endl;
		openfile.close();
		
	}
	
	return 0;
}