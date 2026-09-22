#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

struct node
{
	ElemType data;
	struct node* next;
};
typedef node Node;
Node* initList()
{
	Node *head=(Node*)malloc(sizeof(Node));
	if (head == NULL)
		return NULL;
	head->data = 0;
	head->next = NULL;
	return head;
}
int insertHead(Node *L,ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (p==NULL)
        return NULL;

	p->data = e;
	p->next = L->next;
	L->next = p;
	return 0;
}
void listNode(Node* L)
{
	Node *p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	
}Node* get_tail(Node* L)
{

	Node *p = L;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p;
}
Node* insertTail(Node *tail,ElemType e)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
		return NULL;
	p->data = e;
	tail->next = p;
	p->next = NULL;
	return p;
}
int insertNode(Node* L, ElemType e, int pos)
{

	Node* p = L;
	int i = 0;
	while (i < pos - 1)
	{
		if (p==NULL)
		{
			return 0;
		}
		p = p->next;
		i++;
		
	}
	Node* q = (Node*)malloc(sizeof(Node));
	if (q == NULL)
		return 0;
	q->next = p->next;
	q->data = e;
	p->next = q;
	return 1;

}
int deleteNode(Node *L, int pos)
{
	Node* p = L;
	int i = 0;
	while (i < pos - 1)
	{
		if (p == NULL)
			return 0;
		p = p->next;
		i++;
	}
	if (p->next == NULL)
		return 0;
	Node *q = p->next;
	p->next = q->next;
	free(q);
	return 1;
}
int freeList(Node* L)
{
	Node *p = L;
	Node* q = L;
	if (p==NULL||q==NULL)
	{
		return 0;
	}
	while(p->next != NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	 L->next = NULL;
	 return 1;

}
int lenthList(Node *L)
{
	Node* p = L;
	int i = 1;
	while (p->next != 0)
	{
		p = p->next;
		i++;
	}
	printf("%d\n", i);
	return 1;
}


int main()
{
	Node* list = initList();
	insertHead(list, 10);
	insertHead(list, 20);
	insertHead(list, 30);
	insertTail(get_tail(list), 99);
	insertNode(list, 3, 3);
	listNode(list);
	//deleteNode(list, 1);
	lenthList(list);
	freeList(list);
	lenthList(list);
	return 1;

}

