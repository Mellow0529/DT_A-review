#include <iostream>
#include "linked_list.h"


template <class Type>
Linked_list<Type>::Linked_list(const Linked_list& L)
{
	this->node = L.node;
	this->size = L.size;
	this->head = L.head;
}

template <class Type>
Linked_list<Type>::~Linked_list()
{
	Node* temp;
	for (int i = 0; i < size; i++)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	temp = NULL;
}

template <class Type>
bool Linked_list<Type>::insertHead()
{
	this->head = new Node;
	size++;
	head->next = NULL;
	return true;
}


template <class Type>
bool Linked_list<Type>::insert(Type data, int position)
{
	if (position < 0 || position > size)
	{
		std::cout << "Invalid insert position." << std::endl;
		return false;
	}

	Node* newNode = new Node;
	Node* prior;
	prior = head;
	for (int i = 0; i < position; i++)
		prior = prior->next;

	newNode->data = data;
	newNode->next = prior->next;
	prior->next = newNode;
	size++;

	return true;
}

template <class Type>
bool Linked_list<Type>::push_back(Type data)
{
	Node* temp;
	temp = head;
	while (temp->next)
		temp = temp->next;

	Node* newNode = new Node;
	newNode->data = data;
	temp->next = newNode;
	newNode->next = NULL;
	size++;

	return true;
}

template <class Type>
bool Linked_list<Type>::find(int index, Type& x) const
{
	if (index <= 0 || index > size)
	{
		std::cout << "Index out of bounds." << std::endl;
		return false;
	}
	Node* p = head;
	for (int i = 0; i < index; i++)
	{
		p = p->next;
	}
	x = p->data;
	return true;
}

template <class Type>
bool Linked_list<Type>::remove(int position)
{
	if (position <= 0 || position > size)
	{
		std::cout << "Invalid remove position." << std::endl;
		return false;
	}

	Node* temp;
	Node* prior;
	prior = head;
	for (int i = 0; i < position - 1; i++)
		prior = prior->next;

	temp = prior->next;
	prior->next = temp->next;

	delete temp;
	temp = NULL;

	size--;
	return true;
}

template<class Type>
bool Linked_list<Type>::print() const
{
	Node* temp;
	temp = head->next;
	while (temp != NULL)
	{
		std::cout << temp->data << "->";
		temp = temp->next;
	}
	std::cout << "NULL" <<std::endl;
	return true;
}


int testLinkedList()
{
	Linked_list<int> myLinked_list;
	// int x;
	
	myLinked_list.insertHead();
	myLinked_list.push_back(1);
	myLinked_list.push_back(3);
	myLinked_list.push_back(6);
	myLinked_list.push_back(9);
	myLinked_list.print();
 	myLinked_list.remove(1);
	myLinked_list.print();
	myLinked_list.insert(8, 2);
	myLinked_list.print();

	return 0;
}