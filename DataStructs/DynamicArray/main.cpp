#include "Graph.h"	
#include <iostream>
#include <functional>
#include <algorithm>
Vertex<char> * BreadthFirstSearch(Vertex<char> * v1, std::function<bool(Vertex<char>*)> pred)
{
	std::list<Vertex<char>*> queue;
	std::list<Vertex<char>*> lookedAt;

	queue.push_back(v1);

	while (queue.size() > 0)
	{
		
		Vertex<char> * check = (queue.front());

		std::cout << "Checking " << check->data << std::endl;

		if (pred(check)) return check;

		

		queue.pop_front();
		lookedAt.push_back(check);

		for (std::list<Edge<char>*>::iterator i = check->edges.begin(); i != check->edges.end(); i++)
		{
			//Check to see if its already looked at or in the list to look at
			if (!(std::find(lookedAt.begin(), lookedAt.end(), (*i)->target) != lookedAt.end()) && !(std::find(queue.begin(), queue.end(), (*i)->target) != queue.end()))
			{
				queue.push_back((*i)->target);
				std::cout << "Adding " << (*i)->target->data << ' ';
			}
			
		}
		std::cout << std::endl;

	}
	return nullptr;

}


int main()
{
	std::cout << "Graph stuff" << std::endl;


	Graph<char> graph;
	//DynArray<Graph::Vertex> graph; 
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




	//PRINT GRAPH
	for (auto i = graph.m_verts.begin(); i != graph.m_verts.end(); i++)
	{
		std::cout << (*i)->data << '(';
		for(auto j = (*i)->edges.begin(); j != (*i)->edges.end(); j++)
		{
			std::cout << (*j)->target->data << '-' << (*j)->weight << "  ";
		}
		std::cout << ")" << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;

	Vertex<char> * searchV = BreadthFirstSearch(vertA, [](Vertex<char>* v) { if (v->data == 'I') return true; else return false; });
	if (searchV != nullptr)
		std::cout << "SEARCH FOUND: " << searchV->data;
	else
		std::cout << "Didnt find it";

	

	std::cin.get();
	std::cin.ignore();
	std::cin.get();
	return 0;
}