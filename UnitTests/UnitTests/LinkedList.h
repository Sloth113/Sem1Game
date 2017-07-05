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

	LinkedList() 
	{
		m_first = nullptr; 
		m_last = nullptr; 
	}
	~LinkedList()
	{
		this->clear();
	}

	void pushBack(T value)
	{
		if (m_last != nullptr)
		{
			//If something exists
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
	void pushFront(T value)
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

	void insert(Iterator it, T value)
	{
			ListNode<T> * node = m_first;

			for (Iterator i = this->begin(); i != it; i++)
			{
				node = node->next;
			}
			//Insert value in t next value
			if (node == m_last)
			{
				this->pushBack(value);
			}
			else
			{
				node->next->prev = new ListNode<T>();//new node and set the next nodes previous to it
				node->next->prev->data = value;//new nodes data
				node->next->prev->next = node->next;//Set new nodes next to old next
				node->next = node->next->prev;//Current node point to new 
				node->next->prev = node;//set new nodes previous to current

			}
	}

	Iterator begin() { return Iterator(m_first); }
	Iterator end() { return Iterator(nullptr); }

	T first()
	{
		return m_first->data;
	}
	T last()
	{
		return m_last->data;
	}

	int count()
	{
		int count = 0;
		for(Iterator i = this->begin(); i != this->end(); i++)
		{
			count++;
		}
		return count;
	}

	void erase(Iterator it)
	{
		ListNode<T> * node = m_first;
		for (Iterator i = this->begin(); i != it; i++)
			node = node->next;
		
		if (node == m_last)
		{
			this->popBack();
		}
		else if (node == m_first)
		{
			this->popFront();
		}
		else
		{
			node->next->prev = node->prev;
			node->prev->next = node->next;
			delete node;
		}
	}
	void remove(T value)
	{
		ListNode<T> * node = m_first;

		while(node != nullptr)
		{
			if(node->data == value){
				if (node == m_first)
				{
					node = node->next;
					this->popFront();
				}
				else if (node == m_last)
				{
					node = nullptr;
					this->popBack();
				}
				else
				{
					ListNode<T> * tmp = node;
					node = node->next;
					tmp->next->prev = tmp->prev;
					tmp->prev->next = tmp->next;
					delete tmp;
				}
			}
			else
			{
				node = node->next;
			}
		}
	}

	T popBack()
	{
		if (m_first == m_last)
		{
			T value = m_first->data;
			delete m_first;
			m_first = nullptr;
			m_last = nullptr;
			return value;
		}
		else
		{
			T value = m_last->data;
			m_last = m_last->prev; //new last
			delete (m_last->next); //delete data
			m_last->next = nullptr; //set pointer
			return value;
		}
	}
	T popFront()
	{
		if (m_first == m_last)
		{
			T value = m_first->data;
			delete m_first;
			m_first = nullptr;
			m_last = nullptr;
			return value;
		}
		else
		{
			T value = m_first->data;
			m_first = m_first->next;
			delete(m_first->prev);
			m_first->prev = nullptr;
			return value;
		}
	}

	bool empty()
	{
		this->isEmpty();
	}

	void clear()
	{
		while(m_first != m_last){
			this->popFront();
		}
		delete m_first;
		m_first = nullptr;
		m_last = nullptr;
	}

	bool isEmpty() 
	{ 
		return begin() == Iterator(nullptr) && end() == Iterator(nullptr); 
	}

	//void remove(predicate); pass in condition
	
private:
	ListNode<T>* m_first;
	ListNode<T>* m_last;
};