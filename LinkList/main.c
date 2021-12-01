#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "linkList.h"



int main(int argc, char** argv) {
	// Ԥ������1000��ͷ���� ���ҳ�ʼ����
	linkList* list[1000];
	for (int i = 0; i < 1000; i++)
	{
		list[i] = (linkList*)malloc(sizeof(linkList));
		list[i]->nextNode = NULL;
		list[i]->prevNode = NULL;

	}
	//����һ�����õ�����ָ��
	linkList* pointOflist = NULL;
	if (!strcmp(argv[1], "-d"))
	{
		int begin = 0;
		int end = 0;
		//p������¼ÿһ������
		int p = 0;
		//���argv[2]�ڵĵ���
		while (argv[2][end] != '\0') {
			// begin��ÿ��������argv�е���ʼλ�ã�end������ֹ��λ��
			while (('a' <= argv[2][end] && argv[2][end] < 'z') || ('A' <= argv[2][end] && argv[2][end] < 'Z'))
			{
				end++;
			}
			//��ʱ��λ��Ϊ����β����+1��λ��
			char* this_word = (char*)malloc(end - begin - 1);
			cpyByNum(this_word, argv[2], begin, end - 1);
			int index = hashFunction(this_word);
			printf("%d", index);
			addNode(list[index], this_word, end - begin - 1);
			begin = end++;

		}

	}
}