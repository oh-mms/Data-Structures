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
	// 만약 키값이 존재한다면 필요한 처리는 여기서 할 수 있다.
	// 예를들어, 원래 키 값의 다음 원소에라도 저장하도록 인덱스를 조정해줄 수 있다. (개방조사법, 체이닝 등)
	return false;
}

int main() {
	char input = NULL;
	int num;
	cin >> num;
	for (int i = 0; i < num; ++i) {
		cin >> input;
		if (hashing(input)) {
			cout << input << " 생성 완료." << endl;
		}
		else
			cout << input << "은 이미 저장되어 있습니다." << endl;
	}

	cout << "hashTable에 존재하는 원소" << endl;
	for (int i = 0; i < 100; ++i) {
		if (!hashTable[i]) continue;
		cout << (char)(i + 97) << endl;
	}
}