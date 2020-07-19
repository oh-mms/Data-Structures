//  Created by oh-mms. 2020.
//  e-mail		: chohmms@gmail.com
//  blog			: https://blog.naver.com/oh-mms
//  gitHub		: https://github.com/oh-mms
//  You can use it freely in any way.
//  If you want to contact me, please send a mail.

#pragma once
#include <iostream>

template <typename T>
class Node {

	template <typename T>
	friend class Deque;

private:
	T				m_Data;
	Node<T>* m_pNext;
	Node<T>* m_pPrev;

private:
	Node() {
		m_pNext = nullptr;
		m_pPrev = nullptr;
	}

	~Node() {
	}
};

template <typename T>
class Deque {

	typedef Node<T>	NODE;
	typedef Node<T>* PNODE;

private:
	PNODE	m_pFront;
	PNODE	m_pBack;
	int		m_iSize;

public:
	Deque() {
		m_pFront = new NODE;
		m_pBack = new NODE;
		m_iSize = 0;

		m_pFront->m_pNext = nullptr;
		m_pFront->m_pPrev = m_pBack;

		m_pBack->m_pNext = m_pFront;
		m_pBack->m_pPrev = nullptr;
	}

	~Deque() {
		delete m_pFront;
		delete m_pBack;
	}

public:
	void push_front(const T& data) {
		PNODE node = new NODE;
		node->m_Data = data;

		node->m_pNext = m_pFront;
		node->m_pPrev = m_pFront->m_pPrev;

		m_pFront->m_pPrev->m_pNext = node;
		m_pFront->m_pPrev = node;

		m_iSize++;
	}

	void pop_front() {
		if (empty())
			return;

		PNODE node = m_pFront->m_pPrev;

		m_pFront->m_pPrev = node->m_pPrev;
		node->m_pPrev->m_pNext = m_pFront;

		delete node;
		m_iSize--;
	}

	void push_back(const T& data) {
		PNODE node = new NODE;
		node->m_Data = data;

		node->m_pPrev = m_pBack;
		node->m_pNext = m_pBack->m_pNext;

		m_pBack->m_pNext->m_pPrev = node;
		m_pBack->m_pNext = node;

		m_iSize++;
	}

	void pop() {
		if (empty())
			return;

		PNODE node = m_pBack->m_pNext;

		m_pBack->m_pNext = node->m_pNext;
		node->m_pNext->m_pPrev = m_pBack;

		delete node;
		m_iSize--;
	}

	void front() {
		std::cout << "The first item is " << m_pFront->m_pPrev->m_Data << std::endl;
	}

	void back() {
		std::cout << "The last item is " << m_pBack->m_pNext->m_Data << std::endl;
	}

	void print_front() {
		if (empty())
			return;

		PNODE node = m_pFront->m_pPrev;
		while (node != m_pBack) {
			std::cout << node->m_Data << " ";
			node = node->m_pPrev;
		}

		std::cout << std::endl;
	}

	void print_back() {
		if (empty())
			return;

		PNODE node = m_pBack->m_pNext;
		while (node != m_pFront) {
			std::cout << node->m_Data << " ";
			node = node->m_pNext;
		}

		std::cout << std::endl;
	}

	void clear() {
		if (empty())
			return;

		PNODE node = m_pBack->m_pNext;

		while (node != m_pFront) {
			m_pBack->m_pNext = node->m_pNext;
			delete node;
			node = m_pBack->m_pNext;
		}

		m_iSize = 0;
		m_pFront->m_pPrev = m_pBack;
	}

	bool empty() {
		return m_iSize == 0;
	}

	int size() {
		return m_iSize;
	}
};