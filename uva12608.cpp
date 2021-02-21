
#include <bits/stdc++.h>
using namespace std;


int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int t, w, n, xi, wi;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &w, &n);
		int ans = 0;
		for (int i = 0, wt = w; i < n; i++)
		{
			scanf("%d %d", &xi, &wi);
			if (wt == wi)
			{
				wt = w;
				ans += 2 * xi;
			}
			else if (wt < wi)
			{
				ans += 2 * xi;
				if (wi == w)
				{
					wt = w;
					ans += 2 * xi;
				}
				else
					wt = w - wi;
			}
			else
			{
				wt -= wi;
				if (i + 1 == n)
					ans += 2*xi;
			}
		}
		printf("%d\n", ans);
	}
}
