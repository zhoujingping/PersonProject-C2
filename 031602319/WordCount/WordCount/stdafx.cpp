#include "stdafx.h"
//���캯������ʼ���ļ������
File::File()
{
	charcount = 0;
	line = 0;
	wordscount = 0;
}
//�����ļ�,ͳ���������ַ���
void File::Infile(string filename)
{
	ifstream infile(filename, ios::in|ios::_Nocreate );
	if (!infile)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	string s;
	while (getline(infile, s))
	{
		charcount += s.length();
		line++;
		Wordscount(s);
	}
	charcount += line;
	infile.close();
}

//ʵ���ļ����ʸ���ͳ�ƣ��������е��ʣ������ظ�������һ��string��list
void File::Wordscount(string filename)
{
	//ifstream infile(filename, ios::in | ios::_Nocreate);
	//if (!infile)
	//{
		//cerr << "open error!" << endl;
		//exit(1);
	//}
	smatch m;
	//string s;
	string s1;
	regex r("[a-zA-Z]{4}[0-9a-zA-Z]*");
	//while (getline(infile, filename))
	//{
		while (regex_search(filename, m, r))
		{
			s1 = m.str();
			transform(s1.begin(), s1.end(), s1.begin(), tolower);
			words.push_back(s1);
			wordscount++;
			filename = m.suffix().str();
		}
	//}
	//infile.close();
}

//�����ʵ�list���ֵ���������������ʼ�����ֵĸ������뵥�ʶ��󣬲�����һ����list��֮��ȥ������list���ظ��ĵ��ʡ�
void File::Wordsway()
{
	List::iterator i, j;
	if (!words.empty())
	{
		words.sort();
		string s;
		int k;
		for (i = words.begin(); i != words.end(); ++i)
		{
			Word *w = new Word;
			s = *i;
			w->name = s;
			k = 1;
			for (j = ++i; j != words.end(); ++j)
			{
				if (s == *j)
					k++;
				else
					break;
			}
			w->count = k;
			i = --j;
			words_count.push_back(*w);
		}
		words.unique();
	}
	else
		cout << "words list��ûԪ��";
}
//�����������ļ�
void File::Outfile()
{
	ofstream outfile("result.txt");
	/*if (!outfile)
	{
		cerr << "open error!" << endl;
		exit(1);
	}*/
	outfile << "characters: " << charcount << endl;
	outfile << "words: " << wordscount << endl;
	outfile << "lines: " << line << endl;
	string s;
	Wordlist::iterator i;
	words_count.sort();
	if (!words_count.empty())
	{
		string s;
		int k = 0;
		for (i = words_count.begin(); i != words_count.end(); ++i)
		{
			k++;
		    outfile << "<" << i->name << ">: " << i->count << endl;
			if (k == 10)
				break;
		}
	}
	else
	{
		cout << "words_count list��ûԪ��";
	}
	outfile.close();
}
File::~File()
{
}