#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<fstream>
#include "core.h"
using namespace std;

int main(int argc, char * argv[])//
{
	tjb tj;
	//����һ������fp�ļ�ָ��
	FILE *fp;
	//c�洢ÿ���ַ�
	int c;
	//s�洢�м䵥��
	string s = "";
	int i = 0;
	//������ĿҪ�������ļ���
	int characters = 0, words = 0, lines = 1;
	//count����������ĸ�����Ƿ���4��������ĸ��t��־���ʣ�k�����ʸ���,tt����Ƿ��Ѿ����뵥�ʱ���,p�����ʿ��Լ����ı�־
	int count = 0, t = 0, k = 0, tt = 0, p = 1;
	//path���������ļ�·��
	char *path;
	if (argv[1] != NULL)
	{
		path = argv[1];

	}
	else
	{
		//path = "test.txt";
		path = "input6.txt";
	}
	if ((fp = fopen(path, "r")) == NULL)//�򿪲������ɹ�
	{
		printf("The file can not be opened.\n");
		exit(1);//���������ִ��
	}
	else
	{
		tj.readwj(fp);
		//ͳ���ַ�
		characters = tj.countzf();
		//ͳ������
		lines = tj.counths();
		//ͳ�Ƶ�����
		words = tj.countdc();
		tj.csort();
		printf("characters: %d\n", characters);
		printf("words: %d\n", words);
		printf("lines: %d\n", lines);
		for (int i = 0;i<k;i++)
		{
			//cout << "<" << word[i] << ">��" << wordc[i] << endl;
		}
		tj.write();
		//write(characters, words, lines, word, wordc, k);
	}
	fclose(fp);
	getchar();
	getchar();
	system("pause");
	return 0;
}
