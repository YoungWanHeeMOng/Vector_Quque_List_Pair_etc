
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item;
typedef struct DListNode {
	item data;
	struct DListNode * prev;
	struct DListNode * next;
}DListNode;

// head ������ �׻� ù ��带 �����Ѵ�
DListNode *head=NULL;

// tail ������ �׻� ������ ��带 �����Ѵ�
DListNode *tail=NULL;


// ���� ���� ����Ʈ�� �ʱ�ȭ, ������� prev, next �� �ڱ��ڽ��� ������
void init(DListNode* phead)
{
	phead->prev=phead;
	phead->next=phead;
}

// new_node �� before ����� ������ ��ġ�ϵ��� �����Ѵ�.
void insert_node(DListNode* before, DListNode* new_node) {
	new_node->prev=before;
	new_node->next=before->next;

	before->next->prev=new_node;
	before->next=new_node;
}

// ���� ���Ḯ��Ʈ�� ���� ��带 ����� �� ����� �ּҸ� ��ȯ��
DListNode* create_node(int n)
{
	DListNode * new_node = new DListNode();

	new_node->data=n;
	new_node->prev=NULL;
	new_node->next=NULL;

	return new_node;
}



// ���� ���Ḯ��Ʈ�� data�� ���������� Ž���ϸ� �����
//
void display()
{
	DListNode * current=head;
	printf("���������: ");
	while (current != NULL) {
		printf("%d ", current->data);
		current=current->next;
		if (current != head) printf(",");
	}
	printf("\n");
}

void display(DListNode* phead)
{
	DListNode* current = phead->next;
	printf("���������: ");
	while (current != phead) {
		printf("%d ", current->data);
		current = current->next;
		if (current != phead) printf(",");
	}
	printf("\n");
}
//  ���� ���Ḯ��Ʈ��  data�� ���������� Ž���ϸ� �����
void reverse_display(DListNode* phead)
{
	DListNode * current=phead->prev;

	// ��������� - prev �� ���󰡸� �����
	printf("���������: ");
	while (current != phead) {
		printf("%d ", current->data);
		current=current->prev;
		if(current != phead) printf(",");
		
	}
	printf("\n");
}
//void reverse_display(DListNode* phead)
//{
//	DListNode* current = phead;
//
//	if (current == NULL) return; //�� ����Ʈ�� ��� ����
//	// ������ ������ ���󰡼�
//	while (current->next != phead) {
//		current = current->next;
//	}
//	// ��������� - prev �� ���󰡸� �����
//	printf("���������: ");
//	while (current != NULL) {
//		printf("%d ", current->data);
//		current = current->prev;
//		if (current != phead) printf(",");
//
//	}
//	printf("\n");
//}
// ���� ���� ����Ʈ�� ��带 ���
void detail_display(DListNode* phead)
{
	DListNode *current;

	printf("   |%15s	|%16s	|%15p	|	\n", "Prev Node", "Current", "Next Node");
	for (current = phead->next; current != phead; current = current->next) {
		printf("<--|%15p	|%2d(%14p)	|%15p	|-->\n", current->prev,current->data, current,current->next);
	}
	printf("\n");
}



// ��带 ���� ���Ḯ��Ʈ�� ����� �����ϴ� �Լ�
void insert_head(DListNode** phead, int n)
{
	DListNode *new_node = create_node(n);

	// ����带 ����Ű�� ������ ������ �����ϴ� ��ü�� ���� NULL�̸� �� ��带 �����ϵ��� �Ѵ�
	if (*phead == NULL) {
		*phead = new_node;
		return;
	}
	(*phead)->prev = new_node;
	new_node->next=*phead;
	*phead=new_node;
}

// data ���� ���� ��带 ���� ����Ʈ�� ù ���� ����
void insert_head(int data) {
	// ���ο� ��� ����
	DListNode * new_node=create_node(data);

	// ���� ����Ʈ�� ���������
	if (head == NULL)
		head=tail=new_node;		//tail , head �� ����带 ����
	else {
		head->prev=new_node;		// ����� �����带 ������Ʈ
		// �� ����� next �� head ��带 ������
		new_node->next=head;
		// �� ��带 head �� ����
		head=new_node;
	}
}
// ��带 ���� ���Ḯ��Ʈ�� ������ �����ϴ� �Լ�
void insert_tail(DListNode** phead, int n)
{
	DListNode *current=*phead;
	DListNode *new_node=create_node(n);

	if (*phead == NULL) {
		*phead =new_node;
		return;
	}
	while (current->next != NULL)
		current = current->next;  // ������ ������ �̵�

	//������ ����� ���� ��忡 ������
	current->next = new_node;
	new_node->prev =current;
}

// data ���� ���� ��带 ���� ����Ʈ�� ������ ���� ����
void insert_tail(int data) {
	// ���ο� ��� ����
	DListNode * new_node=create_node(data);

	// ���Ḯ��Ʈ�� ����ִٸ�
	if (head==NULL)
		head=tail=new_node;		// tail, head �� ����带 ����
	else {
		tail->next=new_node;		// ������ ����� ���� ��带 ������Ʈ
		// �� ����� prev�� tail ��带 ������
		new_node->prev=tail;
		//�� ��带 tail�� ����
		tail=new_node;
	}
}


// ���Ḯ��Ʈ�� empty �ΰ� �˻��ϴ� �Լ�
bool isEmpty()
{
	return head == NULL;
}

// ���� ����Ʈ�� ���̸� ���ϴ��Լ�
int length()
{
	int length=0;
	DListNode * current;

	for (current = head; current != NULL; current = current->next) {
		length ++;
	}

	return length;
}

// key���� ���� ��带 �߰��ϸ� �̳�� �տ� data ���� ���� ���ο� ��带 �����Ͽ� ������
bool insert_before(int key, int data) {
	DListNode *current=head;

	// ����Ʈ�� ����ִٸ� false�� ��ȯ
	if (head== NULL)  return false;

	// ����Ʈ�� Ž����
	while (current->data != key) {
		// ���������� ���ٸ� ������ ���ϰ�  false�� ��ȯ
		if (current->next == NULL)
			return false;
		else
			current=current->next;
	}

	if (current == head) {
		insert_head(data) ;
	}
	else {
		// �� ��带 �����
		DListNode *new_node = create_node(data);

		new_node->prev = current->prev;
		current->prev->next=new_node;
		new_node->next=current;
		current->prev=new_node;
	}
	return true;
}

// key���� ���� ��带 �߰��ϸ� �� ��� �ڿ� data ���� ���� ����� ��带 �����Ͽ� ������
bool insert_after(int key, int data) {
	DListNode * current=head;

	// ����Ʈ�� ����ִٸ� false�� ��ȯ
	if (head==NULL) return false;

	// ����Ʈ�� Ž����
	while (current->data != key) {
		// ���������� ���ٸ� ������ ���ϰ� false�� ��ȯ
		if (current ->next == NULL)
			return false;
		else
			current=current->next;

	}

	if (current == tail) {
		insert_tail(data);
	} else {
		// �� ��带 �����
		DListNode *new_node=create_node(data);

		new_node->next = current->next;
		current->next->prev=new_node;
		new_node->prev=current;
		current->next=new_node;
	}
	return true;
}

// ù ��带 �����ϴ� �Լ�
void delete_head()
{
	// ù ��带 �����ϴ� ��ũ�� �ӽ÷� ����
	DListNode *temp_node = head;

	// �� ����Ʈ�� ��� - �ƹ��͵� ���� ����
	if(head == NULL)
		return;
	else if (head->next==NULL) // ��尡 �ϳ����� ���
		tail=NULL;

	head=head->next;
	free(temp_node);
}

// ������ ��带 �����ϴ� �Լ�
void delete_tail()
{
	// ������ ��带 �����ϴ� ��ũ�� �ӽ÷� ����
	DListNode* temp_node = tail;

	// �� ����Ʈ�� ��� - �ƹ��͵� ���� ����
	if (tail == NULL)
		return;
	else if (head->next == NULL) // ��尡 �ϳ����� ���
		head = NULL;
	else
	{
		tail->prev->next = NULL;
	}

	tail = tail->prev;
	free(temp_node);
}

// �־��� Ű�� ���� ��带 ������
bool Delete(int key)
{
	// ù ��忡������ �����ؼ� �˻�
	DListNode* current=head;

	// ����Ʈ�� ������� ��� false�� ��ȯ
	if (head == NULL)
		return false;

	// ����Ʈ�� Ž����
	while (current->data != key) {
		// ���������� ���ٸ� ������ ���ϰ� false�� ��ȯ
		if (current->next == NULL)
			return false;
		else
		{
			current=current->next;
		}
	}

	if(current == head)
		delete_head();
	else if (current == tail)
		delete_tail();
	else {
		current->prev->next=current->next;
		current->next->prev = current->prev;
		free(current);
	}
	return true;
}


int main()
{
	/*init(head);
	insert_head(100);
	insert_head(200);
	insert_head(300);
	insert_head(400);
	insert_head(500);
	insert_head(600);


	printf("\n��������� (ó������ ��) : ");
	display();
	Delete(100);
	display();
	Delete(600);
	display();
	Delete(300);
	display();
	delete_tail();
	display();
	insert_after(500,300);
	display();
	insert_before(500,600);
	display();
	printf("\n");*/

	// ������ ������ ������ �ƴ� �Ϲݺ����� ����� �д�
	DListNode head_node;
	DListNode *p[10];
	int i;

	init(&head_node);			//����带 �ʱ�ȭ�Ѵ�
	printf("head_node�� �ּ� = %14p\n\n", &head_node);
	for (i=0; i < 4; i++) { // 4���� ��带 �������� ������
		p[i] = create_node(i);
		// ��� ����� ������ ���� ������ ��带 ����
		insert_node(&head_node, p[i]);
		printf("p[%d] ��带 ���߿��Ḯ��Ʈ�� ������ ���\n", i);
		display(&head_node);
		reverse_display(&head_node);
		 }
	printf("\n4���� ��带 ���߿��Ḯ��Ʈ�� ������ ���\n");
	detail_display(&head_node);



	system("pause");
	return 0;
}

