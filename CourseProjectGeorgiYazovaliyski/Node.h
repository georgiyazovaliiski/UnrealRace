#pragma once
template <class T> class Node
{
public:
	Node();
	Node(T* data);
	~Node();
	Node<T>* getNext();
	Node<T>* getPrev();
	T* getData();
	void setData(T* newData);
	void setNext(Node* newNext);
	void setPrev(Node* newPrev);

private:
	T* data;
	Node<T>* next;
	Node<T>* previous;
};
