#pragma once

#include "node.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void addAtFront(T node);
	void addAtBack(T node);
	void addAfterNode(T oldNode, T nodeToInsert);
	void removeNode(T node);

	void printList();
	int size();

	template<class TT>
	friend ostream &operator << (ostream &out , const LinkedList<TT> *obj)
	{
		Node<TT> *temp=obj.head;
		while (temp != nullptr)
		{
			out << *temp->getData() << endl;
			temp=temp->getNext();
		}
		cout << endl;
	}

private:
	Node<T> *head;
};

template<class T>
LinkedList<T>::LinkedList() :head(0)
{

}

template<class T>
LinkedList<T>::~LinkedList()
{
	Node<T> *node=head;
	Node<T> *tempNode;

	while (node != nullptr)
	{
		tempNode=node;
		node=node->next;
		delete tempNode;
	}
}

template<class T>
void LinkedList<T>::addAtFront(T node)
{
	Node<T> *newNode=new Node<T>();
	newNode->data=node;

	if (head == nullptr)
	{
		head = newNode;
		newNode->next=nullptr;
		newNode->prev=nullptr;
		return;
	}
	newNode->next=head;
	head->prev=newNode;
	head=newNode;
}

template <class T>
void LinkedList<T>::addAtBack(T node)
{
	Node<T> *newNode=new Node<T>();
	newNode->data=node;
	if (head == nullptr)
	{
		head=newNode;
		return;
	}
	Node<T> *tmpNode=head;
	while (tmpNode->next != nullptr)
	{
		tmpNode=tmpNode->next;
	}

	tmpNode->next=newNode;
	newNode->prev=tmpNode;

}

template <class T>
void LinkedList<T>::addAfterNode(T oldNode, T nodeToInsert)
{
	Node *newNode = new Node<T>();
	newNode->data=nodeToInsert;

	Node *oNode=new Noded<T>();
	oNode->data=oldNode;

	if (head == nullptr)
	{
		head=newNode;
	}
	else
	{
		Node<T> *tempNode=head, *tmp2;
		while (tempNode->data == oNode->data)
		{
			if (tempNode->next == nullptr)
			{
				cout << "node not found in the list" << endl;
				break;
			}
			else
			{
				tempNode=tempNode->next;
			}
		}
		tmp2=tempNode->next;
		tempNode->next=newNode;
		newNode->next=tmp2;
		tmp2->prev=newNode;
	}
}

template <class T>
void LinkedList<T>::removeNode(T node)
{
	Node<T> *tmpNode, *tmpNode2;
	if (head == nullptr)
	{
		cout << "List is empty";
		return ;
	}
	else if (head->data == node)
	{
		tmpNode=head;
		if (head->next != nullptr)
		{
			head=head->next;
			head=>prev=nullptr;
			delete tmpNode;
			tmpNode=nullptr;
		}
		else {
			delete head;
			head->prev=nullptr;
			delete tmpNode;
			tmpNode=nullptr;
			return;
		}
	}

	tmpNode2=head;
	while (tmpNode2->next->next != nullptr)
	{
		if (tmpNode2->next->data == node)
		{
			tmpNode = tmpNode2->next;
			tmpNode2->next=tmpNode->next;
			tmpNode->next->prev=tmpNode2;
			delete tmpNode;
			tmpNode=nullptr;
			return;
		}
		tmpNode2=tmpNode2->next;
	}
	if (tmpNode2->next->data == node)
	{
		tmpNode=tmpNode2->next;
		delete tmpNode;
		tmpNode=nullptr;
		tmpNode2->next=nullptr;
		return;
	}
	cout << "Element not found" << endl;
}

template <class T>
int LinkedList<T>::size()
{
	if (head == nullptr)
	{
		return 0;
	}
	Node<T> *tmp=head;
	int nodeCounter=0;

	while (temp != nullptr)
	{
		nodeCounter +=1;
		tmp = tmp->next;
	}
	return nodeCounter;
}

template <class T>
void LinkedList<T>::printList()
{
	Node<T> *tmp=head;
	if (tmp == nullptr)
	{
		cout << "List is empty" << endl;
	}
	if (tmp->next == nullptr)
	{
		cout << tmp->data << endl;
		return;
	}
	else
	{
		while (tmp != nullptr)
		{
			cout << tmp->data << endl;
			tmp=tmp->next;
		}
	}
	cout << "Print List" << endl;
}

