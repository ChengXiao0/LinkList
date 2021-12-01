#include <stdlib.h>
#include"utils.h"
#include"linkList.h"
void addNode(linkList* headNode, char* value, int length) {
	//����һ���µĽڵ㣬��malloc����ռ�
	linkList* newNode = (linkList*)malloc(sizeof(linkList));
	newNode->value = (char*)malloc(length);
	strcpy(newNode->value, value);
	newNode->times = 0;
	newNode->nextNode = NULL;
	//���������ͷ��û��ָ����һ���ڵ㣬��ô��Ϊ��������ǵ�һ�α��޸�
	if (headNode->nextNode == NULL) {
		headNode->nextNode = newNode;
		newNode->prevNode = headNode;
	}
	else {
		//���������ҵ�����ĩβ�Ľڵ㣬�����¸��ڵ�ָ��ָ��ǰ�½ڵ�
		linkList* p = headNode;
		while (p->nextNode != NULL) {
			p = p->nextNode;
		}
		newNode->value = value;
		newNode->prevNode = p;
		p->nextNode = newNode;
	}
}

void insertNode(linkList* thisNode, char* value)
{
	/*
	* thisNodeָ��һ���ڵ�
	*/
}

int findNode(linkList* head, char* value, linkList* p)
{
	//pָ�����ڷ������ҵ�Ԫ�ص�λ��
	p = head;
	//��ͷ��ʼ������֪������һ���ڵ�
	while (p->nextNode)
	{
		if (p->value == value)
		{
			p->times++;
			return 1;
		}
		p = p->nextNode;
	}
	return 0;
	
	
}