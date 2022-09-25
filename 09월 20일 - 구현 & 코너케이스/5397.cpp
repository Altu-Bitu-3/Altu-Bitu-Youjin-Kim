#include <iostream>
#include <string>
#include <list>

using namespace std;

void findPassword(string keylogger) {
    list<char> password;
    list<char> ::iterator cur = password.begin();
    
    for(int i=0; i<keylogger.length(); i++) {
        if(keylogger[i] == '>') {
            if(cur != password.end()) cur++;}
        
        else if(keylogger[i] == '<') {
            if(cur != password.begin()) cur--;}
        
        else if(keylogger[i] == '-') {
            if(cur != password.begin()) cur = password.erase(--cur);}
        
        else {
            password.insert(cur, keylogger[i]);}
    }
    
    for(auto i: password) cout << i;
    cout << '\n';
}

int main()
{
    string keylogger;
    
    int n = 0;
    cin >> n;
    
    while(n--) {
        cin >> keylogger;
        findPassword(keylogger);
    }
    
    return 0;
}
