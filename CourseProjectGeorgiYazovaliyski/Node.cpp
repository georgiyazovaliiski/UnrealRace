#include "pch.h"
#include "Node.h"

template<class T>
inline Node<T>::Node()
{
	this->next = nullptr;
	this->previous = nullptr;
}

template<class T>
Node<T>::Node(T* data)
{
	this->data = data;
	this->next = nullptr;
	this->previous = nullptr;
}

template<class T>
inline Node<T>::~Node()
{
	delete data;
	setPrev(nullptr);
	setNext(nullptr);
}

template<class T>
Node<T>* Node<T>::getNext()
{
	return next;
}

template<class T>
Node<T>* Node<T>::getPrev()
{
	return previous;
}

template<class T>
T * Node<T>::getData()
{
	return data;
}

template<class T>
void Node<T>::setData(T * newData)
{
	this->data = newData;
}

template<class T>
void Node<T>::setNext(Node * newNext)
{
	this->next = newNext;
}

template<class T>
void Node<T>::setPrev(Node * newPrev)
{
	this->previous = newPrev;
}
