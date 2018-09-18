#include"pch.h"
#include"readchars.h"
#include<fstream>
using namespace std;


/**********************读取字符*********************/
int readchars(string filename, int file_chars)
{
	ifstream file(filename);
	//FILE *file = _fsopen(filename, "r", _SH_DENYNO);
	if (!file)
	{
		printf( "打开文件错误！" );
		return 0;
	}
	char chars = -1;
	while (1)
	{
		//chars = fgetc(file);
		chars = file.get();
		if (chars == EOF)
			break;
		file_chars++;
	}
	std::ofstream openfile("result.txt", std::ios::trunc);
	openfile << "characters: " << file_chars << endl;
	openfile.close();
	return 0;
}