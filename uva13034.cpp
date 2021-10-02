//https://onlinejudge.org/external/130/13034.pdf
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    scanf("%d", &x);
    for(int j = 1; j <= x; j++)
    {
        bool ans = true;
        int z;
        for(int i = 0; i < 13; i++)
        {
            scanf("%d", &z);
            ans = ans && z;
        }
        printf("Set #%d: %s\n", j, ans ? "Yes" : "No");
    }
}
