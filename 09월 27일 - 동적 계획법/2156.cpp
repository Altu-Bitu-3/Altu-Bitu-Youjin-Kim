#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void winePick(vector<int> input, int n) {
    vector<int> dp(n+1, 0);
    vector<int> temp(3, 0);
    
    //dp[i] → i번 마실 수 있을 때 최대 양
    //dp[0] = 0인 상태
    dp[1] = input[1];
    dp[2] = input[1] + input[2];
    
    //3잔 연속 마실 수 없으므로 3 이상부터는
    //1 2 3이 있을 때 1+3, 2+3, 1+2 중에 선택해야 한다.
    
    //여기서 1+3 → 지지지난 번 (...) 최댓값 + 지금 값 (4개부터는 지금 값 + 1개 더 고려해야 함)
    //2+3 → 지지난 번 최댓값 + 지금 값
    //1+2 → 그냥 지난 번 최댓값
    
    for(int i=3; i<=n; i++) {
        for(int j=0; j<3; j++) {
            temp[0] = dp[i-3] + input[i-1] + input[i];
            temp[1] = dp[i-2] + input[i];
            temp[2] = dp[i-1];
        }
        
        sort(temp.begin(), temp.end());
        dp[i] = temp[2]; //최댓값 저장
    }
    
    cout << dp[n];
    return;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> input_array(n+1, 0);
    
    for(int i=1; i<=n; i++) {
        int temp;
        cin >> temp;
        
        input_array[i] = temp;
    }
    
    winePick(input_array, n);
    return 0;
}