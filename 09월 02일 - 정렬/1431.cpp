#include <iostream>
#include <vector>
#include <string>

using namespace std;

int preProcess(string s) {
    int sum = 0;
    vector<char> v;
    
    v.reserve(s.size());
    copy (s.begin(), s.end(), back_inserter(v));

    int len = s.length();
    for(int i=0; i<len; i++) {
        if(v[i] >= '0' && v[i] <= '9'){
            int n=0;
            n = v[i] - '0';
            sum = sum + n;
        }
    }
    return sum;
}

vector<string> Dict(int i, vector<string> vc) {
    if(vc[i+1] < vc[i]) {
        string temp = "";

        temp = vc[i+1];
        vc[i+1] = vc[i];
        vc[i] = temp;
    }
    return vc;
}

vector<string> Sort(int i, vector<string> vc) {
    string temp = "";

    if(vc[i+1].length() < vc[i].length()){
            temp = vc[i+1];
            vc[i+1] = vc[i];
            vc[i] = temp;
        }

    else if(vc[i+1].length() == vc[i].length()){
        int s1 = preProcess(vc[i+1]);
        int s0 = preProcess(vc[i]);

        if(s1 < s0) {
            temp = vc[i+1];
            vc[i+1] = vc[i];
            vc[i] = temp;
        }
        
        else if(s1 == s0) {
            vc = Dict(i, vc);
        }
    }
    return vc;
}

int main() {
    int length = 0;
    cin >> length;

    vector<string> all_guitars;
    all_guitars.reserve(length);

    for(int i=0; i<length; i++){
        string serial = "";
        cin >> serial;
        
        all_guitars.push_back(serial);
    }
    
    int sort_len = length - 1;
    for(int i=0; i<sort_len; i++){
        for(int j=i; j>=0; j--){
            all_guitars = Sort(j, all_guitars);
        }
    }

    for(int i=0; i<length; i++){
        cout << all_guitars[i] << "\n";
    }
    return 0;
}