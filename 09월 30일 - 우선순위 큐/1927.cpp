#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false); //시간초과 방지
    
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int>> pq; //오름차순 큐
    
    while(n--) {
        int input;
        cin >> input;
        
        if(!input) {
            if(pq.empty()) cout << "0" << "\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else pq.push(input);
    }
    return 0;
}