#include "LineNum.h"
int LineNum(char * filename)
{
	char ch;
	int flag = 0;
	int linenumber = 0;
	FILE *file;
	fopen_s(&file, filename, "r");
	for (; (ch = fgetc(file)) != EOF;)
	{
		if (ch == '\n')
		{
			if (flag > 0)linenumber++;
			flag = 0;
		}
		else if (ch != ' '&&ch != '\t')
		{
			flag++;
		}

	}if (flag > 0)linenumber++;
	fclose(file);
	return  linenumber;
}