#include"Word_Fre.h"
typedef pair<string, double> PAIR;
bool CmpByValue(const PAIR& lhs, const PAIR& rhs)
{
	return (lhs.second != rhs.second) ? lhs.second > rhs.second : lhs.first < rhs.first;
}
int Word_Fre(char * filename)
{
	map<string, int> Word_Num_map;
	char ch;
	string word;
	int flag = 0;
	FILE *file;
	fopen_s(&file, filename, "r");
	for (; (ch = fgetc(file)) != EOF;)
	{
		if ('A' <= ch && ch <= 'Z')
			ch = ch + 32;
		if (ch >= 'a' && ch <= 'z')//Ó¢ÎÄ×ÖÄ¸
		{
			if (flag >= 0) { flag++; word = word + ch; }
			if (flag < 0) { flag = 0; word = ""; }
		}
		else if (ch >= 48 && ch <= 57)//Êý×Ö
		{
			if (flag >= 4) { flag++; word = word + ch; }
			else { flag = 0; word = ""; }
		}
		else //·Ç×ÖÄ¸Êý×Ö·ûºÅ
		{
			if (flag >= 4)
			{
				Word_Num_map[word]++;

				word = "";
				flag = 0;

			}
			else { flag = 0; word = ""; }
		}


	}
	if (flag >= 4)
	{
		Word_Num_map[word]++;
	}
	vector <PAIR> Word_Num_vec(Word_Num_map.begin(), Word_Num_map.end());
	sort(Word_Num_vec.begin(), Word_Num_vec.end(), CmpByValue);
	ofstream outfile("result.txt", ios::out);
	if (Word_Num_vec.size() < 10)
		for (int i = 0; i != Word_Num_vec.size(); ++i) {
			const char *ss = Word_Num_vec[i].first.c_str();
			cout << '<' << ss << '>' << ":" <<' '<< Word_Num_vec[i].second << endl;
		}
	else
		for (int i = 0; i != 10; ++i) {
			const char *ss = Word_Num_vec[i].first.c_str();
			cout << '<' << ss << '>' << ":" <<' '<< Word_Num_vec[i].second << endl;
		}
	return 0;
}