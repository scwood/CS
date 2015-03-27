#ifndef NODE_H_
#define NODE_H_

#include <cstddef>

template <class T>

class Node
{
public:
	T data;
	Node<T>* next_node;
	~Node(){}
	Node (T data)
	{
		this->data = data;
		next_node = NULL;
	}
};

#endif /* NODE_H_ */