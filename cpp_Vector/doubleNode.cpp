

#include <iostream>

using namespace std;

typedef int item;

typedef struct sNode
{
	item  data;
	struct sNode* prev;
	struct sNode *next;
} sNode;

// ���� ���� ����Ʈ�� �ʱ�ȭ, ������� prev, next�� �ڱ��ڽ��� ������
void init(sNode* phead) {
	phead->prev = phead;
	phead->next=phead;
}

// ���� ���Ḯ��Ʈ�� ���� ��带 ����� �� ����� �ּҸ� ��ȯ��
sNode* create_node(int n)
{
	sNode * new_node=new sNode();
	new_node->data=n;
	new_node->prev=NULL;		// prev, next �� NULL�� �ʱ�ȭ
	new_node->next=NULL;

	return new_node;
}

// new_node �� before ����� ������ ��ġ�ϵ��� �����Ѵ�.
void insert_node(sNode* before, sNode* new_node)
{
	new_node->prev=before;
	new_node->next=before->next;

	before->next->prev = new_node;  // ���⼭ ���� �״�� �� ��
	before->next=new_node;

}


void display(sNode* phead)
{
	sNode * current =phead->next;

	// ��������� - next �� ���󰡸� �����
	cout << "��������� : ( ";
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

	// ��������� - next �� ���󰡸� �����
	cout << "��������� : ( ";
	while (current != phead) {
		cout << current->data;
		current = current->prev;
		if (current != phead) cout << ",";
	}
	cout << " ) " << endl;
}

// ������ ���� ���� ����Ʈ�� ��带 ���
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

// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main()
{
	// ������ ������ ������ �ƴ� �Ϲݺ����� ����� �д�
	sNode head_node;
	sNode *p[20];
	int i;

	init(&head_node);				// �ʱ�ȭ
	cout << "head_node�� �ּ� = " << &head_node << endl << endl;
	for (i = 0; i < 20; i++)
	{
		p[i]=create_node(i);   // 4���� ��带 �������� ������
		// ��� ����� ������ ���� ������ ��带 ����
		insert_node(&head_node, p[i]);
		cout << "p[" << i << "] ��带 ���߿��Ḯ��Ʈ�� ������ ��� \n";
		display(&head_node);
		reverse_display(&head_node);
	}
	cout << "\n" << "4���� ��带 ���߿��Ḯ��Ʈ�� detail  ��� \n";
	detail_display(&head_node);
	cout << "\n" << "4���� ��带 ���߿��Ḯ��Ʈ�� reverse detail  ��� \n";
	detail_reverse_display(&head_node);


	system("pause");
	return 0;
}