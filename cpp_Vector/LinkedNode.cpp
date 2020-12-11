
#include <iostream>
#include <string>
//#include <malloc.h>
using namespace std;

typedef struct node {
	int value;
	string name;
	struct node * next;	// 다음 노드를 가리키는포인터
} NODE;

NODE * start=NULL; // 시작 노드를 가리키는 포인터

void initNode();		// 초기화 노드
void pushNode(int value) ; // 노드 앞쪽에뒤에 넣기
void rpushNode(int value);  // 뒤에 넣기

void printNode();			// 프린트 노드

int main()
{
	NODE * cur = NULL;		//현재 노드를 가리키는 포인터
	NODE * new_node=NULL;	// 새로 생성된 노드를 가리키는 포인터

	if (start == NULL)				// 처음 생성한 노드
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

	new_node = new NODE();		// 노드 생성
	new_node->next = NULL;		// 포인터 초기화
	start = new_node;				// 시작 지점으로 설정
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