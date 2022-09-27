#include <iostream>
#include <vector>

using namespace std;

bool isGroupWord(string word) {
	/* 원래 내 코드 */ /*
    for(int i=0; i<word.size(); i++){
    	for(int j=0; j<i; j++){
			if(word[i] != word[i-1] && word[i] == word[j]){
				return false; }				
		}
	}
    return true; */

	/* 답안 코드 보고 수정 */
	char cur = NULL;
	vector<bool> alphabet(26, false); //단어에서 알파벳 문자의 출현 유무를 나타내는 bool형 배열을 선언

    for (int i=0; i<word.size(); i++) {
        if (word[i] == cur) { //연속해서 나타난 문자라면 
            continue; 
        }
      
        if (alphabet[word[i] - 'a']) {  //이전의 문자와 다른 문자가 나타났다면

            return false; //alphabet은 boolean 벡터이므로, 안에 있는 값이 true or false
			//즉 특정 alphabet이 이미 나타난 경우라면 alphabet[index] == true일 것이다.
        }
        cur = word[i]; //cur은 처음에는 NULL이었다가 여기서 처음으로 값이 들어온다. (0부터 단어 길이 동안)
		//즉, 사실상 다음 루프에서의 직전 문자를 의미하는 변수.
        alphabet[word[i] - 'a'] = true; //지금 들어온 단어가 있었다고 flag = true 표시
    }
    return true;
}

int main(){	
    //그룹단어 조건
    //1. 지금 알파벳이 전에 쓰인 적 없음
    //2. 만약 전에 쓰였었다면 바로 앞에 같은 게 묶여있어야 함
    
    string word;
    int count = 0;
    
	int n;
	cin >> n;
    
	for(int i=0; i<n; i++){
		cin >> word;
		if(isGroupWord(word)) count++;
	}
	
	cout << count;
    return 0;
}