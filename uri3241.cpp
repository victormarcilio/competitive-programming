#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, left, right;
    char plus;
    string np;
    cin >> n;
    while (n--)
    {
        if (cin >> left >> plus >> right)
            cout << left + right << '\n';
        else
        {
            cin.clear();
            cin >> np;
            cout << "skipped\n";
        }
    }
}
