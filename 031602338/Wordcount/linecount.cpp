#include"linecount.h"
#include<string>
#include<fstream>
int lines_number(string txt)//ͳ���ļ���Ч����
{
	unsigned int  i;
	int count = 0;
	string content;
	ifstream file(txt);

	while (getline(file, content))//ֱ���ļ���β���������ж����ı�
	{

		for (i = 0; i < content.length(); i++)
		{
			if (content[i] != '\n'&& content[i] != '\t' && content[i] != ' '&&content[i] != '\r')
			{
				count++;
				break;
			}
		}
	}
	
	file.clear();
	file.seekg(0);
	return count;
	
}