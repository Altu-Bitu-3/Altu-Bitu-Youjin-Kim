#include <iostream>
#include <deque>
#include <stack>
#include <string>

using namespace std;

deque<int> cardDeploy(int n, stack<int> commands) {
    deque<int> result;
    result.push_back(1);

    for(int i=2; i<=n; i++) {
        switch(commands.top()) {
        case 1:
            result.push_front(i);
            break;
        case 2: {
            int k = result.front();
            result.pop_front();
            result.push_front(i);
            result.push_front(k);
            break; }
        case 3:
            result.push_back(i);
            break;
        }
        commands.pop();
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> commands;
    deque<int> result;

    for(int i=0; i<n-1; i++) {
        int c;
        cin >> c;

        commands.push(c);
    }

    result = cardDeploy(n, commands);

    while(result.empty() == false) {
        cout << result.front() << " ";
        result.pop_front();
    }

    return 0;
}