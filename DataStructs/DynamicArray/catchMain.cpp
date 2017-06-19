#include <iostream>
#include "DynArray.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <chrono>

void bubbleSort(int * const ar, int size);
void insertionSort(int * const ar, int size);
void mergeSort(int * const ar, int startIdx, int endIdx);
void merge(int * const ar, int startIdx, int midIdx, int endIdx);
void quickSort(int * const ar, int startIdx, int endIdx);
int partition(int * const ar, int startIdx, int endIdx);


//TESTS

bool dynarsEqual(DynArray<int> ar1, DynArray<int> ar2) {
	if (ar1.getSize() != ar2.getSize()) return false;
	for (int i = 0; i < ar1.getSize(); i++) 
	{
		if (ar1[i] != ar2[i]) {
			return false;
		}
	}
	return true;
}


TEST_CASE("TEST TEST", "[dynArray]")
{
	DynArray<int> ar = DynArray<int>();
	DynArray<int> ar2 = DynArray<int>();
	ar.add(1);
	ar.add(2);
	ar2.add(1);
	ar2.add(2);

	//REQUIRE(dynarsEqual(ar, ar2) == false);
//	REQUIRE(false);
	//Testing tests
	REQUIRE(true);
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::cin.get();

	REQUIRE(false);
}
//
//int main()
//{
//
//
//	//Arrays
//	/*
//	DynArray<int> ar = DynArray<int>();
//	DynArray<int> ar2 = DynArray<int>();
//
//	int * nums = new int[5];
//	for(int i = 0; i <= 5; i++){
//		nums[i] = 100 + i;
//	}
//
//	for (int i = 0; i < 50; i++)
//	{
//		ar.add(i);
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		ar2.add(i*10);
//	}
//	//ar.add(99, 3);
//	//ar.add(nums, 5, 5);
//	//ar.pop();
//	//ar.remove(5);
//	//ar.sort();
//	//ar.add(ar2);
//	//ar.shuffle();
//	//ar.sort();
//	//ar.rotate(-5);
//	for (int i = 0; i < ar.getSize(); i++)
//	{
//		std::cout << ar[i] << ' ';
//	}
//	//
//	*/
//
//	//std::cout << "\nLIST STUFF \n";
//	/*
//	LinkedList<int> list;
//	LinkedList<int>::Iterator it;
//	list.pushFront(2);
//
//	for (LinkedList<int>::Iterator i = list.begin(); i != list.end(); i++)
//	{
//		std::cout << *i << " ";
//	}
//	std::cout << '\n';
//	list.pushFront(4);
//
//	list.pushFront(6);
//	std::cout << "Count:" << list.count() << std::endl;
//	list.pushBack(10);
//	it = list.begin(); //1st
//	it++;//2nd
//	it++;//3d
//	list.insert(it, 23);//insert after 3rd
//	it--;
//	std::cout << *it << std::endl;
//	list.erase(it);//remember to reset it, it doesnt exist any more
//	it = list.begin();
//	it++;
//	it++;
//	//list.popBack();
//	std::cout << *it << ';' << &it << std::endl;
//
//	list.pushFront(1);
//	list.insert(it, 1);
//	list.pushBack(1);
//	std::cout << "Count:" << list.count() << std::endl;
//	for (LinkedList<int>::Iterator i = list.begin(); i != list.end(); i++)
//	{
//		std::cout << *i << " ";
//	}
//	std::cout << std::endl;
//	list.remove(1);
//	list.popFront();
//
//	list.popFront();
//
//	list.popFront();
//	list.popFront();
//	std::cout << "Count:" << list.count() << std::endl;
//	for (LinkedList<int>::Iterator i = list.begin(); i != list.end(); i++)
//	{
//		std::cout << *i << " ";
//	}
//	std::cout << std::endl;
//	*/
//	//Stacks
//	/*
//	Stack<int> s = Stack<int>(5);
//	s.push(20);
//	s.push(10);
//	s.push(20);
//	s.push(10);
//	s.push(20);
//	s.push(10);
//	s.push(20);
//	s.push(10);
//
//	int size = s.size();
//	for(int i = 0; i < size; i++){
//		std::cout << s.pop() << '.';
//	}
//	std::cout << std::endl;
//	*/
//	/*
//	Queue<int> q = Queue<int>();
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//
//	std::cout << q.pop() <<std::endl;
//	std::cout << q.pop() << std::endl;
//	std::cout << q.pop() << std::endl;
//	std::cout << q.top() << std::endl;
//	*/
//
//	//SORTING
//	const int size = 100;
//	int * values = new int[size];
//	int * valuesToSort = new int[size];
//
//
//	srand(time(nullptr));
//	//RANDOM SET
//	for (int i = 0; i < size; i++)
//	{
//		values[i] = rand() % size;
//	}
//
//	memcpy(valuesToSort, values, sizeof(int)*size); //copy 
//
//	//PRINT 
//	for (int i = 0; i < size; i++)
//	{
//		std::cout << values[i] << ",";
//	}
//
//	std::cout << std::endl << std::endl;
//	//Bubble sort
//	std::chrono::high_resolution_clock::time_point t1, t2;
//	t1 = std::chrono::high_resolution_clock::now();
//	bubbleSort(values, size);
//	t2 = std::chrono::high_resolution_clock::now();
//
//	for (int i = 0; i < size; i++)
//	{
//		std::cout << values[i] << ",";
//	}
//	std::cout << std::endl << std::endl;
//	std::cout << "Bubble sort took " << (t2 - t1).count() << " nanoseconds." << std::endl;
//
//
//
//
//	//pause 
//	std::cout << "Press to instertion sort" << std::endl;
//	std::cin.get();
//	std::cout << std::endl;
//
//
//
//	memcpy(values, valuesToSort, sizeof(int)*size); //copy random set back to values
//
//	//PRINT 
//	for (int i = 0; i < size; i++)
//	{
//		std::cout << values[i] << ",";
//	}
//
//	std::cout << std::endl << std::endl;
//	//Bubble sort
//	
//	t1 = std::chrono::high_resolution_clock::now();
//	insertionSort(values, size);
//	t2 = std::chrono::high_resolution_clock::now();
//
//	for (int i = 0; i < size; i++)
//	{
//		std::cout << values[i] << ",";
//	}
//	std::cout << std::endl << std::endl;
//	std::cout << "Insertion sort took " << (t2 - t1).count() << " nanoseconds." << std::endl;
//
//
//
//	//pause 
//	std::cout << "Press to merge sort" << std::endl;
//	std::cin.get();
//	std::cout << std::endl;
//
//	memcpy(values, valuesToSort, sizeof(int)*size); //copy random set back to values
//
//	//PRINT 
//	for (int i = 0; i < size; i++)
//	{
//		std::cout << values[i] << ",";
//	}
//
//	std::cout << std::endl << std::endl;
//	//Bubble sort
//
//	t1 = std::chrono::high_resolution_clock::now();
//	mergeSort(values, 0, size-1);
//	t2 = std::chrono::high_resolution_clock::now();
//
//	for (int i = 0; i < size; i++)
//	{
//		std::cout << values[i] << ",";
//	}
//	std::cout << std::endl << std::endl;
//	std::cout << "Merge sort took " << (t2 - t1).count() << " nanoseconds." << std::endl;
//
//
//	//pause 
//	std::cout << "Press to quick sort" << std::endl;
//	std::cin.get();
//	std::cout << std::endl;
//
//	memcpy(values, valuesToSort, sizeof(int)*size); //copy random set back to values
//
//													//PRINT 
//	for (int i = 0; i < size; i++)
//	{
//		std::cout << values[i] << ",";
//	}
//
//	std::cout << std::endl << std::endl;
//	//Bubble sort
//
//	t1 = std::chrono::high_resolution_clock::now();
//	quickSort(values, 0, size - 1);
//	t2 = std::chrono::high_resolution_clock::now();
//
//	for (int i = 0; i < size; i++)
//	{
//		std::cout << values[i] << ",";
//	}
//	std::cout << std::endl << std::endl;
//	std::cout << "Quick sort took " << (t2 - t1).count() << " nanoseconds." << std::endl;
//
//
//	delete[] values;
//	delete[] valuesToSort;
//
//
//	
//	std::cin.ignore(std::cin.rdbuf()->in_avail());
//	std::cin.get();
//	return 0;
//}

void bubbleSort(int * const ar, int size)
{
	for(int i = size -1; i > 0; i-- )
	{
		for (int j = 0; j < i ; j++)
		{
			if (ar[j] > ar[j + 1])
			{
				int tmp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = tmp;
			}
		}
	}
}

void insertionSort(int * const ar, int size)
{
	
	for (int i = 1; i < size; i++) 
	{
		int k = ar[i];
		int j = i - 1;
		while (j >= 0 && ar[j] > k) 
		{
			ar[j + 1] = ar[j];
			j = j - 1;
			ar[j + 1] = k;
		}
	}



}

void mergeSort(int * const ar, int startIdx, int endIdx) {
	if (startIdx < endIdx) 
	{
		int mid = (startIdx + endIdx) / 2;
		mergeSort(ar, startIdx, mid);
		mergeSort(ar, mid + 1, endIdx);
		merge(ar, startIdx, mid, endIdx);
	}
}
void merge(int * const ar, int startIdx, int midIdx, int endIdx) {
	int leftEnd = midIdx - startIdx + 1;
	int rightEnd = endIdx - midIdx;
	int * lAr = new int[leftEnd];
	int * rAr = new int[rightEnd];

	for (int i = 0; i < leftEnd; i++) 
	{
		lAr[i] = ar[startIdx + i];
	}

	for (int i = 0; i < rightEnd; i++)
	{
		rAr[i] = ar[midIdx + i  + 1];
	}

	int i = 0; 
	int j = 0;

	for (int k = startIdx; k <= endIdx; k++) 
	{
		if (j >= rightEnd || (i < leftEnd && lAr[i] <= rAr[j])) 
		{
			ar[k] = lAr[i];
			i++;
		}
		else
		{
			ar[k] = rAr[j];
			j++;
		}
	}

	delete[] lAr;
	delete[] rAr;
}

void quickSort(int * const ar, int startIdx, int endIdx)
{
	if (startIdx < endIdx)
	{
		int q = partition(ar, startIdx, endIdx);
		quickSort(ar, startIdx, q - 1);
		quickSort(ar, q + 1, endIdx);
	}
}
int partition(int * const ar, int startIdx, int endIdx)
{
	int x = ar[endIdx];
	int i = startIdx - 1;
	for (int j = startIdx; j < endIdx; j++) 
	{
		if (ar[j] <= x)
		{
			i++;
			int tmp = ar[i];
			ar[i] = ar[j];
			ar[j] = tmp;
		}
	}
	int tmp = ar[i + 1];
	ar[i + 1] = ar[endIdx];
	ar[endIdx] = tmp;
	return i + 1;
}


