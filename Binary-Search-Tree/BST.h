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
	friend class BinarySearchTree;

private:
	T		m_Data;
	Node<T>*	m_pLeft;		// Left Child
	Node<T>*	m_pRight;		// Right Child

private:
	Node() {
		m_pLeft = nullptr;
		m_pRight = nullptr;
	}

	~Node() {
	}
};

template <typename T>
class BinarySearchTree {
	
	typedef Node<T>		NODE;
	typedef Node<T>*	PNODE;

private:
	PNODE	 m_pRoot;
	int	 m_iSize;

public:
	BinarySearchTree() {
		m_pRoot = nullptr;
		m_iSize = 0;
	}

	~BinarySearchTree() {
		if (m_iSize)
			clear(get_root());
	}

public:
	void insert(const T& data) {
		PNODE node = new NODE;
		node->m_Data = data;

		if (m_pRoot == nullptr) {
			m_pRoot = node;
			m_iSize++;
			return;
		}

		PNODE curNode = m_pRoot;

		// This may be a not good algorithm and clean code.
		// If you need code readability, then please encapsulate the logic.
		// Or you can process it in a different way more wisely.
		while (curNode != nullptr) {
			if (curNode->m_Data > data) {
				if (curNode->m_pLeft != nullptr)
					curNode = curNode->m_pLeft;
				else {
					curNode->m_pLeft = node;
					break;
				}
			}

			else {
				if (curNode->m_pRight != nullptr)
					curNode = curNode->m_pRight;
				else {
					curNode->m_pRight = node;
					break;
				}
			}
		}

		m_iSize++;
	}

	void clear(PNODE node) {
		if (node == nullptr)
			return;

		clear(node->m_pLeft);
		clear(node->m_pRight);
		std::cout << "delete " << node->m_Data << std::endl;
		delete node;
		m_iSize--;
	}

	PNODE get_root() {
		return m_pRoot;
	}

	void pre_order(PNODE node) {
		if (node == nullptr)
			return;

		std::cout << node->m_Data << " ";
		pre_order(node->m_pLeft);
		pre_order(node->m_pRight);
	}

	void in_order(PNODE node) {
		if (node == nullptr)
			return;

		in_order(node->m_pLeft);
		std::cout << node->m_Data << " ";
		in_order(node->m_pRight);
	}

	void post_order(PNODE node) {
		if (node == nullptr)
			return;

		post_order(node->m_pLeft);
		post_order(node->m_pRight);
		std::cout << node->m_Data << " ";
	}

	void print_size() {
		std::cout << "Size : " << m_iSize << std::endl;
	}
};
