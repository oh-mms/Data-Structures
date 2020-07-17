//  Created by oh-mms. 2020.
//  e-mail	: chohmms@gmail.com
//  blog		: https://blog.naver.com/oh-mms
//  gitHub	: https://github.com/oh-mms
//  You can use it freely in any way.
//  If you want to contact me, please send a mail.

#pragma once
#include <iostream>

template <typename T>
class Node {

	template <typename T>
	friend class LinkedList;

private:
	T					m_Data;
	Node<T>*		m_pNext;
	Node<T>*		m_pPrev;

private:
	Node() {
		m_pNext = nullptr;
		m_pPrev = nullptr;
	}

	~Node() {
	}
};

template <typename T>
class LinkedList {

	typedef Node<T>	NODE;
	typedef Node<T>*	PNODE;

private:
	PNODE		m_pStart;
	PNODE		m_pEnd;
	int			m_iSize;

public:
	LinkedList() {
		m_pStart = new NODE;
		m_pEnd = new NODE;

		m_pStart->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pStart;

		m_pStart->m_pPrev = nullptr;
		m_pEnd->m_pNext = nullptr;

		m_iSize = 0;
	}

	~LinkedList() {
		delete m_pStart;
		delete m_pEnd;
	}

public:
	void push_front(const T& data) {
		PNODE temp = new NODE;
		temp->m_Data = data;

		PNODE node = m_pStart->m_pNext;

		temp->m_pNext = node;
		node->m_pPrev = temp;

		m_pStart->m_pNext = temp;
		temp->m_pPrev = m_pStart;

		++m_iSize;
	}

	void push_back(const T& data) {
		PNODE temp = new NODE;
		temp->m_Data = data;

		PNODE node = m_pEnd->m_pPrev;

		temp->m_pNext = m_pEnd;
		node->m_pNext = temp;

		temp->m_pPrev = node;
		m_pEnd->m_pPrev = temp;

		++m_iSize;
	}

	void pop_front() {
		if (empty())
			return;

		PNODE temp = m_pStart->m_pNext;
		PNODE tempNext = temp->m_pNext;

		tempNext->m_pPrev = m_pStart;
		m_pStart->m_pNext = tempNext;

		delete temp;
		m_iSize--;
	}

	void pop_back() {
		if (empty())
			return;

		PNODE temp = m_pEnd->m_pPrev;
		PNODE tempPrev = temp->m_pPrev;

		tempPrev->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = tempPrev;

		delete temp;
		m_iSize--;
	}

	void clear() {
		if (empty())
			return;

		while (!empty()) {
			pop_front();				// it's for convenient and needs original logic.
		}
		

		// setting for reuse.
		m_pStart->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pStart;

		m_pStart->m_pPrev = nullptr;
		m_pEnd->m_pNext = nullptr;
	}

	bool empty() {
		return m_iSize == 0;
	}

	void print() {
		if (empty()) {
			std:: cout << "No element !" << std::endl;
			return;
		}

		for (PNODE temp = m_pStart->m_pNext; temp != m_pEnd; ) {
			std::cout << temp->m_Data << " ";
			temp = temp->m_pNext;
		}

		std::cout << std::endl;
	}
};
