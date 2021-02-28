//  Created by oh-mms. 2020.
//  e-mail		: chohmms@gmail.com
//  blog		: https://blog.naver.com/oh-mms
//  gitHub		: https://github.com/oh-mms
//  You can use it freely in any way.
//  If you want to contact me, please send a mail.

#include <iostream>
#include <string>

using namespace std;

class Node {
private:
	string _sStr;
	Node* _pNextNode;
public:
	Node(string str) : _pNextNode(nullptr) { _sStr = str; }
	~Node() { delete(_pNextNode); }
	string GetString() { return _sStr; }
	void SetNextNode(Node* node) { _pNextNode = node; }
	Node* GetNextNode() { return _pNextNode; }
};

Node* hashTable[100];

void hashing(string str) {
	int index = str.size();
	if (hashTable[index] == nullptr) {
		hashTable[index] = new Node(str);
		return;
	}
	// ���� �����Ѵٸ� ü�̴��� �ǵ��� ������ش�.
	Node* tempNode = hashTable[index];
	while (tempNode->GetNextNode() != nullptr) tempNode = tempNode->GetNextNode();
	tempNode->SetNextNode(new Node(str));
	return;
}

int main() {
	string input;
	int num;
	cin >> num;
	for (int i = 0; i < num; ++i) {
		cin >> input;
		hashing(input);
	}

	cout << "hashTable�� �����ϴ� ����" << endl;
	for (int i = 0; i < 100; ++i) {
		if (!hashTable[i]) continue;
		cout << "hashTable[" << i << "] �� ����� ���� : ";
		Node* tempNode = hashTable[i];
		while (tempNode != nullptr) {
			cout << tempNode->GetString() << ", ";
			tempNode = tempNode->GetNextNode();
		}
		cout << endl;
	}
}