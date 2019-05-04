#include "pch.h"
#include "LinkedList.h"
#include "Node.h"
#include <iostream> 
#include <vector> 

template<class T>
inline LinkedList<T>::LinkedList()
{
	this->head = nullptr;
}

template<class T>
LinkedList<T>::LinkedList(Node<T>* init)
{
	this->head = init;
}

template<class T>
inline LinkedList<T>::~LinkedList()
{
	delete head;
}


template<class T>
void LinkedList<T>::push(Node<T>* node)
{

	if (this->head == nullptr || node->getData()->get_hp() > this->head->getData()->get_hp())
	{
		node->setNext(head);
		this->head = node;
	}
	else {
		Node<T>* current = head;
		Node<T>* previous = nullptr;

		while (current->getNext() != nullptr && current->getNext()->getData()->get_hp() > node->getData()->get_hp()) 
		{
			previous = current;
			current = current->getNext();
		}
		if (current->getNext() == nullptr)
			current->setNext(node);
		else {
			previous = current;
			current = current->getNext();
			previous->setNext(node);
			node->setNext(current);
		}
	}
}

template<class T>
void LinkedList<T>::remove(int id)
{
	std::cout << "Removing vehicle with id " << id << "!" << std::endl;
	Node<T> * prev = nullptr;
	Node<T> * current = this->head;
	int i = 1;
	while (current) {
		if (i == id) {
			if (id == 1) {
				this->head = current->getNext();
			}
			else {
				std::cout << current->getData()->get_hp() << std::endl;

				prev->setNext(current->getNext());
			}
			std::cout << "Successfully removed vehicle with id " << id << "!" << std::endl;
			current->~Node();
			break;
		}
		i++;

		prev = current;
		current = current->getNext();
	}

	std::cout << "Was not able to remove vehicle with id " << id << "!" << std::endl;
}

template<class T>
void LinkedList<T>::print()
{
	std::cout << "On the starting line!" << std::endl;
	Node<T> * current = this->head;
	int i = 1;
	while (current) {
		std::cout << i << ". " << current->getData()->get_brand_name() << ", Horse power: " << current->getData()->get_hp() << std::endl;
		current = current->getNext();
		i++;
	}
}

template<class T>
void LinkedList<T>::generateVector(std::vector<T*>& a)
{
	Node<T> * current = this->head;

	while (current) {
		a.push_back(current->getData());

		current = current->getNext();
	}
}
