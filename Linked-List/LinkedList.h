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
	T					 m_iData;
	Node<T>*	 m_pNext;

private:
	Node() { m_pNext = nullptr; }
	~Node() { }

public:
	// Check if the data is in this node.
	bool checkData(const int& data) const {
		if (m_iData == data)
			return true;

		return false;
	}
};

template <typename T>
class LinkedList {

	typedef Node<T>		NODE;
	typedef Node<T>*		PNODE;

private:
	//PNODE tail;		// If you add a tail pointer in this class, then you can use this more easily.
	PNODE head;
	int size;

public:
	LinkedList() {
		head = new NODE;
		head->m_pNext = nullptr;
		size = 0;
	}

	~LinkedList() {
		delete head;
	}

public:
	void push_front(const int& data) {
		PNODE node = new NODE;
		node->m_iData = data;
		node->m_pNext = head->m_pNext;
		head->m_pNext = node;
		size++;
	}

	void push_back(const int& data) {
		PNODE node = new NODE;
		node->m_iData = data;

		// If there is no node in the list, you have to care for inserting the first node.
		PNODE temp = head->m_pNext;
		if (temp == nullptr) {
			push_front(data);
			return;
		}

		// Find the last node.
		while (temp->m_pNext != nullptr) {
			temp = temp->m_pNext;
		}

		temp->m_pNext = node;
		size++;
	}


	void pop_front() {
		PNODE node = head->m_pNext;

		if (node == nullptr) return;

		head->m_pNext = node->m_pNext;
		delete node;
		size--;
	}

	void pop_back() {
		PNODE node = head->m_pNext;

		// If there is no node in the list, you have to care for inserting the first node.
		if (node == nullptr) return;

		PNODE prev = node;

		// Find the last node and the previous node;
		while (node->m_pNext != nullptr) {
			prev = node;
			node = node->m_pNext;
		}

		prev->m_pNext = node->m_pNext;
		delete node;

		size--;
	}

	void searchElement(const int& data) {
		PNODE node = head->m_pNext;
		int idx = 0;

		while (node != nullptr) {
			if (node->checkData(data)) {
				std::cout << "data " << data << " is in index : " << idx << std::endl;
				return;
			}
			node = node->m_pNext;
			idx++;
		}

		std::cout << "Search : data " << data << " is Not found." << std::endl;
	}

	void deleteNode(const int& data) {
		PNODE node = head->m_pNext;

		if (node == nullptr) return;

		PNODE prev = head;

		while (node != nullptr) {
			if (node->checkData(data)) {
				std::cout << "data " << data << " is deleted." << std::endl;
				prev->m_pNext = node->m_pNext;
				delete node;
				size--;
				return;
			}
			prev = node;
			node = node->m_pNext;
		}

		std::cout << "Delete : data " << data << " is Not found." << std::endl;
	}

	void clear() {
		while (size > 0) pop_front();		// Function 'pop_front()' is not the right one, but for convenience.
		head->m_pNext = nullptr;
		std::cout << "All data is removed." << std::endl;
	}

	void printSize() {
		std::cout << "Size : " << size << std::endl;
	}

	void print() {
		PNODE node = head->m_pNext;

		if (node == nullptr)
			return;

		while (node != nullptr) {
			std::cout << node->m_iData << " ";
			node = node->m_pNext;
		}

		std::cout <<  std::endl;
	}
};