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
	//定义一个名叫fp文件指针
	FILE *fp;
	//c存储每个字符
	int c;
	//s存储中间单词
	string s = "";
	int i = 0;
	//都是题目要求的输出的计数
	int characters = 0, words = 0, lines = 1;
	//count计数单词字母个数是否有4个以上字母，t标志单词，k代表单词个数,tt标记是否已经存入单词表中,p代表单词可以计数的标志
	int count = 0, t = 0, k = 0, tt = 0, p = 1;
	//path变量报错文件路径
	char *path;
	if (argv[1] != NULL)
	{
		path = argv[1];

	}
	else
	{
		path = "test.txt";
		//path = "input6.txt";
	}
	if ((fp = fopen(path, "r")) == NULL)//打开操作不成功
	{
		printf("The file can not be opened.\n");
		exit(1);//结束程序的执行
	}
	else
	{
		tj.readwj(fp);
		words = tj.countdc();
		//统计字符
		characters = tj.countzf();
		//统计行数
		lines = tj.counths();
		//统计单词数
		words = tj.countdc();
		tj.csort();
		printf("characters: %d\n", characters);
		printf("words: %d\n", words);
		printf("lines: %d\n", lines);
		for (int i = 0;i<k;i++)
		{
			//cout << "<" << word[i] << ">：" << wordc[i] << endl;
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
