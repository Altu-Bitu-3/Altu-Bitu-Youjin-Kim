#include <iostream>
#include <queue>

using namespace std;

int main () {
    int n, k;
    queue <int> joseph;
    queue <int> sorted;

    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        joseph.push(i);
    } //초기 배열 생성 
    
    while (joseph.empty() == false) {
        int temp;
        for (int i=0; i<(k-1); i++) {
            temp = joseph.front();
            
            joseph.push(temp);
            joseph.pop();
            }
        
        temp = joseph.front();
        joseph.pop();
        
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
