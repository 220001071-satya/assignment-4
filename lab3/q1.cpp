// Satya Narayan 
// 220001071

// time comlexicity O(nlogn)

// this method uses merge sort as a subroutine and calcualtes inversions while sorting the array 


#include <bits/stdc++.h>
using namespace std;

int mergeAndInversions(vector<int>& ve, int start, int mid, int end){
    int n = mid - start + 1;
    int m = end - mid;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++){
        a[i] = ve[start + i];
    }
    for(int i = 0; i < m; i++) b[i] = ve[mid + 1 + i];
    int i = 0, j = 0, k = 0;
    int count = 0;
    while(i < n && j < m){
        if(a[i] > b[j]){
            ve[start + k] = b[j];
            j++;
            count += n - i;
        }
        else {
            ve[start + k] = a[i];
            i++;
        }
        k++;
    }
    while(i < n) {
        ve[start + k] = a[i];
        i++;
        k++;
    }
    while(j < m){
        ve[start + k] = b[j];
        k++;
        j++;
    }
    return count;
}
int sortAndInversions(vector<int>& ve, int start, int end){
    if(end <= start) return 0;
    int mid = (start + end)/2;
    int x = sortAndInversions(ve, 0, mid);
    x += sortAndInversions(ve, mid + 1, end);
    x += mergeAndInversions(ve, 0, mid, end);
    return x;
}
int main(){
    int n;
    cin >> n;
    vector<int> ve(n);
    for(int i = 0; i < n; i++) cin >> ve[i];
    int ans = sortAndInversions(ve, 0, n - 1);
    cout << ans << " ";
}