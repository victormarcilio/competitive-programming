//https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/xsquare-and-coin-collection-2/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, k, val;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        long long ans = 0, acc = 0;
        while(n--)
        {
            cin >> val;
            if(val <= k)
                acc+= val;
            else
            {
                ans = max(ans, acc);
                acc = 0;
            }
        }
        cout << max(ans, acc) << '\n';
    }
}
