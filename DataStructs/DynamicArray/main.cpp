#include <iostream>
#include "DynArray.h"
#include "LinkedList.h"

int main()
{
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
	std::cout << "\nLIST STUFF \n";
	LinkedList<int> list;
	LinkedList<int>::Iterator it;
	list.pushFront(2);
	list.pushFront(4);
	list.pushFront(6);
	list.pushBack(100);
	it = list.begin();
	std::cout << list.popBack() << std::endl;
	std::cout << *it <<std::endl;
	it++; it++;// it++;
	std::cout << *it << std::endl;
	
	std::cin.get();
	std::cin.ignore();
	std::cin.get();
	return 0;
}
