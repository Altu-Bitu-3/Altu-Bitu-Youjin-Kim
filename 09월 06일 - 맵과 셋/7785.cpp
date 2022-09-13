#include<iostream>
#include<set>

using namespace std;

int main() {
	int n; //입력 길이
	string name, state; //이름, 출입기록
	set<string> company; //현재 출근 중인 사람 set

	/* 입력 */
	cin >> n; //입력의 길이 (= n)을 입력 받는다.
	while (n--) { //n번 입력을 받는다.
		cin >> name >> state; //이름, 출입기록 순으로 String을 입력받는다.

		if (state == "enter") { //만약 '출근' 기록이 입력되면
			company.insert(name); //company set에 (출근한 사람의) 이름을 넣는다.
		}
		else { //만약 '출근' 기록이 입력되지 않았다면 (== 만약 '퇴근' 기록이라면)
			company.erase(name); //company set에서 (퇴근한 사람의) 이름을 뺀다.
		}
	}

	/* 출력 (역으로 참조) */
	for (auto iter = company.rbegin(); iter != company.rend(); iter++) { //set은 자동으로 "오름차순" 정렬되므로 역으로 참조하면 → 바로 사전순 역순으로 출력할 수 있다.
		cout << *iter << '\n'; //company set에 남아 있는 이름들을 출력한다.
	}
}