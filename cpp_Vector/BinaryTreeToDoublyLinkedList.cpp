
#include <iostream>

using namespace std;

class node
{
	public:
		int data;
		node* left;
		node* right;
};

/* This is the core function to convert Tree to list. This function follows steps 1 and 2 of the above algorithm */
node* bintree2listUtil(node* root)
{
	// base case
	if (root == NULL)
	{
		return root;
	}

	// Convert the left subtree and link to root
	if (root->left != NULL)
	{
		// Convert the left subtree
		node* left=bintree2listUtil(root->left);

		// Find inorder predecessor . After this loop, left will point to the inorder predecessor
		for (; left->right != NULL; left=left->right);

		// Make root as next of the predecessor
		left->right=root;
		cout << "left->right ";
		// Make predecessor as previous of root
		root->left=left;
	}

	// Convert the right subtree and link to root
	if (root->right != NULL)
	{
		// Convert the right subtree
		node * right = bintree2listUtil(root->right);

		// Find inorder successor. After this loop , right will point to the inorder successor
		for(; right->left != NULL; right=right->left);

		// Make root as previous of successor
		right->left=root;
		cout << "right->left ";
		// Make successor as next of root
		root->right=right;
	}

	return root;
}

// The main function that first callls bintree2listUtil(), then follows step 3 of the above algorithm
node* bintree2list(node* root)
{
	// base case
	if (root==NULL)
		return root;

	// Convert to DLL using bintree2listUtil()
	root=bintree2listUtil(root);

	// bintree2listUtil() returns root of the converted DLL. we need pointer to the leftmost node 
	// which is head of the constructed DLL, so move to the leftmost node
	while (root->left != NULL)
	{
		root=root->left;
	}
	return (root);
}

/* Helper function that allocated a new node with the given data and MULL left and right pointers. */
node* newNode(int data)
{
	node* new_node=new node();
	new_node->data=data;
	new_node->left=new_node->right=NULL;
	return new_node;
}

/* Function to print nodes in a given doubly linked list */
void printList(node* node)
{
	while (node != NULL)
	{
		cout<< node->data << " ";
		node=node->right;
	}

	cout << "\n";
}

/* Driver code */
int main()
{
	// let us create the tree shown in above diagram
	node * root = newNode(10);
	root->left=newNode(12);
	root->right=newNode(15);
	root->left->left=newNode(25);
	root->left->right=newNode(30);
	root->right->left=newNode(36);

	// Convert to DLL
	node * head=bintree2list(root);

	cout <<"\n";
	// print the converted list
	printList(head);


	system ("pause");
	return 0;
}



