#pragma once
#pragma once
template<typename T>
class L_Node
{
private:
	T item;
	L_Node<T>* next;
public:
	L_Node()
	{
		next = nullptr;
	}
	L_Node(T newItem)
	{
		item = newItem;
		next = nullptr;
	}
	void setItem(T newItem)
	{
		item = newItem;
	}
	void setNext(L_Node<T>* nextNodePtr)
	{
		next = nextNodePtr;
	}
	T getItem() const
	{
		return item;
	}
	L_Node<T>* getNext() const
	{
		return next;
	}
};
//////////////////////LinkedList/////////////////
template <typename T>
class LinkedList
{
private:
	L_Node<T>* Head;

public:

	LinkedList()
	{
		Head = nullptr;
	}


	// OZER changed 
	void remove(  T & entry)
	{
		L_Node<T>* Lptr = Head;
		Head = Head->getNext();
		entry = Lptr->getItem();
	}

	void setHead(L_Node<T>* ptr) {
		Head = ptr;
	}

	void InsertEnd(const T& data)
	{
		L_Node<T>* R = new L_Node<T>(data);
		if (!Head)
		{
			Head = R;
			return;
		}
		L_Node<T>* p = Head;
		while (p->getNext())
			p = p->getNext();
		p->setNext(R);
	}
	

	bool isEmpty()
	{
		if (Head != nullptr)
		{
			return false;
		}
		return true;
	}
	void DeleteAll()
	{
		L_Node<T>* ptr = Head;
		while (Head)
		{
			ptr = Head->getNext();
			delete Head;
			Head = ptr;
		}
	}
	int GetSize()
	{
		int c = 0;
		L_Node<T>* ptr = Head;
		while (ptr)
		{
			c++;
			ptr = ptr->getNext();
		}
	}

	void print() {
		L_Node<T>* ptr = Head;
		while (ptr) {
			cout << ptr->getItem() << "  ";
			ptr = ptr->getNext();
		}
	}

	L_Node<T>* getHead() {
		return Head;
	}

	~LinkedList()
	{
		DeleteAll();
	}
};


