    //https://www.urionlinejudge.com.br/judge/pt/problems/view/2296
    #include<bits/stdc++.h>
    using namespace std;

    int main()
    {
        int n, k, ans = 1;
        int v[1000];
        int best = 50000;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &k);
            int left = 0, right = 0;
            for(int j = 0; j < k; j++)
                scanf("%d", v + j);
            for(int j = 1; j < k; j++)
            {
                if(v[j] > v[j - 1])
                    left += v[j] - v[j - 1];
                else if(v[j] < v[j - 1])
                    right += v[j - 1] - v[j];
            }
            if(best > min(left, right))
            {
                ans = i;
                best = min(left, right);
            }
        }
        printf("%d\n", ans);
    }
