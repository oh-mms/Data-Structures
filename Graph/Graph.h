//  Created by oh-mms. 2020.
//  e-mail	: chohmms@gmail.com
//  blog	: https://blog.naver.com/oh-mms
//  gitHub	: https://github.com/oh-mms
//  You can use it freely in any way.
//  If you want to contact me, please send a mail.

#pragma once
#include <iostream>

template <typename T>
class Edge {

	template <typename T>
	friend class Node;

	typedef Node<T>		NODE;
	typedef Node<T>*	PNODE;
	typedef Edge<T>*	PEDGE;

private:
	PNODE	m_pNode;		// to show which node is linked with.
	PEDGE	m_pNext;		// using for pointing a next edge.

private:
	Edge() {
		m_pNode = nullptr;
		m_pNext = nullptr;
	}

	~Edge() {
		std::cout << "Edge Node " << m_pNode->m_Data << " is deleted." << std::endl;
		delete m_pNext;
	}

private:
	void print() {
		std::cout << m_pNode->m_Data << " ";

		PEDGE next = m_pNext;

		while (next != nullptr) {
			std::cout << next->m_pNode->m_Data << " ";
			next = next->m_pNext;
		}
	}
};


template <typename T>
class Node {

	template <typename T>
	friend class Edge;

private:
	typedef Node<T>*	PNODE;
	typedef Edge<T>		EDGE;
	typedef Edge<T>*	PEDGE;

private:
	T			m_Data;
	PEDGE			m_pEdge;

public:
	Node(const T& data) {
		m_Data = data;
		m_pEdge = nullptr;
		std::cout << "Node " << m_Data << " is created." << std::endl;
	}

	~Node() {
		std::cout << "Node " << m_Data << " is deleted." << std::endl;
		delete m_pEdge;
	}

public:
	void print_edge() {
		std::cout << "Node " << m_Data << " is linked with : ";
		m_pEdge->print();
		std::cout << std::endl;
	}

	void add_edge(PNODE node)  {
		PEDGE edge = new EDGE;
		edge->m_pNode = node;

		PEDGE next = m_pEdge;

		if (m_pEdge == nullptr) {
			m_pEdge = edge;
			return;
		}

		while (next->m_pNext != nullptr) {
			next = next->m_pNext;
		}

		next->m_pNext = edge;
	}
};
