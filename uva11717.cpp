
#include <bits/stdc++.h>
using namespace std;


int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int t, n, i, k, active, x[1000], caso = 1;
	scanf("%d", &t);
	while (t--)
	{
		int rest = 0, ig = 0;
		scanf("%d %d %d", &n, &i, &k);
		active = i;
		
		for (int j = 0; j < n; j++)
			scanf("%d", &x[j]);
		for (int j = 0; j < n; j++)
		{
			if (x[j] >= active)
			{
				rest++;
				active = x[j] + k + i;
				int aux = x[j] + k;
				while (j + 1 < n && x[j + 1] < aux)
				{
					j++;
					ig++;
				}
			}
			else
				active = x[j] + i;
		}
		printf("Case %d: %d %d\n", caso++, rest, ig);
	}
}
