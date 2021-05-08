//http://codeforces.com/problemset/problem/1520/B
#include<bits/stdc++.h>
#pragma warning(disable: 4996)
 
using namespace std;
 
 
int main()
{
#ifdef _DEBUG
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    int t, n;
    string s;
    cin >> t;
    set<long long> numbers;
    for (char c = '1'; c <= '9'; c++)
        for (int i = 1; i <= 9; i++)
            numbers.insert(stol(string(i, c)));
    while (t--)
    {
        cin >> n;
        int temp = 0;
        auto it = numbers.begin();
        while (it != numbers.end() && *it <= n)
        {
            temp++;
            it++;
        }
        cout << temp << '\n';
    }
    
}