#pragma once

#include "LinkedQueue.h"

template <typename T> 
class Extended_LinkedQueue :public LinkedQueue
{

	void Update() const
	{
		Node<T>* ptr = frontPtr;
		while (ptr)
		{
			cout << ptr->getItem() << " ";
			ptr = ptr->getNext();
		}
		cout << endl;
	}

};