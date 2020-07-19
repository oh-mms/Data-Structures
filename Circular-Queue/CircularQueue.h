//  Created by oh-mms. 2020.
//  e-mail		: chohmms@gmail.com
//  blog		: https://blog.naver.com/oh-mms
//  gitHub		: https://github.com/oh-mms
//  You can use it freely in any way.
//  If you want to contact me, please send a mail.

#pragma once
#include <iostream>
#define DEFAULT_SIZE 10

template <typename T>
class CircularQueue {
private:
	T*		m_pQueue;
	int		m_iFront;
	int		m_iRear;
	int		m_iSize;
	int		m_iCapacity;

public:
	CircularQueue(const int Capacity = DEFAULT_SIZE) : m_iCapacity(Capacity) {
		m_pQueue = new T[m_iCapacity]{NULL};
		m_iFront = 0;
		m_iRear = 0;
		m_iSize = 0;
	}

	~CircularQueue() {
		delete[] m_pQueue;
	}

public:
	void push(const T& data) {
		if (isFull())
			return;

		m_pQueue[m_iRear] = data;

		m_iRear = ++m_iRear % m_iCapacity;
		m_iSize++;
	}

	void pop() {
		if (empty())
			return;
		
		std::cout << "pop : " << m_pQueue[m_iFront] << std::endl;
		m_pQueue[m_iFront] = NULL;

		m_iFront = ++m_iFront % m_iCapacity;
		m_iSize--;
	}

	bool empty() {
		return m_iSize == 0;
	}

	bool isFull() {
		return m_iSize == m_iCapacity;
	}

	void show() {
		int idx = m_iFront;
		int size = m_iSize;

		while (size-- != 0) {
			std::cout << m_pQueue[idx] << " ";
			idx = ++idx % m_iCapacity;
		}
		std::cout << std::endl;
	}

	void clear() {
		m_iSize = 0;
		m_iFront = m_iRear;

		std::cout << "Clear Finished !" << std::endl;
	}
};