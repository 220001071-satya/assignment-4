// Satya Narayan 
// 220001071

// time comlexicity O(k + (n - k)log(k)) 

// use a min heap to achieve this 

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> ve(n);
    for(int i = 0; i < n; i++) cin >> ve[i];
    priority_queue<int, vector<int>, greater<int>> pq(ve.begin(), ve.begin() + k);
    for(int i = k; i < n; i++){
        pq.push(ve[i]);
        pq.pop();
    }
    cout << pq.top();

}