#pragma once
#include "Node.h"
#include "Vehicle.h"
#include <iostream> 
#include <vector> 
template <class T> class LinkedList
{
public:
	LinkedList();
	LinkedList(Node<T>*);
	~LinkedList();
	void push(Node<T>*);
	void remove(int id);
	void print();
	void generateVector(std::vector<T*> &a);
private:
	Node<T>* head;
};
