#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int Euclidean(int a, int b)
{
    int r = a % b;
    if (r == 0) {
      return b;
    }
    return Euclidean(b, r);
}

int main() {
    string str;
    cin >> str;
    
    string ss_buffer;
    vector<int> n;
    
    stringstream ss(str);
    while(getline(ss, ss_buffer, ':')){
        n.push_back(stoi(ss_buffer));
    }
    
    int gcd = Euclidean(n[0], n[1]);
    cout << n[0]/gcd << ":" << n[1]/gcd;
    
    return 0;
}