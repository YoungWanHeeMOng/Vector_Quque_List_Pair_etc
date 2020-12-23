/* 
���� ���Ḯ��Ʈ - ���� ���Ḯ��Ʈ ��������
��� �����ʱ�ȭ ���� ���� �˻� ��ü ��� ����
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * next;
}Node;


void InitList(Node **phead, Node **ptail);
void AddData(Node **phead, Node **ptail, int data);
void Remove(Node **phead, Node **ptail, Node *now);
Node *Find(Node *seek, int data);
void ViewAll(Node *head, Node *tail);
void Clear(Node **phead, Node **ptail);

int main()
{
	Node *head;
	Node * tail;
	InitList(&head, &tail);
	AddData(&head, &tail, 3);
	AddData(&head, &tail, 4);
	AddData(&head, &tail, 6);
	AddData(&head, &tail, 9);
	ViewAll(head, tail);


	Node *seek=Find(head, 4);
	if (seek)
	{
		printf("4�� ������ ��带 ã����\n");
		Remove(&head, &tail, seek);
		printf("4�� ������ ��带 ������\n");
		ViewAll(head,tail);
	}
	Clear (&head, &tail);
	ViewAll(head, tail);

	return 0;
}

void InitList(Node** phead, Node** ptail)
{
	*phead=*ptail=NULL;
}

void AddData(Node** phead, Node** ptail, int data)
{
	Node *now=(Node *) malloc(sizeof(Node));
	now->data=data;

	if (*phead == NULL)
	{
		*phead=*ptail=now;
		return;
	}
	(*ptail)->next=now;
	now->next=(*phead);
	(*ptail)=now;
}

void Remove(Node** phead, Node** ptail, Node* now)
{
	Node *prev=NULL;
	Node *seek=*phead;
	while (seek != *ptail)
	{
		if (seek == now)
		{
			break;
		}
		prev=seek;
		seek=seek->next;

	}

	if (seek == *ptail && seek != now) // ���� �߻�
	{
		return;
	}
	if (seek == *phead)
	{
		*phead=seek->next;
	}
	if (seek == *ptail)
	{
		*ptail= prev;
	}
	if (prev)
	{
		prev->next = seek->next;
	}
	
	free (seek);
}

	

Node *Find(Node* seek, int data)
{
	Node *at=seek;
	if (seek == NULL)	//���� �߻�
	{
		return NULL;
	}
	do
	{
		if (seek->data == data)
		{
			return seek;
		}
		seek=seek->next;
	} while (seek != at);

	return NULL;
}
void ViewAll(Node* head, Node* tail)
{
	Node *seek=head;
	int i = 0;
	if (head == NULL)
	{
		printf("��� �ֽ��ϴ�.\n");
		return;
	}
	while (seek != tail)
	{
		i++;
		printf("[%2d]:%-5d ", i, seek->data);
		if (i % 5 == 0)
		{
			printf("\n");
		}
		seek=seek->next;
	}
	i++;
	printf("[%2d]:%-5d ",i, seek->data);
	printf("\n");

}
void Clear(Node** phead, Node** ptail) {
	Node *prev=NULL;
	Node *seek=*phead;
	while (seek != *ptail)
	{
		prev=seek;
		seek=seek->next;
		free(prev);
	}
	free (seek);
	*phead=*ptail=NULL;
	printf("��� �������ϴ�.\n");
}