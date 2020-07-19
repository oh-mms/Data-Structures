//  Created by oh-mms. 2020.
//  e-mail	: chohmms@gmail.com
//  blog	: https://blog.naver.com/oh-mms
//  gitHub	: https://github.com/oh-mms
//  You can use it freely in any way.
//  If you want to contact me, please send a mail.

#pragma once
#include <iostream>

template <typename T>
class Node {

	template <typename T>
	friend class Stack;

private:
	T		 m_data;
	Node<T>*	 m_pNext;

private:
	Node() { m_pNext = nullptr; }
	~Node() { }
};

// All methods were written for checking their data. (using std::cout)
template <typename T>
class Stack {

	typedef Node<T>		NODE;
	typedef Node<T>*	PNODE;

private:
	PNODE head;
	int size;

public:
	Stack() {
		head = new NODE;
		head->m_pNext = nullptr;
		size = 0;
	}

	~Stack() {
		delete head;
	}

public:
	void push(const T& data) {
		PNODE node = new NODE;
		node->m_data = data;

		if (size <= 0) {
			head->m_pNext = node;
			size++;
			return;
		}

		node->m_pNext = head->m_pNext;
		head->m_pNext = node;
		size++;
	}

	void pop() {
		PNODE node = head->m_pNext;

		if (node == nullptr)
			return;

		head->m_pNext = node->m_pNext;
		delete node;
		size--;
	}

	void clear() {		
		while (size > 0) {
			pop();
		}

		std::cout << "clear finished." << std::endl;
	}

	void print() {
		PNODE node = head->m_pNext;
		
		while (node != nullptr) {
			std::cout << node->m_data << " ";
			node = node->m_pNext;
		}

		std::cout << "\n" << std::endl;
	}

	void peek() {
		std::cout << "peek : " << head->m_pNext->m_data << std::endl;
	}

	void empty() {
		if (size <= 0)
			std::cout << "this stack is empty." << std::endl;
	}

	void printSize() {
		std::cout << "size : " << size << std::endl;
	}
};
