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
    
    int t, n, x;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &x);
        deque<int> d;
        int v;        
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &v);
            d.push_back(v);
        }
        if (accumulate(begin(d), end(d), 0) == x)
            printf("NO\n");
        else
        {
            int acc = 0;
            printf("YES\n");
            if (d.front() != x)
            {
                printf("%d", d.front());
                acc = d.front();
                d.pop_front();
            }
            else
            {
                printf("%d", d.back());
                acc = d.back();
                d.pop_back();
            }
            while (!d.empty())
            {
                if (acc + d.front() != x)
                {
                    acc += d.front();
                    printf(" %d", d.front());
                    d.pop_front();
                }
                else
                {
                    acc += d.back();
                    printf(" %d", d.back());
                    d.pop_back();
                }
            }
            printf("\n");
        }
    }
    
}