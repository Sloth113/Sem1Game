#include <iostream>
#include "DynArray.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

int main()
{
	//Arrays
	/*
	DynArray<int> ar = DynArray<int>();
	DynArray<int> ar2 = DynArray<int>();

	int * nums = new int[5];
	for(int i = 0; i <= 5; i++){
		nums[i] = 100 + i;
	}

	for (int i = 0; i < 50; i++)
	{
		ar.add(i);
	}
	for (int i = 0; i < 10; i++)
	{
		ar2.add(i*10);
	}
	//ar.add(99, 3);
	//ar.add(nums, 5, 5);
	//ar.pop();
	//ar.remove(5);
	//ar.sort();
	//ar.add(ar2);
	//ar.shuffle();
	//ar.sort();
	//ar.rotate(-5);
	for (int i = 0; i < ar.getSize(); i++)
	{
		std::cout << ar[i] << ' ';
	}
	//
	*/

	//std::cout << "\nLIST STUFF \n";
	/*
	LinkedList<int> list;
	LinkedList<int>::Iterator it;
	list.pushFront(2);

	for (LinkedList<int>::Iterator i = list.begin(); i != list.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << '\n';
	list.pushFront(4);
	
	list.pushFront(6);
	std::cout << "Count:" << list.count() << std::endl;
	list.pushBack(10);
	it = list.begin(); //1st
	it++;//2nd
	it++;//3d
	list.insert(it, 23);//insert after 3rd
	it--;
	std::cout << *it << std::endl;
	list.erase(it);//remember to reset it, it doesnt exist any more 
	it = list.begin();
	it++;
	it++;
	//list.popBack();
	std::cout << *it << ';' << &it << std::endl;

	list.pushFront(1);
	list.insert(it, 1);
	list.pushBack(1);
	std::cout << "Count:" << list.count() << std::endl;
	for (LinkedList<int>::Iterator i = list.begin(); i != list.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	list.remove(1);
	list.popFront();

	list.popFront();

	list.popFront();
	list.popFront();
	std::cout << "Count:" << list.count() << std::endl;
	for (LinkedList<int>::Iterator i = list.begin(); i != list.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	*/
	//Stacks
	/*
	Stack<int> s = Stack<int>(5);
	s.push(20);
	s.push(10);
	s.push(20);
	s.push(10);
	s.push(20);
	s.push(10);
	s.push(20);
	s.push(10);

	int size = s.size();
	for(int i = 0; i < size; i++){
		std::cout << s.pop() << '.';
	}
	std::cout << std::endl;
	*/
	
	Queue<int> q = Queue<int>();
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	std::cout << q.pop() <<std::endl;
	std::cout << q.pop() << std::endl;
	std::cout << q.pop() << std::endl;
	std::cout << q.top() << std::endl;
	
	std::cin.get();
	std::cin.ignore();
	std::cin.get();
	return 0;
}
