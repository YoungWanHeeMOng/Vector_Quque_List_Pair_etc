using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;
//using System.Threading.Tasks;
//using System.Xml;

// C# program to convert binary tree to double linked list  

/* A binary tree node has data, and left and right pointers */
public class Node
{
	public int data;
	public Node left, right;

	public Node(int item)
	{
		data = item;
		left = right = null;
	}
}

public class BineryTree
{
	public Node root;
	/* This is the core function to convert Tree to list. This function follows steps 1 and 2 of the above algorithm */
	public virtual Node bintree2listUtil(Node node)
	{
		// base case
		if (node == null)
		{
			return node;
		}

		// convert the left subtree and link to root
		if (node.left != null)
		{
			// Convert the left subtree 
			Node left = bintree2listUtil(node.left);

			// Find inorder predecessor. After this loop, left will point to the inorder predecessor
			for (; left.right != null; left = left.right)
			{
				;
			}

			// Make root as next of the predecessor
			left.right = node;
			// Make predecessor as previous of root
			node.left = left;
		}

		// Convert the right subtree and link to root
		if (node.right != null)
		{
			// Convert the right subtree
			Node right = bintree2listUtil(node.right);

			// Find inorder successor. After this loop, right will point to the inorder successor
			for (; right.left != null; right = right.left)
			{
				;
			}

			// Make root as previous of successor
			right.left = node;
			// Make successor as next of root
			node.right = right;
		}

		return node;
	}

	public virtual Node bintree2list(Node node)
	{
		// base case
		if (node == null)
		{
			return node;
		}

		// Convert to DLL using bintree2listUtil()
		node = bintree2listUtil(node);

		// bintree2listUtil() returns root node of  the converted DLL. 
		//We need pointer to the leftmost node which is head of the constructed DLL, so move to the leftmost node
		while (node.left != null)
		{
			node = node.left;
		}

		return node;

	}

	/* Function to print modes in a given doubly linked list */
	public virtual void printList(Node node)
	{
		while (node != null)
		{
			Console.Write(node.data + " ");
			node = node.right;
		}
	}

	/* Driver program to test above funstions */
	public static void Main(string[] args)
	{
		BineryTree tree = new BineryTree();

		// Let us create the tree shown in above diagram
		tree.root = new Node(10);
		tree.root.left = new Node(12);
		tree.root.right = new Node(15);
		tree.root.left.left = new Node(25);
		tree.root.left.right = new Node(30);
		tree.root.right.left = new Node(36);

		// Convert to DLL
		Node head = tree.bintree2list(tree.root);

		// Print the converted list
		tree.printList(head);

		System.Console.ReadKey();
	}
}

//namespace Cs_Vector_List
//{
//	class Program
//	{
//		static void Main(string[] args)
//		{
//		}
//	}
//}
