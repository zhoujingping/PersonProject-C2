#include"pch.h"
#include"readword.h"
#include<fstream>
#include<stdlib.h>
#include<string>

using namespace std;


/**********************读取文件中单词*********************/

int max1(int a, int b)
{
	if (a > b)
		return a;
	else return b;
}
int cmp(string a, string b)
{
	int size = max1(a.length(), b.length());
	for (int i = 0;i < size;i++)
	{
		if (a[i] < b[i])
			return 1;
		else if (a[i] > b[i])
			return -1;
	}
	if (size = a.length())
		return 1;
	else return -1;
}




map<string,int> readword(map<string, int> words_m,string filename, int word_num)
{
	int i = 0;
	//FILE *fp _fsopen(filename, "r", _SH_DENYNO);
	ifstream file(filename);

	if (!file)
	{
		printf("无法打开此文件!\n");
		exit(0);
	}
	char ch, b_chars[30];
	
	while (1)
	{
		i = 0;
		ch = file.get();
		if (ch == EOF)
			break;
		if (ch >= 'A'&&ch <= 'Z')
		{
			ch += 32;
		}
		while ((ch >= 'a'&&ch <= 'z')|| (ch >= '0'&&ch <= '9'))
		{
			b_chars[i] = ch;
			i++;
			ch = file.get();
			if (ch >= 'A'&&ch <= 'Z')
			{
				ch += 32;
			}
			if (ch==EOF) break;
		}
		b_chars[i] = '\0';
		if (((b_chars[0] <= 'z') && (b_chars[0] >= 'a')) )
		{
			if (((b_chars[1] <= 'z') && (b_chars[1] >= 'a')))
			{
				if (((b_chars[2] <= 'z') && (b_chars[2] >= 'a')))
				{
					if (((b_chars[3] <= 'z') && (b_chars[3] >= 'a')))
					{
						word_num++;
						if (words_m.find(b_chars) == words_m.end())
						{
							words_m[b_chars] = 1;
						}
						else
							words_m[b_chars]++;
						
					}
				}
			}
		}
		/*if (flag == 1 && b_chars[0] != '\0')
		{
			while (b_chars[i])
			{
				if (b_chars[i] >= 'A'&&b_chars[i] <= 'Z')
				{
					b_chars[i] += 32;
				}
				i++;
			}
		}
		p = head->next;
		struct word *q = new word;
		q->next = NULL;
		if (flag == 1 && b_chars[0] != '\0')
		{
			for (int j = 1;j < z;j++)
			{
				if (chars[j]->name[0]== b_chars[0])
				{
					flag1 = j;
					break;
				}
			}
			if (flag1!=0)
			{
				strcpy_s(q->name, b_chars);
				q->num = 1;
				q->next = chars[flag1]->next;
				chars[flag1]->next = q;
			}
			else
			{
				strcpy_s(q->name, b_chars);
				q->num = 1;
				q->next = head->next;
				head->next = q;
				chars[z] = new word;
				chars[z] = q;
				z++;

			}
		}
		flag1 = 0;
		flag = 0;

	}
	printf("单词录入完毕！\n");
	/*struct word* p1 = new word;
	p = head->next;
	while (p)
	{
		p1 = p->next;
		if (p->num != 0)
		{
			while (p1 != NULL)
			{
				if (p1->name[0] == p->name[0])
				{
					if (p1->num != 0)
					{
						if (!cmp(p->name, p1->name))
						{
							p->num++;
							p1->num = 0;
						}
					}
					p1 = p1->next;
				}
				else
					break;
			}
		}
		p = p->next;
	}*/
	}
	std::ofstream openfile("result.txt", std::ios::app);
	openfile << "words: " << word_num << endl;
	openfile.close();
	return words_m;
}


