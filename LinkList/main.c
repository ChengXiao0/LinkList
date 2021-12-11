#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "linkList.h"

#pragma warning(disable:4996)

int main(int argc, char** argv) {
	// 预先设置1000个头链表， 并且初始化它
	linkList* list[1000];
	for (int i = 0; i < 1000; i++)
	{
		list[i] = (linkList*)malloc(sizeof(linkList));
		list[i]->nextNode = NULL;
		list[i]->prevNode = NULL;

	}
	//设置一个常用的链表指针
	linkList* pointOflist = NULL;
	if (!strcmp(argv[1], "-d"))
	{
		int begin = 0;
		int end = 0;
		//p帮助记录每一个单词
		int p = 0;
		//检查argv[2]内的单词
		while (argv[2][end] != '\0') {
			// begin是每个单词在argv中的起始位置，end则是终止的位置
			while (('a' <= argv[2][end] && argv[2][end] < 'z') || ('A' <= argv[2][end] && argv[2][end] < 'Z'))
			{
				end++;
			}
			//此时的位置为单词尾部还+1的位置
			char* this_word = (char*)malloc(end - begin - 1);
			cpyByNum(this_word, argv[2], begin, end - 1);
			int index = hashFunction(this_word);
			addNode(list[index], this_word, end - begin - 1);
			//将end移动到下个单词的头部
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
		//计算文件文本的长度
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
		//关闭文件，重新打开
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
		//p帮助记录每一个单词
		int p = 0;
		//检查str内的单词
		while (str[end] != '\0') {
			// begin是每个单词在argv中的起始位置，end则是终止的位置
			while (('a' <= str[end] && str[end] < 'z') || ('A' <= str[end] && str[end] < 'Z'))
			{
				end++;
			}
			//此时的位置为单词尾部还+1的位置
			char* this_word = (char*)malloc(end - begin - 1);
			cpyByNum(this_word, str, begin, end - 1);
			int index = hashFunction(this_word);
			addNode(list[index], this_word, end - begin - 1);
			//将end移动到下个单词的头部
			while ((!(('a' <= str[end] && str[end] < 'z') || ('A' <= str[end] && str[end] < 'Z'))) && str[end] != '\0')
			{
				end++;
			}
			begin = end;
		}
	}
	//打印结果
	for (int i = 0; i < 1000; i++)
	{
		printList(list[i]);
	}
	return 0;
}