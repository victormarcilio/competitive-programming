//http://codeforces.com/group/btcK4I5D5f/contest/341073/problem/A
#include<bits/stdc++.h>
 
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ii = pair<int, int>;
 
int tira10(int x)
{
    if(x > 15)
    {
        return min(45, x - 15) * 10;
    }
    return 0;
}
 
int tira8(int x)
{
    if(x > 60)
    {
        return min(120, x - 60) * 8;
    }
    return 0;
}
 
int tira6(int x)
{
    if(x > 180)
    {
        return min(240, x - 180) * 6;
    }
    return 0;
}
 
int tira2(int x)
{
    if(x > 420)
    {
        return (x - 420) * 2;
    }
    return 0;
}
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, v;
    cin >> n;
    while(n--)
    {
        cin >> v;
        int cents = 0;        
        cents += tira10(v);
        cents += tira8(v);
        cents += tira6(v);
        cents += tira2(v);
 
        printf("%.2f\n", cents/100.0);
    }
}