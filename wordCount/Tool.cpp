#include "Tool.h"
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

Tool::Tool()
{
	CharNum = 0;
	WordNum = 0;
	Lines = 0;
}
Tool::~Tool()
{

}

bool cmp(pair<int, string> a, pair<int, string> b)

{

	if (a.first != b.first)return a.first > b.first;

	return a.second < b.second;

}

bool Tool::isDigit(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Tool::isEng(char ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool Tool::isBEng(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		return true;
	}
	else
	{
		return false;
	}
}

char Tool::lowEng(char ch)
{
	ch = ch + 'a' - 'A';
	return ch;
}

void Tool::init(ifstream& txt)
{
	char ch;
	bool empty = true;
	string s;

	if (!txt.is_open())
	{
		return;
	}



	while ((ch = txt.get()) != EOF)
	{
		CharNum++;
		bool flag = true;
		bool isDOE = false;

		if (isBEng(ch))
		{
			ch=lowEng(ch);
		}

		if (empty && ch != ' ' && ch != '\n' && ch != '\t')
		{
			empty = false;
		}
		if (ch == '\n')
		{
			if (!empty)
			{
				Lines++;
				empty = true;
			}
		}
		
		if ((!isDigit(ch)) && (!isEng(ch)) && flag)
		{
			if (s.length() >= 4)
			{
				for (int i = 0; i < 4; i++)
				{
					if (!isEng(s[i]))
					{
						flag = false;
						break;
					}
					else
					{
						flag = true;
					}
				}
				if (flag == true)
				{

					mp[s]++;
					WordNum++;
					//cout << s << endl;
				}
				flag = true;
			}
			s.clear();
		}

		if ((isDigit(ch) || isEng(ch) )&& !isDOE)
		{
			isDOE = true;
		}

		if (isDOE)
		{
			if (isDigit(ch) || isEng(ch))
			{
				s = s + ch;
			}
			else
			{
				isDOE = false;
			}
			
		}
		
	}
	if (!empty)
	{
		Lines++;
		empty = true;
	}
}

int Tool::GetCharNum()
{
	return CharNum;
}

int Tool::GetLines()
{
	return Lines;
}

int Tool::GetWordNum()
{
	return WordNum;
}

vector<pair<int, string>> Tool::GetVe()

{

	unordered_map<string, int>::iterator it;

	vector<pair<int, string> > ve;

	vector<pair<int, string> > re;

	for (it = mp.begin(); it != mp.end(); it++)

	{

		ve.push_back(make_pair(it->second, it->first));

	}

	//sort(ve.begin(), ve.end(), cmp);



	pair<int, string> ma;

	int pos = 0;
	int len = ve.size();
	for (int i = 0; i < min(10, len); i++)

	{

		ma = ve[0];

		pos = 0;


		for (int j = 1; j < (int)ve.size(); j++)

		{

			if (cmp(ve[j], ma)) {

				ma = ve[j];

				pos = j;

			}

		}

		re.push_back(ma);

		ve.erase(ve.begin() + pos);

	}



	return re;

}