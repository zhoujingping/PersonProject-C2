#pragma once
#include "pch.h"
#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;

struct node { //����ṹ��
	string word;//������
	int times;//���ʳ���Ƶ��
	node *next;
	node(string w, int number) //���캯��
	{
		word = w;
		times = number;
		next = NULL;
	}
};
class Text {
private:
	string allstring;//�����ı�������
	int count_char;//�ַ�����
	int count_word;//���ʸ���
	int count_line;//����
	node *hash_table[18280];//��ϣ��
public:
	Text()//���캯��
	{
		allstring = "";
		count_char = 0;
		count_word = 0;
		count_line = 0;
		for (int i = 0; i <= 18279; i++)//��ʼ�������ṹ��ָ������
			hash_table[i] = new node("", 0);
	}
	int countchar(ifstream *infile, ofstream *outfile);//ͳ���ַ�����
	int countword(ofstream *outfile);//ͳ�Ƶ��ʸ���
	int countline(ofstream *outfile);//ͳ������
	void rank(ofstream *outfile);//ͳ�Ƴ���Ƶ������10������
	void insert(string w);//��ÿ�����ʲ����ϣ��
};