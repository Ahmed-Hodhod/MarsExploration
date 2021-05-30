#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"
template <typename T>
class LinkedList
{
private:
	Node<T>* Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
public:


	LinkedList()
	{
		Head = nullptr;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	void PrintList()	const
	{
		cout << "\nprinting list contents:\n\n";
		Node<T>* p = Head;

		while (p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "NULL\n";
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	*
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		R->setNext(Head);
		Head = R;

	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
	}



	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list
	void InsertEnd(const T& data);

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	bool Find(int Key);

	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
	int CountOccurance(const T& value);

	//[4] DeleteFirst
	//Deletes the first node in the list
	void DeleteFirst();

	void Reverse();



	//[5] DeleteLast
	//Deletes the last node in the list
	void DeleteLast();

	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNode(const T& value);

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNodes(const T& value);

	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L
	void Merge(const LinkedList& L);

	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)
//	Node<T>* Reverse();

	// Exercise 3
	void PrintKth(int Kth);




};

#endif	

template<typename T>
inline void LinkedList<T>::InsertEnd(const T& data)
{
	Node<T>* Item = new Node<T>(data);
	Node<T>* ptr = Head;
	if (!ptr)
	{
		Head = Item;
	}
	else
	{
		while (ptr->getNext())
		{
			ptr = ptr->getNext();
		}
		ptr->setNext(Item);
	}
}

template<typename T>
inline bool LinkedList<T>::Find(int Key)
{
	Node<T>* ptr = Head;
	while (ptr)
	{
		if (ptr->getItem() == Key) return true;
		ptr = ptr->getNext();
	}
	return false;
}

template<typename T>
inline int LinkedList<T>::CountOccurance(const T& value)
{
	int count = 0;
	Node<T>* ptr = Head;
	while (ptr)
	{
		if (ptr->getItem() == value) count++;
		ptr = ptr->getNext();
	}
	return count;
}

template<typename T>
inline void LinkedList<T>::DeleteLast()
{
	if (!Head) return;
	if (!Head->getNext())
	{
		Head = NULL;
		return;
	}

	Node<T>* prev, * current;
	while (current->getNext())
	{
		prev = current;
		current = current->getNext();
	}
	prev->setNext(NULL);
}

template<typename T>
inline bool LinkedList<T>::DeleteNode(const T& value)
{
	if (!Head) return false;

	while (Head->getItem() == value)
	{
		Head = Head->getNext();
	}

	Node<T>* ptr = Head;
	while (ptr && ptr->getNext())
	{
		if (ptr->getNext()->getItem() == value)
		{
			ptr->setNext(ptr->getNext()->getNext());
			return true;
		}
		ptr = ptr->getNext();
	}
	return false;

}


template <typename T>
inline void LinkedList<T>::PrintKth(int Kth)
{
	int count = 0;
	Node<T>* ptr = Head;
	while (ptr)
	{
		if (Kth == ++count)
		{
			std::cout << ptr->getItem();
			return;
		};
	}
	std::cout << "Beyond List Length. ";
}

template<typename T>
inline void LinkedList<T>::DeleteFirst()
{
	if (!Head) return;
	Node<T>* old = Head;
	Head = Head->getNext();
	delete old;
}

template<typename T>
inline void LinkedList<T>::Reverse()
{
	Node<T>* fast, * slow, * temp;
	slow = nullptr;
	fast = Head;
	while (fast)
	{
		temp = fast->getNext();
		fast->setNext(slow);
		slow = fast;
		fast = temp;
	}
	Head = slow;

}
