#include<string>
#include"FileWordCounter.h"

using namespace std;
int min(int a, int b)
{
	if (a < b)return a;
	else return b;
}
int main(int argc, char* argv[])
{
	if (argc == 0)
	{
		cout << "System Error!" << endl;
	}
	else if (argc == 1)
	{
		cout << "do nothing" << endl;
	}
	else if (argc == 2)
	{
		ifstream in;
		in.open(argv[1]);
		
		if (in.is_open())
		{
			FileWordCounter fwc;
			ofstream out;
			out.open("result.txt");
			if (!out.is_open())
			{
				cout << "output open failed" << endl;
				return -1;
			}
			fwc.init(in);
			out << "characters: " << fwc.getCharNum() << endl;
			vector<pair<int,string> > v = fwc.getVe();
			out << "words: " << fwc.getWordNum()<< endl;
			out << "lines: " << fwc.getLine() <<endl;
			for (int i = 0; i < min(v.size(),10); i++)
			{
				out << "<" << v[i].second << ">: " << v[i].first << endl;
			}
		}
		else
		{
			cout << "input open fail" << endl;
		}
		
	}
	else
	{
		cout << "do nothing" << endl;
	}
	return 0;
}