#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;
const int SIZE = 8;

int m, n;
vector<int> num(SIZE);
vector<bool> check(SIZE);

vector<int> inputs; //입력 받는 벡터
set<string> isExist; //기존 존재 여부 파악 벡터

/* backtracking 코드는 라이브코딩 N과 M 1번문제 참고함! */
void backtracking(int cnt) { 
    if (cnt == n) {
        string key;
        for (int i = 0; i < cnt; i++) {
            int index = num[i];
            key += to_string(inputs[index]);
            key += " ";
        }
        
        if(isExist.find(key) == isExist.end()) {
            cout << key;
            isExist.insert(key);
        }
        return;
    }
    for (int i = 0; i < m; i++) { 
        if (!check[i]) { 
            num[cnt] = i;
            check[i] = true;
            backtracking(cnt + 1);

            check[i] = false; 
        }
    }
}

int main() {
    //입력
    cin >> m >> n;

	//수열 입력받기
	for(int i=0; i<m; i++) {
		int new_number;
		cin >> new_number;
		
		inputs.push_back(new_number);
	}
	
	sort(inputs.begin(), inputs.end());
	
	backtracking(0);
    return 0;
}