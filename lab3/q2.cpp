// Satya Narayan 
// 220001071

// Time Complexity  -> O(log(n + m))
// Space Complexity -> O(1)

// Code starts here
#include <bits/stdc++.h> 

using namespace std;


double median(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();
    if (n > m)
    {
        return median(b, a);
    }
    int low = 0, high = n;
    int N = n + m;
    int left = (N + 1) / 2;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int x = left - mid;

        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if (mid < n)
        {
            r1 = a[mid];
        }
        if (mid - 1 >= 0)
        {
            l1 = a[mid - 1];
        }
        if (x < m)
        {
            r2 = b[x];
        }
        if (x - 1 >= 0)
        {
            l2 = b[x - 1];
        }

        if (l1 <= r2 && l2 <= r1)
        {
            if (N % 2)
            {
                return max(l1, l2);
            }
            else
            {
                return (max(l1, l2) + min(r1, r2)) * 1.0 / 2;
            }
        }
        else if (l1 > r2)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return 0;
}

int main()
{
    // Taking input from input.in and giving output to output.out
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    long long t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        long long n, m;
        cin >> n >> m;
        vector<int> A(n), B(m);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        for (int i = 0; i < m; i++)
            cin >> B[i];

        double ans = median(A, B);

        cout << "The median of testcase " << tt << " is -> " << ans << endl;
    }
}