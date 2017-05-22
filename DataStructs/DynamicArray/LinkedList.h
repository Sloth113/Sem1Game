#pragma once
template<typename T>
class ListNode
{
public:
	ListNode * next;
	ListNode * prev;
	T data;
};

template<typename T>
class LinkedList
{
public:
	class Iterator
	{
	public:
		Iterator() {}
		Iterator(ListNode<T> * node) : m_node(node) {}
		//no checks to see if end of list
		void operator ++ () { m_node = m_node->next; }
		void operator ++ (int) { m_node = m_node->next; }
		void operator -- () { m_node = m_node->prev; }
		void operator -- (int) { m_node = m_node->prev; }
		T& operator * () { return m_node->data; }
		T* operator -> () { return &m_node->data; }
		bool operator == (const Iterator& rh) { return m_node == rh.m_node; }
		bool operator != (const Iterator& rh) { return m_node != rh.m_node; }

		ListNode<T> * getNode() { return m_node; }
	private:
		ListNode<T> * m_node = nullptr;
	};

	LinkedList() { m_first = nullptr; m_last = nullptr; }
//	~LinkedList();

	void pushFront(T value)
	{
		if (m_last != nullptr)
		{
			m_last->next = new ListNode<T>();//new node
			//Set up new node
			m_last->next->data = value;//set data
			m_last->next->next = nullptr;
			m_last->next->prev = m_last;//set prev on new node to old last
			//set new last node
			m_last = m_last->next;
		}
		else
		{
			//First node
			m_first = new ListNode<T>();
			m_last = m_first;
			m_first->next = nullptr;
			m_first->prev = nullptr;
			m_first->data = value;
		}

	}
	void			pushBack(T value)
	{
		if (m_first != nullptr)
		{
			m_first->prev = new ListNode<T>();//new value
			//New node set up
			m_first->prev->data = value; //set data
			m_first->prev->prev = nullptr;
			m_first->prev->next = m_first;//set next value on new node to old first
			//set new first node 
			m_first = m_first->prev; 
		}
		else
		{
			//first node
			m_first = new ListNode<T>();
			m_last = m_first;
			m_first->next = nullptr;
			m_first->prev = nullptr;
			m_first->data = value;
		}
	}

	void insert(Iterator i, T value);

	Iterator begin() { return Iterator(m_first); }
	Iterator end() { return Iterator(nullptr); }//?

	T first()
	{
		return m_first->data;
	}
	T last()
	{
		return m_last->data;
	}

	int count();

	void erase(Iterator i);
	void remove(T value);

	T popBack()
	{
		m_last->prev->next = nullptr; //remove from list
		T value = m_last->data;
		//Delete last
//		~m_last;
		m_last = m_last->prev;//Set new last
		return value;
	}
	T popFront();

	bool empty()
	{
		this->isEmpty();
	}

	void clear();

	bool isEmpty() { return begin() == end(); }

	//void remove(predicate); pass in condition


private:
	ListNode<T>* m_first;
	ListNode<T>* m_last;

};