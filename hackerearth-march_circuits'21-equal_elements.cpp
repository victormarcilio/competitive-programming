//https://www.hackerearth.com/pt-br/challenges/competitive/march-circuits-21/algorithm/equal-elements-2-db70c1ae/
//https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/equal-elements-2-db70c1ae/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, x, odds;
    cin >> t;
    while (t--)
    {
        cin >> n;
        odds = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            odds += x & 1;
        }
        cout << min(odds, n - odds) << '\n';
    }
}
