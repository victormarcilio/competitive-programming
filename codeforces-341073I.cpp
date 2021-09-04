//http://codeforces.com/group/btcK4I5D5f/contest/341073/problem/I
#include<bits/stdc++.h>
 
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ii = pair<int, int>;
 
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    string genoma, padrao;
    cin >> n >> m >> genoma >> padrao;
 
    int pos = genoma.find(padrao);
    printf("%d", pos);
    while(pos != -1)
    {
        pos = genoma.find(padrao, pos + 1);
        if(pos != -1)
            printf(" %d", pos);
    }
    printf("\n");
}