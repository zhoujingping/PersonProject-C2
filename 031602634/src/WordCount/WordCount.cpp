#include "stdafx.h"


int main(int argc, char *argv[])
{
	FILE *inf;
	fopen_s(&inf, argv[1], "r");								//从文本中读出单词
	if (inf == NULL)
	{
		cout << "error" << endl;
		system("pause");
		return 0;
	}

	myfile f;
	f.countchar(inf);
	rewind(inf);												
	f.countline(inf);
	rewind(inf);
	f.countword(inf);
	rewind(inf);
	f.frequencycount(inf);
	

	return 0;
}

