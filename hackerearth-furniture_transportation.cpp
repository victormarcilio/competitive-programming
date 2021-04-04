//https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/furniture-transportation-2/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, m, n, l;
    cin >> n >> l >> m;
    int c = 0;
    int acc = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        if (v <= l)
        {
            acc++;
            if (acc >= m)
                c++;
        }
        else
            acc = 0;
    }
    cout << c << '\n';
}
