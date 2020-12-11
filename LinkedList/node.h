
#pragma once

#include <iostream>

template<class T>
class LinkedList;

template<class T>
class Node
{
	friend class LinkedList<T>;

public:
	Node();
	Node(T);
	T getData();
	Node<T>* getNext() { return next; }
	Node<T>* getPrev() { return prev; }

	friend ostream& operator <<( ostream & out, const Node<T> &node)
	{
		out << node.data;
		return out;
	}

private:
	T data;
	Node<T> *next;
	Node<T> *prev;
};

template <class T>
Node<T>::Node()
{
	data=nullptr;
	next=0;
	prev=0;
}

template<class T>
Node<T>::Node(T node)
{
	data=node;
	next=0;
	prev=0;
}

template<class T>
T Node<T>::getData()
{
	return data;
}

