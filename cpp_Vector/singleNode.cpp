
#include <iostream>

using namespace std;


struct sNode {
	int data;
	sNode * next;
};

sNode* node;

void initNode()
{
	if (node == NULL) {
		/*node->data=0;
		node->next=NULL;*/
		return;
	}
	else {
		sNode * cur;
		cur= node;

		while (cur != NULL)
		{
			node = cur->next;
			free(cur);
			cur= node;
		}
	}

}

void addNode( int data)
{
	sNode * temp=new sNode();

	temp->data = data;
	temp->next=NULL;

	if (node == NULL){
		node=temp;
		cout << temp->data << " : ";
	}
	else
	{
		temp->next=node;
		node=temp;
		cout << temp->data << " : " ;
	}
	
}

void pushNode( int data)
{
	sNode * temp = new sNode();

	temp->data=data;
	temp->next=node->next;

	node->next=temp;
	cout << temp->data << " : ";

}

void insertNode(int data)
{
	sNode* temp=new sNode();

	temp->data=data;
	temp->next=node->next;

	node->next=temp;

	cout << temp->data << " : ";

}

void ascSortNode()
{
	sNode* temp=new sNode();
	int d=0;

	temp->data=0;
	temp->next=NULL;

	cout <<  " \nSort " << endl;
	for (auto a = node; node != NULL; a=node->next)
	{
		if (a != NULL)
		{

			if (a->data > d)
			{
				d = a->data;
				temp->data=d;
				temp->next=a;
					

			}
			else
			{
				temp=a;

			}
			node = node->next;
			cout << d << " ";
			temp = temp->next;
		}
		else
		{
			return ;
		}
	}
	/*for (int i = 0; node != NULL; i++)
	{
		if (node->data >= d)
		{
			d=node->data;
			temp = node;
			
		}
		else
		{
			temp->next = node;
			
		}
		cout << d << " ";
		temp = temp->next;
	}*/

	/*while (node != NULL) {

		if (node->data == NULL)
		{
			return ;
		}
		else
		{
			if (node->data >= temp->data)
			{
				temp->next = node;
				node = node->next;
			}
			else
			{
				temp->next = node;
				node = node->next;
			}
			
		}

	}*/
	node=temp;

}

void printNode()
{
	while (node != NULL)
	{
		cout << node->data << " " ;
		node = node->next;
	}

	cout << endl <<endl;


}


int main()
{
	
	initNode();
	addNode( 1);
	addNode( 2);
	addNode( 3);
	addNode( 4);
	addNode( 5);

	cout <<  endl;
	pushNode(6);
	pushNode(7);

	cout << endl;
	insertNode(8);
	insertNode(9);

	ascSortNode();
	cout << endl;

	printNode();

	system("pause");
	return 0;
}