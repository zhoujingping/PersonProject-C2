#include "charcount1.h"
#include <string>
#include<fstream>
int characters_number(string txt)//统计文件的字符数
{
  
	int count = 0;
	char content;
	ifstream file(txt);
	while (!file.eof())//直到文件结尾，依次逐字符读入
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
