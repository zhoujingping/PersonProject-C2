#include"WordNum.h"
int WordNum(char * filename)
{
	map<string, int> Word_Num_map;
	char ch;
	int flag = 0;
	int wordnumber = 0;
	FILE *file;
	fopen_s(&file, filename, "r");
	for (; (ch = fgetc(file)) != EOF;)
	{
		if ((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90))//Ó¢ÎÄ×ÖÄ¸
		{
			if (flag >= 0)flag++;
			if (flag < 0)flag--;
		}
		else if (ch >= 48 && ch <= 57)//Êý×Ö
		{
			if (flag >= 4)flag++;
			else flag = -1;
		}
		else //·Ç×ÖÄ¸Êý×Ö·ûºÅ
		{
			if (flag >= 4) { wordnumber++; flag = 0; }
			else { flag = 0; }
		}
	}
	fclose(file);
	return wordnumber;;
}