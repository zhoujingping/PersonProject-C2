#include "stdafx.h"

int main()
{
	cout << "����Ҫд����ļ�·�����ļ�����" << endl;
	string filename;
	cin >> filename;
	File f;
	f.Infile(filename);
	f.Wordscount(filename);
	f.Wordsway();
	//cout << "����Ҫ��ȡ���ļ�·�����ļ�����" << endl;
	//cin >> filename;
	f.Outfile();
	system("pause");
	return 0;
}