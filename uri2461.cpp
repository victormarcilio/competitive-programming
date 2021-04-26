#include<bits/stdc++.h>
#pragma warning(disable: 4996)

using namespace std;

int main()
{
#ifdef _LOCAL
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int v, n, m;
    scanf("%d %d", &n, &m);
    set<int> SA, SB;
    int B[10000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v);
        SA.insert(v);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &v);
        if (SA.find(v) != SA.end())
            SB.insert(v);
        else
        {
            bool found = false;
            for(auto it : SB)
                if (SB.find(v - it) != SB.end())
                {
                    found = true;
                    SB.insert(v);
                    break;
                }
            if (!found)
            {
                printf("%d\n", v);
                return 0;
            }
        }
    }

    printf("sim\n");
}
