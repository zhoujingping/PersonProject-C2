#include "FileWordCounter.h"
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b)
{
	if (a.first != b.first)return a.first > b.first;
	return a.second < b.second;
}

FileWordCounter::FileWordCounter()
{
	line = 0;
	charNum = 0;
	wordNum = 0;
}


FileWordCounter::~FileWordCounter()
{
}

void FileWordCounter::init(ifstream & in)
{
	if (!in.is_open()) 
	{
		return;
	}
	char ch;
	bool empty = true;
	bool is = true;
	int pos = 0;
	int le = 0;
	while ((ch = in.get()) != EOF) {
		charNum++;
		if (empty&&ch != ' '&&ch != '\t'&&ch!='\n')
		{
			empty = false;
		}
		if (ch == '\n')
		{
			if (!empty)
			{
				line++;
				empty = true;
			}
		}
		if (!isDigit(ch) && !isLetter(ch))
		{
			if (is&&pos>3)
			{
				s[pos] = '\0';
				mp[s]++;
				//s.clear();
				wordNum++;
			}
			is = true;
			pos = 0;
			le = 0;
		}
		else
		{
			if (isDigit(ch))
			{
				if (is)
				{
					s[pos++] = ch;
					//pos++;
					//s.append(1, ch);
					if (pos == 4 && le != 4)
					{
						is = false;
					}
				}
			}
			else
			{
				if (is)
				{
					if (ch >= 'A'&&ch <= 'Z')
					{
						ch -= 'A' - 'a';
					}
					s[pos++] = ch;
					//s.append(1, ch);
					//pos++;
					le++;
					if (pos == 4 && le != 4)
					{
						is = false;
					}
				}
			}
		}
	}
	if (!empty)
	{
		line++;
		empty = true;
	}
	if (is&&pos>3)
	{
		s[pos] = '\0';
		mp[s]++;
	}
	is = true;
	pos = 0;
	le = 0;
}

int FileWordCounter::getLine()
{
	return line;
}

int FileWordCounter::getCharNum()
{
	return charNum;
}

int FileWordCounter::getWordNum()
{
	return wordNum;
}

bool FileWordCounter::isDigit(char ch)
{
	if ((int)ch < 0||(int)ch>255)return false;
	if (ch >= '0'&&ch <= '9')return true;
	return false;
}

bool FileWordCounter::isLetter(char ch)
{
	if ((int)ch < 0 || (int)ch>255)return false;
	if (ch >= 'a'&&ch <= 'z')return true;
	if (ch >= 'A'&&ch <= 'Z')return true;
	return false;
}

vector<pair<int, string>> FileWordCounter::getVe()
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
	for (int i = 0; i < min(10,(int)ve.size()); i++)
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
