
#include <iostream>
#include <string>
//#include <malloc.h>
using namespace std;

typedef struct node {
	int value;
	string name;
	struct node * next;	// ���� ��带 ����Ű��������
} NODE;

NODE * start=NULL; // ���� ��带 ����Ű�� ������

void initNode();		// �ʱ�ȭ ���
void pushNode(int value) ; // ��� ���ʿ��ڿ� �ֱ�
void rpushNode(int value);  // �ڿ� �ֱ�

void printNode();			// ����Ʈ ���

int main()
{
	NODE * cur = NULL;		//���� ��带 ����Ű�� ������
	NODE * new_node=NULL;	// ���� ������ ��带 ����Ű�� ������

	if (start == NULL)				// ó�� ������ ���
	{
		initNode();
	}

	for (int i=0; i < 11; i++)
			rpushNode ( i);

	printNode();

	system("pause");
	return 0;
}

void initNode()
{
	NODE  * new_node= new NODE();

	new_node = new NODE();		// ��� ����
	new_node->next = NULL;		// ������ �ʱ�ȭ
	start = new_node;				// ���� �������� ����
}

void pushNode( int value)
{
	NODE * new_node=new NODE();

	new_node->value=value;
	new_node->next=NULL;

	if (start == NULL) {
		start=new_node;
	}
	else {
		new_node->next =start;
		start=new_node;
	}
	
}

void rpushNode(int value)
{
	NODE* new_node = new NODE();
	char n[18]="12345";
	new_node->value = value;
	/*new_node->name =*("node") ;*/
	new_node->name="Node-";
	new_node->next = NULL;

	NODE* tempNode = start;

	while (tempNode->next != NULL)
	{
		tempNode = tempNode->next;
	}
	tempNode->next = new_node;

}

void printNode()
{
	while (start != NULL)
	{
		printf("Name : %10s  Value : %3d Next Pointer : %10d\n", start->name.c_str(), start->value, start->next);
		cout << start->name << endl;
		start = start->next;
	}
}