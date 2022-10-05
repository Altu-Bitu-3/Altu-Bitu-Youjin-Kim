#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void maxSubArray(vector<int> input, int n) {
    vector<int> dp(n+1, 0);
    vector<int>::iterator result;
    
    for(int i=1; i<=n; i++) {
        for(int j=0; j<i; j++) {
            if(input[i] > input[j] && dp[i] <= dp[j]) {
                dp[i] = dp[j] + 1;
            } } } //한 칸씩 진행하면서 지난 칸 돌아보며 증가할 시 dp에 저장
    
    result = max_element(dp.begin(), dp.end());
    cout << *result;
}

int main(){
    int n;
    cin >> n;
    
    vector<int> input_array(n+1, 0);

    for(int i=1; i<=n; i++) {
        int temp;
        cin >> temp;
        
        input_array[i] = temp;
    } //input
    //처음에 for문 안의 변수도 n으로 하고 여기도 n으로 했다가 한참 동안 틀렸었다…….
    //아쉬운 실수가 일어나지 않게 변수 겹침을 꼭 조심하자.

    maxSubArray(input_array, n);
    return 0;
}