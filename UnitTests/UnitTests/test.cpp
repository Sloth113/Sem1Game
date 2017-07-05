#include "DynArray.h"
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"
#include "Graph.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

const bool INFO = true;
const bool PAUSE = true;

class TestClass
{
public:
	TestClass()
	{
		f = 1.0f;
		i = 2;
	}
	TestClass(float x, int y)
	{
		f = x;
		i = y;
	}
	int getInt() { return i; }
	float getFloat() { return f; }
	void setInt(int y) { i = y; }
	void setFloat(float x) { f = x; }
private:
	float f;
	int i;
};

bool dynarsEqual(DynArray<int> ar1, DynArray<int> ar2)
{
	if (ar1.getSize() != ar2.getSize()) return false;
	for (int i = 0; i < ar1.getSize(); i++)
	{
		if (ar1[i] != ar2[i])
		{
			return false;
		}
	}
	return true;
}

void printInfo(const char* str)
{
	std::cout << str;
	if (PAUSE)
	{
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin.get();
	}
}


TEST_CASE("Dynamic Array tests", "[test1]")
{
	DynArray<int> ar = DynArray<int>(10);

	REQUIRE(ar.getSize() == 0);
	if (INFO)printInfo("Passed size test1\n");

	ar.add(1);
	ar.add(2);
	ar.add(3);

	REQUIRE(ar.getSize() == 3);
	if (INFO)printInfo("Passed size and add test2\n");

	DynArray<int> ar2 = ar;
	REQUIRE(dynarsEqual(ar, ar2));
	if (INFO)printInfo("Passed copy test\n");

	for (int i = 0; i < 10; i++)
	{
		ar.add(i + 4);
	}

	REQUIRE(ar.getSize() == 13);
	if (INFO)printInfo("Passed resize and size test3\n");

	REQUIRE_FALSE(dynarsEqual(ar, ar2));
	if (INFO)printInfo("Passed comparison tests\n");

	ar2.add(5, 3);
	ar2.add(10, 2);
	for (int i = 0; i < ar.getSize(); i++)
	{
		std::cout << ar[i] << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < ar2.getSize(); i++)
	{
		std::cout << ar2[i] << " ";
	}
	std::cout << std::endl;

	if (INFO)printInfo("The arrays, add at index\n");

	REQUIRE(ar.pop() == 13);
	if (INFO)printInfo("Passed pop test\n");

	ar2.remove(1);
	for (int i = 0; i < ar2.getSize(); i++)
	{
		std::cout << ar2[i] << " ";
	}
	if (INFO)printInfo("Remove index(1) pop test\n");

	ar2.clear();
	REQUIRE(ar2.getSize() == 0);
	if (INFO)printInfo("Remove index(1) pop test\n");

	REQUIRE(ar[ar.find(4)] == ar[3]);
	if (INFO)printInfo("Find test \n");

	if (INFO)printInfo("Dynamic array tests passed");
}

TEST_CASE("Graph tests", "[test2]")
{
	Graph<char> graph;
	Vertex<char> * vertA = graph.createVertex('A');
	Vertex<char> * vertB = graph.createVertex('B');
	Vertex<char> * vertC = graph.createVertex('C');
	Vertex<char> * vertD = graph.createVertex('D');
	Vertex<char> * vertE = graph.createVertex('E');
	Vertex<char> * vertF = graph.createVertex('F');
	Vertex<char> * vertG = graph.createVertex('G');
	Vertex<char> * vertH = graph.createVertex('H');
	Vertex<char> * vertI = graph.createVertex('I');
	Vertex<char> * vertJ = graph.createVertex('J');

	graph.addEdge(vertA, vertB, 1);
	graph.addEdge(vertA, vertE, 1);
	graph.addEdge(vertA, vertD, 1);

	graph.addEdge(vertB, vertA, 1);
	graph.addEdge(vertB, vertC, 1);

	graph.addEdge(vertC, vertB, 1);
	graph.addEdge(vertC, vertF, 1);
	graph.addEdge(vertC, vertG, 1);

	graph.addEdge(vertD, vertA, 1);
	graph.addEdge(vertD, vertH, 1);

	graph.addEdge(vertE, vertA, 1);
	graph.addEdge(vertE, vertF, 1);
	graph.addEdge(vertE, vertH, 1);

	graph.addEdge(vertF, vertC, 1);
	graph.addEdge(vertF, vertE, 1);
	graph.addEdge(vertF, vertJ, 1);

	graph.addEdge(vertG, vertC, 1);
	graph.addEdge(vertG, vertJ, 1);

	graph.addEdge(vertH, vertD, 1);
	graph.addEdge(vertH, vertE, 1);
	graph.addEdge(vertH, vertI, 1);

	graph.addEdge(vertI, vertH, 1);
	graph.addEdge(vertI, vertJ, 1);

	graph.addEdge(vertJ, vertF, 1);
	graph.addEdge(vertJ, vertG, 1);
	graph.addEdge(vertJ, vertI, 1);

	if (INFO)printInfo("Graph set up");

	//PRINT GRAPH
	for (auto i = graph.m_verts.begin(); i != graph.m_verts.end(); i++)
	{
		std::cout << (*i)->data << '(';
		for (auto j = (*i)->edges.begin(); j != (*i)->edges.end(); j++)
		{
			std::cout << (*j)->target->data << '-' << (*j)->weight << "  ";
		}
		std::cout << ")" << std::endl;
	}
	std::cout << std::endl;

	if (INFO)printInfo("Graph print");

	graph.removeVertex(vertG);
	for (auto i = graph.m_verts.begin(); i != graph.m_verts.end(); i++)
	{
		std::cout << (*i)->data << '(';
		for (auto j = (*i)->edges.begin(); j != (*i)->edges.end(); j++)
		{
			std::cout << (*j)->target->data << '-' << (*j)->weight << "  ";
		}
		std::cout << ")" << std::endl;
	}
	std::cout << std::endl;
	if (INFO)printInfo("Remove Vert test also contains remove edge (VERT G)");
	

}

TEST_CASE("Linked List", "[test3]")
{
	LinkedList<int> list;
	LinkedList<int>::Iterator it;

	REQUIRE(list.isEmpty() == true);
	if (INFO)printInfo("Empty list test");

	list.pushFront(1);
	it = list.begin();
	REQUIRE((*it) == 1);
	if (INFO)printInfo("iterator begin test");

	list.pushFront(0);
	it = list.begin();
	REQUIRE((*it) == 0);
	it++;
	REQUIRE((*it) == 1);
	if (INFO)printInfo("iterator begin, ++ and push front");

	it--;
	REQUIRE((*it) == 0);
	if (INFO)printInfo("iterator -- test");

	list.pushBack(10);
	REQUIRE(list.last() == 10);
	if (INFO)printInfo("List push back and last");


	for (LinkedList<int>::Iterator i = list.begin(); i != list.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	if (INFO)printInfo("List print using iterator");

	REQUIRE((list.popBack() == 10 && list.last() == 1));
	if (INFO)printInfo("Pop back test");

	list.clear();
	REQUIRE(list.isEmpty());
	if (INFO)printInfo("Clear test");

	if (INFO)printInfo("Linked list tests");


}

TEST_CASE("Queue", "[test4]")
{
	Queue<int> qu = Queue<int>();

	REQUIRE(qu.isEmpty() == true);
	if (INFO)printInfo("Queue empty test");

	qu.push(1);
	qu.push(2);

	REQUIRE(qu.size() == 2);
	if (INFO)printInfo("Queue size");

	REQUIRE(qu.top() == 1);
	if (INFO)printInfo("Queue push and top");

	REQUIRE((qu.pop() == 1 && qu.top() == 2));
	if (INFO)printInfo("Queue pop and top");

	REQUIRE(qu.size() == 1);
	if (INFO)printInfo("Queue size");

	if (INFO)printInfo("Queue tests");

}

TEST_CASE("Stack test", "[test5]")
{
	Stack<float> stack = Stack<float>(20);

	REQUIRE(stack.isEmpty());
	if (INFO)printInfo("Empty stack");

	stack.push(3.2f);
	stack.push(2.0f);

	REQUIRE(stack.size() == 2);
	if (INFO)printInfo("Stack push and size");

	stack.push(2.01f);
	stack.push(1.16f);

	REQUIRE((stack.pop() == 1.16f && stack.top() == 2.01f));
	if (INFO)printInfo("Stack pop and top check");

	if (INFO)printInfo("Stack tests");
}