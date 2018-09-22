#include "pch.h"
#include"work_2.h"
void Text::insert(string w)//�ѵ��ʲ����ϣ��
{
	int hash = ((w[0] - 96)) + ((w[1] - 96) * 26) + ((w[2] - 96) * 26 * 26);//�����ϣֵ
	node *p = new node("", 1);
	node *q = new node("", 1);
	if (hash_table[hash]->next == NULL)//�ձ����
	{
		p = hash_table[hash];
		hash_table[hash] = new node(w, 1);
		hash_table[hash]->next = p;
	}
	else//�ǿձ�
	{
		int flag = 0;
		q = p = hash_table[hash];
		while (p->next != NULL)//��������
		{
			if (p->word == w)//�ڱ����ҵ��õ��ʣ�����times��1
			{
				p->times++;
				flag = 1;
			}
			q = p;
			p = p->next;
		}
		if (flag == 0)//��������û���ҵ��õ��ʣ���������β�������½��
		{
			node *newnode = new node(w, 1);
			q->next = newnode;
			newnode->next = p;
		}
	}
	return;
}

void Text::rank(ofstream *outfile)//ͳ�ƴ�Ƶ
{
	int num;
	int flag = 0;//�жϳ��ִ������Ľ���ǲ��Ǳ��� 0���� 1��
	node *max, *q, *p, *front_max;
	front_max = new node("", 0);
	for (int j = 0; j < 10 && j < count_word; j++)//����10�ι�ϣ��
	{
		max = new node("", 0);//��ʼ��max
		for (int i = 0; i <= 18279; i++)
		{
			if (hash_table[i]->next == NULL) continue;//�ձ�����
			else//�ǿձ�
			{
				q = p = hash_table[i];
				while (p->next != NULL)
				{
					if (p->times > max->times || (p->times == max->times&&p->word < max->word))
					{

						if (p == hash_table[i])
						{
							flag = 1;//��ʾ�õ����ڱ�ͷ
							num = i;
						}
						else flag = 0;//��ʾ�õ����ڱ���
						max = p;
						front_max = q;
					}
					q = p;
					p = p->next;
				}
			}
		}
		if (max->times != 0)
		{
			//cout << "<" << max->word << ">: " << max->times << endl;//���һ�����
			*outfile << "<" << max->word << ">: " << max->times << endl;//���һ�����
		}
		else  break;//���maxû�б��滻�����ʱ��ϣ���ǿյģ�����Ҫ���

		if (flag == 1)	hash_table[num] = max->next;//���Ƶ�����ĵ����ڱ��ף��滻����ָ��
		else front_max->next = max->next;//���Ƶ�����ĵ����ڱ��У�ɾ�����
	}
	return;
}