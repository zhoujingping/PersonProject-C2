#include "pch.h"
#include"work_2.h"

int Text::countchar(ifstream *infile, ofstream *outfile)//ͳ���ַ���
{
	char a;
	while ((*infile).get(a))//�ַ���ȡ���ɹ�����ֹ
	{
			count_char++;
		allstring += a;//��ÿ���ַ�����all_string
	}
	//cout << "characters: " << count_char << endl;
	*outfile << "characters: " << count_char << endl;//�������result.txt�ļ�
	return count_char;
}