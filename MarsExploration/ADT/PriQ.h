#pragma once

#include <iostream>

using namespace std;

template < typename B>
class PNode
{
private:
	B item; // A data item
	int priority;
	PNode<B>* next; // Pointer to next PNode
public:
	PNode();
	PNode(const B& r_Item);
	PNode(const B& r_Item, int pri);
	PNode(const B& r_Item, PNode<B>* nextNodePtr);
	void setItem(const B& r_Item);
	void setNext(PNode<B>* nextNodePtr);
	void setPriority(int p);
	B getItem() const;
	int getPriority() const;
	PNode<B>* getNext() const;
}; 

template < typename T>
PNode<T>::PNode()
{
	next = nullptr;
}

template < typename T>
PNode<T>::PNode(const T& r_Item)
{
	item = r_Item;
	next = nullptr;
}

template<typename T>
 PNode<T>::PNode(const T& r_Item, int pri)
{
	 item = r_Item;
	 priority = pri;
}

template < typename T>
PNode<T>::PNode(const T& r_Item, PNode<T>* nextNodePtr)
{
	item = r_Item;
	next = nextNodePtr;
}
template < typename T>
void PNode<T>::setItem(const T& r_Item)
{
	item = r_Item;
}

template < typename T>
void PNode<T>::setNext(PNode<T>* nextNodePtr)
{
	next = nextNodePtr;
}

template<typename T>
 void PNode<T>::setPriority(int p)
{
	 priority = p;
}

template < typename T>
T PNode<T>::getItem() const
{
	return item;
}

template<typename T>
 int PNode<T>::getPriority() const
{
	return priority;
}

template < typename T>
PNode<T>* PNode<T>::getNext() const
{
	return next;
}


template <typename A>
class PQueue
{
private:

	PNode<A>* backPtr;
	PNode<A>* frontPtr;
public:
	PQueue();
	bool isEmpty() const;
	void enqueue(const A& newEntry , int pri );
	bool dequeue(A& frntEntry);
	bool peek(A& frntEntry)  const;
	void print() const;
	int getCapacity() const;
	~PQueue();
	PNode<A>* get_FrontPtr();

	//copy constructor
	PQueue(const PQueue<A>& LQ);
};

/*
Function: Queue()
The constructor of the Queue class.

*/
template <typename T>
PQueue<T>::PQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool PQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/
template <typename T>
	void PQueue<T>::enqueue(const T & newEntry, int pri)
	{
		PNode<T>* newNodePtr = new PNode<T>(newEntry, pri);
		
		if (isEmpty()) {
			// TEST 
			frontPtr = newNodePtr;
			backPtr = newNodePtr;
			
			return;
		}
		if (frontPtr->getPriority() < pri) {
			newNodePtr->setNext( frontPtr);
			frontPtr = newNodePtr;
			return;
		}
		else {
			PNode<T>* Nptr = frontPtr;
			while (Nptr->getNext() && Nptr->getNext()->getPriority() > pri) {
				Nptr = Nptr->getNext();
			}
			newNodePtr->setNext( Nptr->getNext());
			Nptr->setNext(newNodePtr);
			return;
		}
		
		
	}
 // end enqueue

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/
template <typename T>
bool PQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	PNode<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: last PNode in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued PNode
	delete nodeToDeletePtr;

	return true;

}

/*
Function: peek
copies the front of this queue to the passed param. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
*/
template <typename T>
bool PQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}

/*
Function: destructor
removes all nodes from the queue by dequeuing them
*/
template <typename T>
PQueue<T>::~PQueue()
{
	T temp;

	//Free (Dequeue) all nodes in the queue
	while (dequeue(temp));
}

/*
Function: Copy constructor
To avoid shallow copy,
copy constructor is provided

Input: PQueue<T>: The Queue to be copied
Output: none
*/
template <typename T>
PQueue<T>::PQueue(const PQueue<T>& LQ)
{
	PNode<T>* NodePtr = LQ.frontPtr;
	if (!NodePtr) //LQ is empty
	{
		frontPtr = backPtr = nullptr;
		return;
	}

	//insert the first PNode
	PNode<T>* ptr = new PNode<T>(NodePtr->getItem());
	frontPtr = backPtr = ptr;
	NodePtr = NodePtr->getNext();

	//insert remaining nodes
	while (NodePtr)
	{
		PNode<T>* ptr = new PNode<T>(NodePtr->getItem());
		backPtr->setNext(ptr);
		NodePtr = NodePtr->getNext();
	}
}

template<typename T>
void PQueue<T>::print() const
{
	PNode<T>* ptr = frontPtr;
	while (ptr)
	{
		cout << ptr->getItem() << " ";
		ptr = ptr->getNext();
	}
	cout << endl;
}
template<typename T>
int PQueue<T> ::getCapacity() const {
	int capacity = 0;
	PNode<T>* ptr = frontPtr;
	while (ptr) {
		++capacity;
		ptr = ptr->getNext();
	}
	return capacity;
}


template<typename T>
inline PNode<T>* PQueue<T>::get_FrontPtr()
{
	return frontPtr;
}