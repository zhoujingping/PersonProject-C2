#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cctype>
#include<regex>
#include<io.h>
#include<unordered_map>
#include<iterator>
#include "WordCount.h"
#include"Tool.h"
using namespace std;

int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main(int argc, char* argv[])
{
	if (argc == 2)
	{

		ofstream SaveFile(argv[1], ios::app);
		SaveFile << "\t";
		SaveFile.close();

		ifstream txt;
		txt.open(argv[1]);

		if (txt.is_open())
		{
			Tool tl;
			ofstream out;
			out.open("result.txt");
			if (!out.is_open())
			{
				cout << "The result.txt is close!" << endl;
				return -1;
			}
			tl.init(txt);
			out << "characters: " << tl.GetCharNum() - 1 << endl;
			vector<pair<int, string> > v = tl.GetVe();
			out << "words: " << tl.GetWordNum() << endl;
			out << "lines: " << tl.GetLines() << endl;
			for (int i = 0; i < min(v.size(), 10); i++)
			{
				out << "<" << v[i].second << ">: " << v[i].first << endl;
			}
		}
		else
		{
			cout << "Input does not open!" << endl;
		}
	}
	else
	{
		cout << "Please makesure the input is correct!" << endl;
	}
}