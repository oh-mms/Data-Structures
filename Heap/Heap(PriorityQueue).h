//  Created by oh-mms. 2020.
//  e-mail	: chohmms@gmail.com
//  blog	: https://blog.naver.com/oh-mms
//  gitHub	: https://github.com/oh-mms
//  You can use it freely in any way.
//  If you want to contact me, please send a mail.

#include <iostream>

using namespace std;

const int SIZE = 10;
int heap[SIZE];

class PriorityQueue {
private:
	int* _pHeap;
	int _iCapacity;
	int _iSize;

public:
	PriorityQueue(int capacity = 0) : _iCapacity(capacity), _iSize(0) { _pHeap = new int[capacity]; }
	~PriorityQueue() { delete[] _pHeap; }

public:
	bool Push(int num) {
		if (_iSize >= _iCapacity) return false;
		_iSize++;
		_pHeap[_iSize - 1] = num;
		HeapifyUp(_iSize - 1);
		return true;
	}

	int Pop() {
		if (_iSize <= 0) return -1;
		int val = _pHeap[0];
		_pHeap[0] = _pHeap[_iSize - 1];
		_iSize--;
		HeapifyDown(0);
		return val;
	}

	void HeapifyDown(int index) { // 편의상 PriorityQueue 내부에 구현함. (원래는 독립된 힙에 존재)
		int i = index * 2 + 1;
		if (i > _iSize) return;
		if (i + 1 <= _iSize && _pHeap[i] < _pHeap[i + 1]) i++;

		if (_pHeap[index] < _pHeap[i]) {
			int temp = _pHeap[index];
			_pHeap[index] = _pHeap[i];
			_pHeap[i] = temp;
		}

		// 지금 확인한 노드의 왼 쪽 인덱스가 존재(전체 크기보다 작으면 존재)한다면,
		// Heapify를 해볼만한 가치가 있는 자식 노드가 존재한다는 것.
		if (i <= _iSize)
			HeapifyDown(i);
	}

	void HeapifyUp(int index) {
		if ((index - 1) / 2 >= 0 && _pHeap[(index - 1) / 2] < _pHeap[index]) {
			int temp = _pHeap[(index - 1) / 2];
			_pHeap[(index - 1) / 2] = _pHeap[index];
			_pHeap[index] = temp;
		}

		if ((index - 1) / 2 > 0)
			HeapifyUp((index - 1) / 2);
	}

	void Print() {
		for (int i = 0; i < _iSize; ++i)
			cout << _pHeap[i] << " ";
	}
};


int main() {
	PriorityQueue pq(10);
	pq.Push(5);
	pq.Push(6);
	pq.Push(4);
	pq.Push(1);
	pq.Push(10);
	pq.Push(15);
	pq.Push(7);
	pq.Push(3);
	pq.Push(9);
	pq.Push(11);

	pq.Print();
	cout << endl;

	for (int i = 0; i < 10; ++i)
		cout << pq.Pop() << " ";

	return 0;
}