#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL); 
    int n;
    int ans = 10;
    int atual, old;
    cin >> n >> old;
    while(--n)
    {
        cin >> atual;
        if(atual - old >= 10)
            ans += 10;
        else
            ans += atual - old;
        old = atual;
    }   
    cout << ans << '\n';
}