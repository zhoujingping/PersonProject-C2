#include "pch.h"
#include"work_2.h"
int Text::countline(ofstream *outfile)//ͳ������
{
	int flag = 0;
	int len = allstring.length();//�ı�����
	for (int i = 0; i < len; i++)
	{
		if (allstring[i] >= 33 && allstring[i] <= 126)//��ʾ��������Ч��
		{
			flag = 1;
			continue;
		}
		if (allstring[i] == '\n'&&flag == 1)//����������Ч�У����ұ�����1�����з�ʱ��������1
		{
			count_line++;
			flag = 0;
		}
	}
	if (flag == 1)//���һ�����û�л��з���ҲҪ��1
		count_line++;

	//cout << "lines: " << count_line << endl;
	*outfile << "lines: " << count_line << endl;//�������result.txt�ļ�
	return count_line;
}