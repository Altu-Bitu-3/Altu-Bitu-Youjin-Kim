#include <iostream> // 입출력 헤더
#include <set> // set 자료구조 사용 헤더
using namespace std; // std 라이브러리 사용 헤더

bool isCycle(set<string>& s, string str) { //사이클 단어인지 여부 확인하는 함수
	int cnt = str.length(); //cnt: 입력된 str의 길이

	while (cnt--) { //단어의 길이만큼 Cycle을 만들어 보면서 일일히 비교 (Brute Force)

		// 같은 단어가 발견된 경우
		if (s.find(str) != s.end()) { // 새로 입력된 단어 (이번에 들어온 단어) 가 아니면 사이클 단어로 판단
			return true; //같은 단어가 있음을 알림
		}

		// 시계 방향대로, 앞 글자를 떼어서 뒤에 붙여줌.
		str = str + str[0]; // 뒤에 붙이는 부분
		str.erase(0, 1); // 앞 글자를 떼어내는 부분
	}
	return false; // 같은 단어가 발견되지 않음 → if 문에서 true가 반환되지 않음 → return false (다른 단어)
}
int main() {
	int n; // 입력된 단어 개수 저장하는 변수
	string str; // 단어를 저장하는 변수
	set<string> word; // 위 str들로 구성된 set (특징: 자동 sort되는 자료구조)

	// 입력
	cin >> n; // 단어 개수를 입력받고
	while (n--) { // 그 개수만큼
		cin >> str; // 단어를 입력받음

		// set 내에 같은 단어가 없으면 새로 추가

		if (!isCycle(word, str)) { // 같은 단어가 없는지 확인
        // → isCycle (맨 위쪽 함수) 에서는 같은 단어가 있으면 true, 없으면 false 반환함
			word.insert(str); // 만약 없다면 새 단어를 추가
		}
	}

	// 출력
	cout << word.size();
}