#include "charcount1.h"
#include <string>
#include<fstream>
int characters_number(string txt)//ͳ���ļ����ַ���
{
  
	int count = 0;
	char content;
	ifstream file(txt);
	while (!file.eof())//ֱ���ļ���β���������ַ�����
	{
		content = file.get();
		if (content >= 0 && content <= 255)
		{
			count++;
		}
	}
	file.clear();
	file.seekg(0);
	return count;

}
