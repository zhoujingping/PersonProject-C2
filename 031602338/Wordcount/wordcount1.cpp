#include"wordcount1.h"
#include<string>
#include<regex>
#include<map>
#include<fstream>
int words_number(string txt)//ͳ���ļ��ĵ�������
{
	 int count=0;
	map<string, int>m;
	string content;
	ifstream file(txt);
	regex wordtemplate("^[a-zA-Z]{4}[a-zA-Z0-9]*");//Ҫ�󵥴ʵ�����ʽ
	while (file >> content)
	{

		const std::sregex_token_iterator  end;
		for (sregex_token_iterator wordIter(content.begin(), content.end(), wordtemplate); wordIter != end; wordIter++)
		{
			m[*wordIter]++;//ͳ��ÿ�����ʵĸ�����
		}
		
	}
	map<string, int>::const_iterator pp;

	for (pp = m.begin(); pp != m.end(); pp++)
	{
		count=count+pp->second;
	}
	
	file.clear();
	file.seekg(0);
	return count;

	
}
