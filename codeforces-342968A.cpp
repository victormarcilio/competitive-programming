//http://codeforces.com/gym/342968/problem/A
#include<bits/stdc++.h>
using namespace std;
 
using vi = vector<int>;
using vvi = vector<vector<int>>;
 
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int start;
    int finish;
    for (int i = 1; i < n; i++)
    {
        if (v[i] < v[i - 1])
        {
            start = i;
            break;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if(v[i + 1] > v[i])
        {
            finish = i + 1;
            break;
        }
    }
    cout << 1 + min_element(begin(v) + start, begin(v) + finish) - begin(v);
}