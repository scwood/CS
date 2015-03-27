#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include "Node.h"

template<class T>
class LinkedList<T>  : public LinkedListInterface<T>{
public:
	Node<T>* head;
	int size_bin;
	~LinkedList() {
		clear();
	}
	LinkedList() {
		head = NULL;
		size_bin = 0;
	}
	bool search(T value) {
		Node<T>* go = head;
		while (go != NULL) {
			if (go->data == value) {
				go = NULL;
				return true;
			}
			go = go->next_node;
		}
		return false;
	}
	void insertHead(T value) {
		if (search(value)) {
			return;
		}
		Node<T>* temp = new Node<T>(value);
		temp->next_node = head;
		head = temp;
		size_bin++;
		return;
	}
	void insertTail(T value) {
		if (search(value)) {
			return;
		}
		if (head == NULL) {
			insertHead(value);
		} else {
			Node<T>* go = head;
			Node<T>* previous;
			while (go != NULL) {
				previous = go;
				go = go->next_node;
			}
			Node<T>* temp = new Node<T>(value);
			previous->next_node = temp;
			size_bin++;
		}
		return;
	}
	void insertAfter(T value, T insertionNode) {
		if(search(value)) {
			return;
		}
		if(!search(insertionNode)) {
			return;
		}
		Node<T>* go = head;
		while (go->data != insertionNode) {
			go = go->next_node;
		}
		Node<T>* next_temp = go->next_node;
		Node<T>* temp = new Node<T>(value);
		go->next_node = temp;
		temp->next_node = next_temp;
		size_bin++;
		return;
	}
	void remove(T value) {
		if(!search(value)) {
			return;
		}
		Node<T>* go = head;
		Node<T>* previous;
		while (go->data != value) {
			previous = go;
			go = go->next_node;
		} 
		if (go == head) {
			head = go->next_node;
			delete go;
			size_bin--;
			return;
		}
		previous->next_node = previous->next_node->next_node;
		delete go;
		size_bin--;
		return;
	}
	void clear() {
		while (head != NULL) {
			T thing = head->data;
			remove(thing);
		}
	}
	T at(int index) {
		if (index > (size_bin - 1) || index < 0) {
			return NULL;
		}
		T val;
		Node<T>* go = head;
		for (int i = 0; i < index; i++) {
			go = go->next_node;
		}
		val = go->data;
		return val;
	}
	int size() {
		return size_bin;
	}
	void print() {
		Node<T>* go = head;
		while (go != NULL)
		{
			std::cout << "\n" << go->data;
			go = go->next_node;
		}
		return;
	}
};

#endif /* LINKEDLIST_H_ */
