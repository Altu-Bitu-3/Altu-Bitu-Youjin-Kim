#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    
    vector<int> a_vec, b_vec;
    
    for(int i=0; i<a.size(); i++) {
        a_vec.push_back(a[i]-'0');
    }
    
    for(int i=0; i<b.size(); i++) {
        b_vec.push_back(b[i]-'0');
    }
    
    reverse(a_vec.begin(), a_vec.end());
    reverse(b_vec.begin(), b_vec.end());
    
    int length, gap;
    if(a_vec.size() > b_vec.size()) {
        length = a_vec.size();
        gap = a_vec.size() - b_vec.size();
        while(gap--) b_vec.push_back(0);
    }
    else{
        length = b_vec.size();
        gap = b_vec.size() - a_vec.size();
        while(gap--) a_vec.push_back(0);
    }
    
    int upper = 0;
    vector<int> sum;
    
    for (int i=0; i<length; i++) {
        int sum_res;
        sum_res = a_vec[i] + b_vec[i] + upper;
        
        if((a_vec[i] + b_vec[i] + upper) >= 10){
            upper = 1;
            sum_res = sum_res - 10;
        }
        else upper = 0;
        
        sum.push_back(sum_res);
    }
    
    if(upper != 0) {
        sum.push_back(upper);
    }
    
    reverse(sum.begin(), sum.end());
    for (int i=0; i<sum.size(); i++){
        cout << sum[i];
    }
}