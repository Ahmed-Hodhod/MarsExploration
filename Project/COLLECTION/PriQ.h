#include <iostream>

using namespace std;

template < typename T>
class Node
{
private:
	T item; // A data item
	int priority; 
	Node<T>* next; // Pointer to next node
public:
	Node();
	Node(const T& r_Item);
	Node(const T& r_Item, int pri);
	Node(const T& r_Item, Node<T>* nextNodePtr);
	void setItem(const T& r_Item);
	void setNext(Node<T>* nextNodePtr);
	void setPriority(int p);
	T getItem() const;
	int getPriority() const;
	Node<T>* getNext() const;
}; // end Node

template < typename T>
Node<T>::Node()
{
	next = nullptr;
}

template < typename T>
Node<T>::Node(const T& r_Item)
{
	item = r_Item;
	next = nullptr;
}

template<typename T>
 Node<T>::Node(const T& r_Item, int pri)
{
	 item = r_Item;
	 priority = pri;
}

template < typename T>
Node<T>::Node(const T& r_Item, Node<T>* nextNodePtr)
{
	item = r_Item;
	next = nextNodePtr;
}
template < typename T>
void Node<T>::setItem(const T& r_Item)
{
	item = r_Item;
}

template < typename T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
	next = nextNodePtr;
}

template<typename T>
 void Node<T>::setPriority(int p)
{
	 priority = p;
}

template < typename T>
T Node<T>::getItem() const
{
	return item;
}

template<typename T>
 int Node<T>::getPriority() const
{
	return priority;
}

template < typename T>
Node<T>* Node<T>::getNext() const
{
	return next;
}


template <typename T>
class LinkedQueue
{
private:

	Node<T>* backPtr;
	Node<T>* frontPtr;
public:
	LinkedQueue();
	bool isEmpty() const;
	void enqueue(const T& newEntry , int pri );
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	void print() const;
	int getCapacity() const;
	~LinkedQueue();

	//copy constructor
	LinkedQueue(const LinkedQueue<T>& LQ);
};

/*
Function: Queue()
The constructor of the Queue class.

*/
template <typename T>
LinkedQueue<T>::LinkedQueue()
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
bool LinkedQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/
template <typename T>

	void LinkedQueue<T>::enqueue(const T & newEntry, int pri)
	{
		Node<T>* newNodePtr = new Node<T>(newEntry, pri);
		if (isEmpty()) {
			frontPtr = newNodePtr;
			backPtr = newNodePtr;
			return;
		}
		if (frontPtr->getPriority() < pri) {
			newNodePtr->setNext( frontPtr);
			frontPtr = newNodePtr;
			backPtr = frontPtr;
			newNodePtr->setNext(NULL);
		}
		else if (pri < backPtr->getPriority()) {
			newNodePtr->setNext(NULL);
			backPtr->setNext(newNodePtr);
			newNodePtr->setNext(backPtr);
		}
		else {
			Node<T>* Nptr = frontPtr;
			while (Nptr->getNext() && Nptr->getNext()->getPriority() > pri) {
				Nptr = Nptr->getNext();
			}
			newNodePtr->setNext( Nptr->getNext());
			Nptr->setNext(newNodePtr);
		}
		return;
	}
 // end enqueue

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/
template <typename T>
bool LinkedQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued node
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
bool LinkedQueue<T>::peek(T& frntEntry) const
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
LinkedQueue<T>::~LinkedQueue()
{
	T temp;

	//Free (Dequeue) all nodes in the queue
	while (dequeue(temp));
}

/*
Function: Copy constructor
To avoid shallow copy,
copy constructor is provided

Input: LinkedQueue<T>: The Queue to be copied
Output: none
*/
template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& LQ)
{
	Node<T>* NodePtr = LQ.frontPtr;
	if (!NodePtr) //LQ is empty
	{
		frontPtr = backPtr = nullptr;
		return;
	}

	//insert the first node
	Node<T>* ptr = new Node<T>(NodePtr->getItem());
	frontPtr = backPtr = ptr;
	NodePtr = NodePtr->getNext();

	//insert remaining nodes
	while (NodePtr)
	{
		Node<T>* ptr = new Node<T>(NodePtr->getItem());
		backPtr->setNext(ptr);
		NodePtr = NodePtr->getNext();
	}
}

template<typename T>
void LinkedQueue<T>::print() const
{
	Node<T>* ptr = frontPtr;
	while (ptr)
	{
		cout << ptr->getItem() << " ";
		ptr = ptr->getNext();
	}
	cout << endl;
}
template<typename T>
int LinkedQueue<T> ::getCapacity() const {
	int capacity = 0;
	Node<T>* ptr = frontPtr;
	while (ptr) {
		++capacity;
		ptr = ptr->getNext();
	}
	return capacity;
}


