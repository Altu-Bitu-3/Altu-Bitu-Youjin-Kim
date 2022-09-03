#include <iostream>
#include <string>
#include <vector>
#include <sstream>

typedef struct POINT{ //점 구조체 생성
    int x;
    int y;
}point;

using namespace std;
vector<point> arr, sorted;

vector<string> splitString(string n, vector<string> x){ //ss 이용해서 split 함수 구현
    istringstream ss;
    string stringBuffer;
    
    ss.str(n);

    while(getline(ss, stringBuffer, ' ')) {
        x.push_back(stringBuffer);
    }

    return x;
}

point newPoint(int a, int b) { //새로운 구조체에 값 추가
    point newPoint;

    newPoint.x = a;
    newPoint.y = b;

    return newPoint;
}

void merge(int start, int mid, int end) {
    int p1 = start;
    int p2 = mid + 1;
    int k = start;
    
    while(p1 <= mid && p2 <= end) {
        if(arr[p1].y < arr[p2].y) {
            sorted[k++] = arr[p1++];
        }
        else {
            if(arr[p1].x < arr[p2].x) {
                sorted[k++] = arr[p1++];
            }
            else{
                sorted[k++] = arr[p2++];
            }
        }
    }
    
    while(p1 <= mid) {
        sorted[k++] = arr[p1++];
    }
    while(p2 <= end) {
        sorted[k++] = arr[p2++];
    }

    for(int i = start; i<=end; i++) {
        arr[i] = sorted[i];
    }
}

void mergeSort(int left, int right) {
    if(left < right) {
        int mid = (left+right)/2;
        mergeSort(left, mid);
        mergeSort(mid+1, right);
        
        merge(left,mid,right);
    }
}

int main() {
    
    int length = 0;
    cin >> length;
    cin.ignore();

    for(int i=0; i<length; i++){ //POINT로 구성된 arr에 새로운 POINT 추가
        vector<string> x;
        string n;

        int newX, newY = 0;
        getline(cin, n);

        x = splitString(n, x);

        newX = stoi(x[0]);
        newY = stoi(x[1]);

        arr.push_back(newPoint(newX, newY)); 
    }

    mergeSort(0, length-1);
    for (int i=0; i<length; i++) {
        cout << arr[i].x << " " << arr[i].y << "\n";
    }

    return 0;
}