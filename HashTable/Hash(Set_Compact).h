//  Created by oh-mms. 2020.
//  e-mail		: chohmms@gmail.com
//  blog		: https://blog.naver.com/oh-mms
//  gitHub		: https://github.com/oh-mms
//  You can use it freely in any way.
//  If you want to contact me, please send a mail.

#include <iostream>

using namespace std;

bool hashTable[100];

bool hashing(char ch) {
	int index = (ch - 'a');
	if (!hashTable[index]) {
		hashTable[index] = true;
		return true;
	}
	// ���� Ű���� �����Ѵٸ� �ʿ��� ó���� ���⼭ �� �� �ִ�.
	// �������, ���� Ű ���� ���� ���ҿ��� �����ϵ��� �ε����� �������� �� �ִ�. (���������, ü�̴� ��)
	return false;
}

int main() {
	char input = NULL;
	int num;
	cin >> num;
	for (int i = 0; i < num; ++i) {
		cin >> input;
		if (hashing(input)) {
			cout << input << " ���� �Ϸ�." << endl;
		}
		else
			cout << input << "�� �̹� ����Ǿ� �ֽ��ϴ�." << endl;
	}

	cout << "hashTable�� �����ϴ� ����" << endl;
	for (int i = 0; i < 100; ++i) {
		if (!hashTable[i]) continue;
		cout << (char)(i + 97) << endl;
	}
}