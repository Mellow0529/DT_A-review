// my linked list. --mellow
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_


#include <iostream>

#if 0 
template <class Type>
class Node
{
public:
	friend class Linked_list<Type>;
private:
	Type data;
	Node<Type>* next;
};
#endif

template <class Type>
class Linked_list
{
public:
	Linked_list() :
		size(0), head(NULL) {}
	Linked_list(const Linked_list& L);
	~Linked_list();

	bool insertHead();
	bool insert(Type data, int position);
	bool push_back(Type data);
	bool find(int index, Type& x) const;
	bool remove(int position);
	bool print() const;

private:
	struct Node
	{
		Type data;
		struct Node* next = NULL;
	} node;

	struct Node* head;
	int size;
};


#endif // !LINKED_LIST_H_
