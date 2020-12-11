
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item;
typedef struct DListNode {
	item data;
	struct DListNode * prev;
	struct DListNode * next;
}DListNode;

// head 변수는 항상 첫 노드를 참조한다
DListNode *head=NULL;

// tail 변수는 항상 마지막 노드를 참조한다
DListNode *tail=NULL;


// 이중 연결 리스트의 초기화, 헤드노드의 prev, next 가 자기자신을 참조함
void init(DListNode* phead)
{
	phead->prev=phead;
	phead->next=phead;
}

// new_node 를 before 노드의 다음에 위치하도록 삽입한다.
void insert_node(DListNode* before, DListNode* new_node) {
	new_node->prev=before;
	new_node->next=before->next;

	before->next->prev=new_node;
	before->next=new_node;
}

// 이중 연결리스트를 위한 노드를 만들고 이 노드의 주소를 반환함
DListNode* create_node(int n)
{
	DListNode * new_node = new DListNode();

	new_node->data=n;
	new_node->prev=NULL;
	new_node->next=NULL;

	return new_node;
}



// 이중 연결리스트의 data를 순방향으로 탐색하며 출력함
//
void display()
{
	DListNode * current=head;
	printf("순방향출력: ");
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
	printf("순방향출력: ");
	while (current != phead) {
		printf("%d ", current->data);
		current = current->next;
		if (current != phead) printf(",");
	}
	printf("\n");
}
//  이중 연결리스트의  data를 역방향으로 탐색하며 출력함
void reverse_display(DListNode* phead)
{
	DListNode * current=phead->prev;

	// 역방향출력 - prev 를 따라가며 출력함
	printf("역방향출력: ");
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
//	if (current == NULL) return; //빈 리스트일 경우 중지
//	// 마지막 노드까지 따라가서
//	while (current->next != phead) {
//		current = current->next;
//	}
//	// 역방향출력 - prev 를 따라가며 출력함
//	printf("역방향출력: ");
//	while (current != NULL) {
//		printf("%d ", current->data);
//		current = current->prev;
//		if (current != phead) printf(",");
//
//	}
//	printf("\n");
//}
// 이중 연결 리스트의 노드를 출력
void detail_display(DListNode* phead)
{
	DListNode *current;

	printf("   |%15s	|%16s	|%15p	|	\n", "Prev Node", "Current", "Next Node");
	for (current = phead->next; current != phead; current = current->next) {
		printf("<--|%15p	|%2d(%14p)	|%15p	|-->\n", current->prev,current->data, current,current->next);
	}
	printf("\n");
}



// 노드를 이중 연결리스트의 헤더에 삽입하는 함수
void insert_head(DListNode** phead, int n)
{
	DListNode *new_node = create_node(n);

	// 헤드노드를 가리키는 포인터 변수가 참조하는 객체가 없이 NULL이면 새 노드를 참조하도록 한다
	if (*phead == NULL) {
		*phead = new_node;
		return;
	}
	(*phead)->prev = new_node;
	new_node->next=*phead;
	*phead=new_node;
}

// data 값을 가진 노드를 연결 리스트의 첫 노드로 삽입
void insert_head(int data) {
	// 새로운 노드 생성
	DListNode * new_node=create_node(data);

	// 연결 리스트가 비어있으면
	if (head == NULL)
		head=tail=new_node;		//tail , head 가 새노드를 참조
	else {
		head->prev=new_node;		// 헤드의 선행노드를 업데이트
		// 새 노드의 next 가 head 노드를 참조함
		new_node->next=head;
		// 새 노드를 head 가 참조
		head=new_node;
	}
}
// 노드를 이중 연결리스트의 꼬리에 삽입하는 함수
void insert_tail(DListNode** phead, int n)
{
	DListNode *current=*phead;
	DListNode *new_node=create_node(n);

	if (*phead == NULL) {
		*phead =new_node;
		return;
	}
	while (current->next != NULL)
		current = current->next;  // 마지막 노드까지 이동

	//마지막 노드의 다음 노드에 삽입함
	current->next = new_node;
	new_node->prev =current;
}

// data 값을 가진 노드를 연결 리스트의 마지막 노드로 삽입
void insert_tail(int data) {
	// 새로운 노드 생성
	DListNode * new_node=create_node(data);

	// 연결리스트가 비어있다면
	if (head==NULL)
		head=tail=new_node;		// tail, head 가 새노드를 참조
	else {
		tail->next=new_node;		// 마지막 노드의 후행 노드를 업데이트
		// 새 노드의 prev가 tail 노드를 참조함
		new_node->prev=tail;
		//새 노드를 tail가 참조
		tail=new_node;
	}
}


// 연결리스트가 empty 인가 검사하는 함수
bool isEmpty()
{
	return head == NULL;
}

// 연결 리스트의 길이를 구하는함수
int length()
{
	int length=0;
	DListNode * current;

	for (current = head; current != NULL; current = current->next) {
		length ++;
	}

	return length;
}

// key값을 가진 노드를 발견하면 이노드 앞에 data 값을 가진 새로운 노드를 생성하여 삽입함
bool insert_before(int key, int data) {
	DListNode *current=head;

	// 리스트가 비어있다면 false를 반환
	if (head== NULL)  return false;

	// 리스트를 탐색함
	while (current->data != key) {
		// 마지막까지 갔다면 삭제를 안하고  false를 반환
		if (current->next == NULL)
			return false;
		else
			current=current->next;
	}

	if (current == head) {
		insert_head(data) ;
	}
	else {
		// 새 노드를 만든다
		DListNode *new_node = create_node(data);

		new_node->prev = current->prev;
		current->prev->next=new_node;
		new_node->next=current;
		current->prev=new_node;
	}
	return true;
}

// key값을 가진 노드를 발견하면 이 노드 뒤에 data 값을 가진 새료운 노드를 생성하여 삽입함
bool insert_after(int key, int data) {
	DListNode * current=head;

	// 리스트가 비어있다면 false를 반환
	if (head==NULL) return false;

	// 리스트를 탐색함
	while (current->data != key) {
		// 마지막까지 갔다면 삭제를 안하고 false를 반환
		if (current ->next == NULL)
			return false;
		else
			current=current->next;

	}

	if (current == tail) {
		insert_tail(data);
	} else {
		// 새 노드를 만든다
		DListNode *new_node=create_node(data);

		new_node->next = current->next;
		current->next->prev=new_node;
		new_node->prev=current;
		current->next=new_node;
	}
	return true;
}

// 첫 노드를 삭제하는 함수
void delete_head()
{
	// 첫 노드를 참조하는 링크를 임시로 저장
	DListNode *temp_node = head;

	// 빈 리스트일 경우 - 아무것도 하지 않음
	if(head == NULL)
		return;
	else if (head->next==NULL) // 노드가 하나뿐일 경우
		tail=NULL;

	head=head->next;
	free(temp_node);
}

// 마지막 노드를 삭제하는 함수
void delete_tail()
{
	// 마지막 노드를 참조하는 링크를 임시로 저장
	DListNode* temp_node = tail;

	// 빈 리스트일 경우 - 아무것도 하지 않음
	if (tail == NULL)
		return;
	else if (head->next == NULL) // 노드가 하나뿐일 경우
		head = NULL;
	else
	{
		tail->prev->next = NULL;
	}

	tail = tail->prev;
	free(temp_node);
}

// 주어진 키를 가진 노드를 삭제함
bool Delete(int key)
{
	// 첫 노드에서부터 시작해서 검색
	DListNode* current=head;

	// 리스트가 비어있을 경우 false을 반환
	if (head == NULL)
		return false;

	// 리스트를 탐색함
	while (current->data != key) {
		// 마지막까지 갔다면 삭제를 안하고 false를 반환
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


	printf("\n순방향출력 (처음부터 끝) : ");
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

	// 헤드노드는 포인터 변수가 아닌 일반변수로 만들어 둔다
	DListNode head_node;
	DListNode *p[10];
	int i;

	init(&head_node);			//헤드노드를 초기화한다
	printf("head_node의 주소 = %14p\n\n", &head_node);
	for (i=0; i < 4; i++) { // 4개의 노드를 동적으로 생성함
		p[i] = create_node(i);
		// 헤드 노드의 다음에 새로 생성된 노드를 삽입
		insert_node(&head_node, p[i]);
		printf("p[%d] 노드를 이중연결리스트에 삽입한 결과\n", i);
		display(&head_node);
		reverse_display(&head_node);
		 }
	printf("\n4개의 노드를 이중연결리스트에 삽입한 결과\n");
	detail_display(&head_node);



	system("pause");
	return 0;
}

