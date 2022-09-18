#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    //최빈값 계산에 사용되는 cmp 함수
    if(a.second != b.second) {
        return a.second > b.second; }
    else {
        return a.first < b.first; }
}

void mathMean(map<int, int> m, int n) {
    //맵 순회하면서 계산. 시간복잡도 높음
    double sum = 0;
    map<int, int> :: iterator i;
    
    for(i=m.begin(); i!=m.end(); i++){
        sum += (i->first * i->second); }

    cout << floor((sum/n)+0.5) << "\n"; //-0 방지
}

void middleNum(map<int, int> m, int n) { 
    int sum = 0;
    map<int, int> :: iterator i;
    
    for(i=m.begin(); i!=m.end(); i++) {
        sum += i->second;
        if(sum >= ((n+1)/2)) {
            cout << i->first << "\n";   
            break; }
    }
}

void mostShown(map<int, int> m) {
    //여러 개 있을 때에는 두 번째로 작은 값을 출력
    vector<pair<int, int>> v(m.begin(), m.end());

    if(v.size() <= 1) {
        cout << v[0].first << "\n"; }

    else {
        sort(v.begin(), v.end(), cmp);
        
        if(v[0].second != v[1].second) {
            cout << v[0].first << "\n"; }

        else {
            cout << v[1].first << "\n"; }
    }
}

void range(map<int, int> m) {
    //map의 첫번째 '키'와 마지막 '키'만 참조

    map<int, int> :: iterator it = m.begin();
    map<int, int> :: reverse_iterator rit = m.rbegin();

    cout << rit->first - it->first;
}

int main() {
    map<int, int> numbers;
    
    int n, key;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> key;
        numbers[key]++;
    }
    
    mathMean(numbers, n);
    
    middleNum(numbers, n);
    
    mostShown(numbers);
    
    range(numbers);
    
    return 0;
}