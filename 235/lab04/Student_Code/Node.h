/*
 * node.h
 *
 *  Created on: Oct 7, 2014
 *      Author: scwood
 */

#ifndef NODE_H_
#define NODE_H_

#include <string>
#include <iostream>

using namespace std;

template <class T>

class Node
{
public:

	//Stores the location of the data of the current mode
	T data;

	// Stores the location of the next node

	Node<T>* next_node;

	//Destructor
	~Node(){}

	//Constructor
	Node (T item)
	{
		this->data = item;
		this->next_node = NULL;
	}

};




#endif /* NODE_H_ */
