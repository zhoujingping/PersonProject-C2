#include "pch.h"
#include"work_2.h"
int Text::countword(ofstream *outfile)//ͳ�Ƶ�����
{
	int flag = 0;
	string temp = "";
	int len = allstring.length();
	for (int i = 0; i < len; i++)
	{
		if ((allstring[i] >= 65 && allstring[i] <= 90) || (allstring[i] >= 97 && allstring[i] <= 122))//�ҵ���һ����ĸ  �ж��ǲ��ǵ���
		{
			flag = 0;
			for (int j = i; j <= i + 3; j++)//�ж��ǲ���ƥ�䵥��
			{
				if (allstring[j] <= 64 || (allstring[j] >= 91 && allstring[j] <= 96) || allstring[j] >= 123 || len - i < 4)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)//����ǵ��ʾ���ȡ���ʵ�temp
			{
				temp = "";
				for (; i < len && ((allstring[i] >= 65 && allstring[i] <= 90) || (allstring[i] >= 97 && allstring[i] <= 122) || (allstring[i] >= 48 && allstring[i] <= 57)); i++)
				{
					if (allstring[i] >= 65 && allstring[i] <= 90)
						allstring[i] += 32;
					temp += allstring[i];
				}
				count_word++;
				//cout << temp << endl;
				Text::insert(temp);
			}
			else//������ǵ��ʾ�������һ�����ʵĵ�һ����ĸ
			{
				for (; (allstring[i] >= 65 && allstring[i] <= 90) || (allstring[i] >= 97 && allstring[i] <= 122 || (allstring[i] >= 48 && allstring[i]<=57)); i++) {}
			}
		}
		else if (allstring[i] >= 48 && allstring[i] <= 57)
		{
			for (; (allstring[i] >= 65 && allstring[i] <= 90) || (allstring[i] >= 97 && allstring[i] <= 122) || (allstring[i] >= 48 && allstring[i] <= 57); i++) {}
		}
	}

	//cout << "words: " << count_word << endl;
	*outfile << "words: " << count_word << endl;//ͳ�Ƶ��ʸ���
	return count_word;
}