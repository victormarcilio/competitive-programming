//https://www.hackerearth.com/pt-br/challenges/competitive/march-circuits-21/algorithm/hill-150045b2/
//https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/hill-150045b2/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, target, cost;
    bool found;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> v(n + 2);
        vector<int> left(n + 2);
        vector<int> right(n + 2);
        for (int i = 1; i <= n; i++)
            cin >> v[i];
        v[n + 1] = 1;
        v[0] = 0;
        left[0] = 0;
        right[n + 1] = 0;

        for (int i = 1; i <= n; i++)
            if (v[i] < v[i - 1])
                left[i] = left[i - 1] + 1;
            else
                left[i] = 0;

        for (int i = n; i; i--)
            if (v[i] < v[i + 1])
                right[i] = right[i + 1] + 1;
            else
                right[i] = 0;
        cout << left[1] + 1 + right[1];
        for (int i = 2; i <= n; i++)
            cout << ' ' << left[i] + 1 + right[i];
        cout << '\n';
    }
}
