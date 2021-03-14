#include <bits/stdc++.h>
using namespace std;

int dp[100001], novos[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int V, M, val, counter;
    scanf("%d %d", &V, &M);
    dp[0] = 1;
    for(int i = 0; i < M; i++)
    {
        scanf("%d", &val);
        counter = 0;
        for(int j = 0; val + j <= V; j++)
            if(dp[j])
                if(val + j == V)
                {
                    puts("S");
                    return 0;
                }
                else
                    novos[counter++] = val + j;
        for(int j = 0; j < counter; j++)
            dp[novos[j]] = 1;
    }
    puts("N");
}
