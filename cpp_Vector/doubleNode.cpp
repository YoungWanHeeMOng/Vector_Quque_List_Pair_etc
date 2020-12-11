

#include <iostream>

using namespace std;

typedef int item;

typedef struct sNode
{
	item  data;
	struct sNode* prev;
	struct sNode *next;
} sNode;

// 이중 연결 리스트의 초기화, 헤드노드의 prev, next가 자기자신을 참조함
void init(sNode* phead) {
	phead->prev = phead;
	phead->next=phead;
}

// 이중 연결리스트를 위한 노드를 만들고 이 노드의 주소를 반환함
sNode* create_node(int n)
{
	sNode * new_node=new sNode();
	new_node->data=n;
	new_node->prev=NULL;		// prev, next 를 NULL로 초기화
	new_node->next=NULL;

	return new_node;
}

// new_node 를 before 노드의 다음에 위치하도록 삽입한다.
void insert_node(sNode* before, sNode* new_node)
{
	new_node->prev=before;
	new_node->next=before->next;

	before->next->prev = new_node;  // 여기서 순서 그대로 할 것
	before->next=new_node;

}


void display(sNode* phead)
{
	sNode * current =phead->next;

	// 순방향출력 - next 를 따라가며 출력함
	cout << "순방향출력 : ( ";
	while (current != phead) {
		cout << current->data ;
		current=current->next;
		if (current != phead) cout << ",";
	}
	cout << " ) " << endl;
}

void reverse_display(sNode* phead)
{
	sNode* current = phead->prev;

	// 순방향출력 - next 를 따라가며 출력함
	cout << "역방향출력 : ( ";
	while (current != phead) {
		cout << current->data;
		current = current->prev;
		if (current != phead) cout << ",";
	}
	cout << " ) " << endl;
}

// 디테일 이중 연결 리스트의 노드를 출력
void detail_display(sNode* phead)
{
	sNode * current;
	printf("    |%15s  |%16s  |%15s  \n", "Prev Node", "Curent", "Next Node");
	for (current = phead->next; current != phead; current = current->next) {
		printf("<--|%15p  |%2d(%14p) |%15p  |-->\n", current->prev, current->data,current,current->next);
	}
	cout << endl;
}

void detail_reverse_display(sNode* phead)
{
	sNode* current;
	printf("    |%15s  |%16s  |%15s  \n", "Prev Node", "Curent", "Next Node");
	for (current = phead->prev; current != phead; current = current->prev) {
		printf("<--|%15p  |%2d(%14p) |%15p  |-->\n", current->prev, current->data, current, current->next);
	}
	cout << endl;
}

// 이중 연결 리스트 테스트 프로그램
int main()
{
	// 헤드노드는 포인터 변수가 아닌 일반변수로 만들어 둔다
	sNode head_node;
	sNode *p[20];
	int i;

	init(&head_node);				// 초기화
	cout << "head_node의 주소 = " << &head_node << endl << endl;
	for (i = 0; i < 20; i++)
	{
		p[i]=create_node(i);   // 4개의 노드를 동적으로 생성함
		// 헤드 노드의 다음에 새로 생성된 노드를 삽입
		insert_node(&head_node, p[i]);
		cout << "p[" << i << "] 노드를 이중연결리스트에 삽입한 결과 \n";
		display(&head_node);
		reverse_display(&head_node);
	}
	cout << "\n" << "4개의 노드를 이중연결리스트에 detail  결과 \n";
	detail_display(&head_node);
	cout << "\n" << "4개의 노드를 이중연결리스트에 reverse detail  결과 \n";
	detail_reverse_display(&head_node);


	system("pause");
	return 0;
}