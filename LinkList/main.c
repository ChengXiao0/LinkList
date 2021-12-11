#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "linkList.h"

#pragma warning(disable:4996)

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
			addNode(list[index], this_word, end - begin - 1);
			//��end�ƶ����¸����ʵ�ͷ��
			while ((!(('a' <= argv[2][end] && argv[2][end] < 'z') || ('A' <= argv[2][end] && argv[2][end] < 'Z')))&& argv[2][end]!='\0')
			{
				end++;
			}
			begin = end;
		}
	}
	else if (!strcmp(argv[1], "-f"))
	{
		FILE* fp = fopen(argv[2], "r");
		long count = 0;
		//�����ļ��ı��ĳ���
		if (!fp) {
			printf("ERROR!!! con't open file");
			return 0;
		}
		else
		{
			char ch;
			printf("File opened successfully");
			while (EOF != (ch = fgetc(fp)))
			{
				count++;
			}
			
		}
		fclose(fp);
		//�ر��ļ������´�
		FILE* fp1 = fopen(argv[2], "r");
		char ch;
		char* str = (char*)malloc(sizeof(char) * count);
		int strIndex = 0;
		while (EOF != (ch = fgetc(fp1)))
		{
			str[strIndex] = ch;
			strIndex++;
		}
		fclose(fp1);
		int begin = 0;
		int end = 0;
		//p������¼ÿһ������
		int p = 0;
		//���str�ڵĵ���
		while (str[end] != '\0') {
			// begin��ÿ��������argv�е���ʼλ�ã�end������ֹ��λ��
			while (('a' <= str[end] && str[end] < 'z') || ('A' <= str[end] && str[end] < 'Z'))
			{
				end++;
			}
			//��ʱ��λ��Ϊ����β����+1��λ��
			char* this_word = (char*)malloc(end - begin - 1);
			cpyByNum(this_word, str, begin, end - 1);
			int index = hashFunction(this_word);
			addNode(list[index], this_word, end - begin - 1);
			//��end�ƶ����¸����ʵ�ͷ��
			while ((!(('a' <= str[end] && str[end] < 'z') || ('A' <= str[end] && str[end] < 'Z'))) && str[end] != '\0')
			{
				end++;
			}
			begin = end;
		}
	}
	//��ӡ���
	for (int i = 0; i < 1000; i++)
	{
		printList(list[i]);
	}
	return 0;
}