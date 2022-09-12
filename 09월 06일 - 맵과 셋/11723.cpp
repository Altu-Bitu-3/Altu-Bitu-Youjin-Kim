#include <iostream>
#include <vector>

using namespace std;

vector<int> Commands(string command, vector<int> s){
        int n;
    
        if(0 == command.compare("add")){
            cin>>n;
            if(s[n] == 0) s[n] = 1;
        }
        else if (0 == command.compare("remove")){
            cin>>n;
            if(s[n] == 1) s[n] = 0;
        }
        else if (0 == command.compare("check")){
            cin>>n;
            
            if(s[n] == 0) cout<<"0\n";
            else cout<<"1\n";
        }
        else if (0 == command.compare("toggle")){
            cin>>n;
            
            if(s[n] == 0) s[n] = 1;
            else s[n] = 0;
        }
        else if (0 == command.compare("all")){
            vector<int> new_set(21, 0);
            for(int i=1; i<=20; i++) new_set[i] = 1;
            s = new_set;
        }
        else if (0 == command.compare("empty")){
            s.assign(21, 0);
        }  
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    string command = "";
    vector<int> s(21);
    
    cin>>n;
    while(n--){
        cin>>command;
        s = Commands(command, s);
    }
    return 0;
}