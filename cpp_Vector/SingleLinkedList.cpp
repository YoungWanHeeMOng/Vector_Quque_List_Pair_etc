
#include <iostream>

using namespace std;

//typedef struct _node Node;

//struct _node {
//
//	int data;
//        int count;
//	struct Node * next;
//};

class Node {
	public:
		int data;
                int multiData;
		Node * next;
 
};

//typedef struct _list {
//	Node *head;
//	Node *tail;
//	int size;
//} List;
//
//int createList(List *lp);
//int insertFirst(List *lp, int data);
//int insertLast(List *lp, int data);
//int removeNode(List *lp, int data);
//Node *searchNode(List *lp, int data);
//
//void sortList(List *lp);
//void showList(List *lp);
//void removeList(List *lp);
//
//// 처음 만들기
//int createList(List* lp)
//{
//	if (lp == NULL) {
//		return -1;
//	}
//
//	lp->head=new Node;
//	if (lp->head == NULL)
//	{
//		return -1;
//	}
//
//	lp->tail=new Node;
//	if (lp->tail == NULL)
//	{
//		free(lp->head);
//		return -1;
//	}
//
//	lp->head->next=lp->tail;
//	lp->tail->next=lp->tail;
//	lp->size=0;
//
//	return 0;
//}
//
//int insertFirst(List* lp, int data)
//{
//	Node *tmp;
//
//	if (lp == NULL)
//	{
//		return -1;
//	}
//
//	tmp->data=data;
//	tmp->next=lp->head->next;
//	lp->head->next=tmp;
//	lp->size +=1;
//
//	return 0;
//}
//
//int insertLast(List* lp, int data)
//{
//	Node * tmp;
//	Node *frontNode;
//
//	if (lp == NULL)
//	{
//		return -1;
//
//	}
//
//	tmp->data=data;
//	tmp->next=lp->tail;
//	lp->size +=1;
//
//	frontNode=lp->head;
//	while (frontNode != lp->tail)
//	{
//		frontNode=frontNode->next;
//	}
//	frontNode->next=tmp;
//
//	return 0;
//}

void printList(Node* n)
{
	while (n != NULL)
	{
                //if (n->count >= maxCount) maxCount=n->count;
		cout << n->data << " : "  << n->multiData << " / " ;
		n=n->next;
	}
        cout << endl;
}

void countList(Node* n)
{
        int maxCount = 0;
        while (n != NULL)
        {
                n = n->next;
                maxCount++;
        }
        cout << "count Node : " << maxCount << endl;
}



void addList(Node* n, int cnt)
{
        Node* tmp=new Node();

        tmp->data=cnt;
        tmp->next=n->next;

        n->next=tmp;
}

/* Given a reference (pointer to pointer)
to the head of a list and an int,
inserts a new node on the front of the list. */
void push(Node** head_ref, int new_data)
{
        /* 1. allocate node */
        Node * new_node = new Node();

        /* 2. put in the data */
        new_node->data=new_data;
        new_node->multiData=new_data * 3;

        /* 3. Make next of new node as head */
        new_node->next=(*head_ref);

        /* 4. move the head to point to the new node */
        (*head_ref) = new_node;
}

// Give a node prev_node, insert a new node after the given prev_node
void insertAfter(Node* prev_node, int new_data) {
        // 1. check if the given prev_node is NULL
        if (prev_node == NULL)
        {
                cout << "the given previous node cannot be NULL";
                return;
        }

        // 2. Allocate new node
        Node* new_node = new Node();

        // 3. Put in the data
        new_node->data = new_data;
        new_node->multiData = new_data * 4;

        // 4. Make next of new node as next of prev_node
        new_node->next=prev_node->next;

        // 5. move the next of prev_node as new_node
        prev_node->next=new_node;
}

// Given a reference (pointer to pointer ) to the head of a list and an int, appends a new node at the end
void append(Node** head_ref, int new_data)
{
        // 1. allocate node
        Node * new_node=new Node();

        // Used in step 5
        Node * last=*head_ref;

        // 2. pput in the data
        new_node->data=new_data;
        new_node->multiData = new_data * 7;

        // 3. This new node is going to be the last node, so make next of it as NULL
        new_node->next=NULL;

        // 4. If the Linked List is empty,, then  make the new node as head
        if (*head_ref == NULL)
        {
                *head_ref=new_node;
                return ;
        }

        // 5. Else traverse till last node
        while (last->next != NULL)
        {
                last=last->next;
        }

        // 6. Change the next of last node
        last->next=new_node;
        return;
}



int main()
{
        /* Start with the empty list */
        Node* head = NULL;
        
        // Insert 6. So linked list become 6->NULL
        for (int i=0; i < 10; i++)
                append(&head, i);

        // Insert 7 at the beginning , so linked list becomes 7->6->NULL
        push(&head, 7);

        // Insert 1 at the beginning . So linked list becomes 1->7->6->NULL
        push(&head, 1);

        // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
        append(&head, 4);

        // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
        for (int i = 11; i < 20; i++)
                insertAfter(head->next, i);

        cout << "Created Linked list is : ";
        printList(head);
        countList(head);


        system("pause");
        return 0;
}