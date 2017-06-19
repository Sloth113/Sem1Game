#pragma once
#include <list>


template<class T>
class Vertex;

template<class T>
class Edge
{
public:
	Edge(Vertex<T>* t = nullptr, float w = 0)
	{
		target = t;
		weight = w;
	};

	virtual ~Edge() {}

	Vertex<T> * target;

	float weight;
};

template <class T>
class Vertex
{
public:
	Vertex(T value) : data(value) {}
	virtual ~Vertex() {}

	std::list<Edge<T>*> edges;

	T data;
};

template<class T>
class Graph
{
public:
	Vertex<T>* createVertex(T value)
	{
		Vertex<T> * v = new Vertex<T>(value);
		m_verts.push_back(v);
		return v;
	}

	void removeVertex(Vertex<T> * v)
	{
		for (auto i = m_verts.begin(); i != m_verts.end(); i++)
		{
			for (auto j = (*i)->edges.begin(); j != (*i)->edges.end();)
			{
				if ((*j)->target == v)
				{
					removeEdge(*i, v);
					j = (*i)->edges.begin(); //BAD but works
				}else
					j++;
			}
		}
	}
	void addEdge(Vertex<T> * v1, Vertex<T> * v2, float weight)
	{
		v1->edges.push_back(new Edge<T>(v2, weight));
	}
	void removeEdge(Vertex<T> * v1, Vertex<T> * v2)
	{
		v1->edges.remove_if([v2](Edge<T> * edge) { return edge->target == v2; });
	}

	std::list<Vertex<T> *> m_verts;
	//protected:
};