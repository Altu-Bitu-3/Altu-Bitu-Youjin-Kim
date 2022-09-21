#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define INTEGER_OF_A 'A'
using namespace std;

/* palindrome available or not */
pair<int, int> isAvailable(vector<int> count) {
    string failed = "I'm Sorry Hansoo";

    int isodd = 0;
    int temp = 0;
    
    for(int i=0; i<26; i++) {
        if(count[i]%2){
            isodd ++;
            temp = i;
        }
        
        if(isodd > 1){
            cout << failed;
            exit(0); //생성 불가능하다면 exit로 프로세스 종료
        }
    }
    pair<int, int> result;

    result.first = isodd;
    result.second = temp;

    return result;
}

/* print function */
void printResult(vector<int> count, int isodd, int temp) {
    int n = INTEGER_OF_A;
    
    for(int i=0; i<26; i++) {
        for(int j=0; j<count[i]/2; j++) cout << (char)(i+n);}
    
    if(isodd) cout << (char)(temp+n);
    
    for(int i=25; i>=0; i--) {
        for(int j=0; j<count[i]/2; j++) cout << (char)(i+n);}
}

/* main */
int main()
{
    string name;
    cin >> name;
    
    int n = INTEGER_OF_A;
    
    vector<int> letters(name.begin(), name.end());
    vector<int> count(26, 0);
    
    for(int i=0; i<name.size(); i++) {
        count[letters[i]-n] ++;
    }
    
    pair<int, int> res = isAvailable(count);
    printResult(count, res.first, res.second);

    return 0;
}