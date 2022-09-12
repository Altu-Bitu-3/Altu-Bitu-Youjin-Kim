#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

map<int, int> indice; //순서 저장하는 map
bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second)
		return indice[a.first] < indice[b.first];
	return a.second > b.second;
}

int main() {
    int n, c;
    cin >> n >> c;
    
    map<int, int> freqsort;
    for(int i=1; i<=n; i++) {
        int num;
        cin >> num;
        freqsort[num] = freqsort[num] + 1;
        
        if (indice[num] == 0) {
            indice[num] = i;
        }
    } //없었으면 인덱스 값 추가
    
    vector<pair<int, int>> sorted(freqsort.begin(), freqsort.end());
    sort(sorted.begin(), sorted.end(), cmp);
    
    for (auto x: sorted) {
		for (int i=0; i<x.second; i++){
			cout << x.first << " ";
		}
	}

	return 0;
}