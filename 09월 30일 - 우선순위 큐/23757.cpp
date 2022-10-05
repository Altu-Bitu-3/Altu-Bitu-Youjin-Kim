#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    priority_queue<int> box;
    vector<int> kids;
    
    for(int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        
        box.push(tmp);
    }
    
    for(int i=0; i<m; i++) {
        int tmp;
        cin >> tmp;
        
        kids.push_back(tmp);
    }
    
    for(int i=0; i<m; i++) {
        int box_now = box.top();
        box.pop();
        
        box_now = box_now - kids[i];
        if(box_now < 0) {
            cout << "0";
            exit(0);
        }
        
        box.push(box_now);
    }
    
    cout << "1";
    return 0;
}