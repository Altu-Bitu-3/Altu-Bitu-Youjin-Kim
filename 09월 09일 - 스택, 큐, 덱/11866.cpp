#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int main () {
    int n, k;
    deque <int> joseph;
    queue <int> sorted;

    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        joseph.push_back(i);
    } //초기 배열 생성 
    
    while (joseph.empty() == false) {
        int temp;
        for (int i=0; i<(k-1); i++) {
            temp = joseph.front();
            
            joseph.push_back(temp);
            joseph.pop_front();
            }
        
        temp = joseph.front();
        joseph.pop_front();
        
        sorted.push(temp);
    }
    
    /* 출력 */
    cout << "<";
    for (int i=0; i<(n-1); i++) {
        cout << sorted.front() << ", ";
        sorted.pop();
    }
    cout << sorted.front() << ">";
    
    return 0;
}
