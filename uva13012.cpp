//https://onlinejudge.org/external/130/13012.pdf
#include<bits/stdc++.h>
using namespace std;

int main()
{
     int x;
     while(~scanf("%d", &x))
    {
         int z, ans = 0;
         for(int i = 0; i < 4; i++)
        {
              scanf("%d", &z);
              ans += z == x;
        }
        printf("%d\n", ans);
    }
}
