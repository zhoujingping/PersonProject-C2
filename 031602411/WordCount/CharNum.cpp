#include "CharNum.h"
int CharNum(char * filename)
{
	char ch;
	int chnumber = 0;//�����ַ���
	FILE *file;
	fopen_s(&file, filename, "r");
	for (; fgetc(file) != EOF;) {
		chnumber++;
	}
	fclose(file);
	return chnumber;
}