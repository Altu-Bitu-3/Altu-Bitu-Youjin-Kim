#include <iostream>

using namespace std;

bool isGroupWord(string word) {
    for(int i=0; i<word.size(); i++){
    	for(int j=0; j<i; j++){
			if(word[i] != word[i-1] && word[i] == word[j]){
				return false; }				
		}
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