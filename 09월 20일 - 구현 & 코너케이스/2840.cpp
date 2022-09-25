#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    vector<pair<int, char>> inputs;
    
    cin >> n >> k; 
    vector<char> wheel(n, '?');
    
    for(int i=0; i<k; i++) {
        pair<int, char> input;
        cin >> input.first >> input.second;
        
        inputs.push_back(input);
    }
    
    int sum = 0, mod = 0; //누적합, 나머지
    for(int i=0; i<k; i++) { //k는 바퀴 돌리는 횟수, n은 바퀴 칸 수
        sum += inputs[i].first;
        mod = sum % n;
        
        if(wheel[mod] != '?' && wheel[mod] != inputs[i].second) {
            cout << '!';
            exit(0);
        }
        else {
            wheel[mod] = inputs[i].second;
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(wheel[i] != '?' && wheel[i] == wheel[j]) {
                cout << '!';
                exit(0);
            }
        }
    }
    
    mod = (n-1) - mod;
    reverse(wheel.begin(), wheel.end());
    
    for(int i=0; i<n; i++) {
        cout << wheel[mod];
        mod++;
        
        if(mod == n) mod = 0;
    }
    return 0;
}