#include <iostream>

using namespace std;

int main()
{
    int red = 0, brown = 0;
    cin >> red >> brown;
     
    //a = 가로 길이, b = 세로 길이
    
    //R이 8부터 5000 사이: a*b는 3*3부터 시작
    
    //a*b - brown == red
    //brown == (a-2)*(b-2)
    //a*b - a*b + 2a + 2b - 4 == red
    //2a + 2b - 4 == red이면 성공 후 exit!!
    
    for(int a=3; a<5000; a++) {
        for(int b=3; b<5000; b++) {
            
            if(2*a + 2*b - 4 == red) {
                
                if(a*b == red+brown && a>=b) {
                    cout << a << " " << b;
                    exit(0);
                }
            }
        }
    }
    return 0;
}
