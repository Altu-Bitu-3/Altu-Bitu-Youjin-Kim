#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int callPrice(pair<int, int> calls) {
    int result = 0;
    result += calls.second * 5;
    
    if(calls.first > 600 && calls.first < 700) {
        int sum = calls.first + calls.second;
        if(sum > 660) {
            result += (sum - 660) * 5;
        }
    }
    
    else if(calls.first >= 1800 && calls.first < 1900) {
        int sum = calls.first + calls.second;
        if(sum >= 1860) {
            // 18:30부터 50분 통화했다고 치면 1880
            // 할증되는 요금은 30분어치
            
            // 18:30부터 13분 통화했다고 치면 1843
            // 할증되는 요금은 13분어치
            result += (1860 - calls.first) * 5;
            }
        else {
            result += calls.second * 5;
        }
    }
    
    else if(calls.first >= 700 && calls.first < 1800) {
        result += calls.second * 5;
    }
    
    //할증: 7시부터 19시까지 5원씩
    //고려 대상 (1): 6시 5분에 시작해서 7시 5분에 끝나는 전화
    //이때 6시 5분(first)는 0605, 할증해야 하는 요금은 5분어치
    
    //고려 대상 (2): 18시 30분에 시작해서 19시 30분에 끝나는 전화
    //first는 1830, 할증 대상은 1860-1830
    
    return result;
}

int main()
{
    int n;
    cin >> n;
    
    vector<pair<int, int>> calls;
    for(int i=0; i<n; i++) {
        pair<int, int> call;
        string temp;
        
        cin >> temp >> call.second;
        temp.erase(2,1);
        
        call.first = stoi(temp);
        calls.push_back(call);
    }
    
    //07:00시부터 19:00시까지 1분에 10원
    //19:00시부터 07:00시까지 1분에 5원
    
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += callPrice(calls[i]);
    }
    
    cout << sum;
    return 0;
}