#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, game = 1, g[1000], c[1000], G[10], C[10];
	while(scanf("%d", &n), n)
	{
		printf("Game %d:\n", game++);
		for(int i = 0; i < n; i++)
			scanf("%d", c + i);
		while(1)
		{
			for(int i = 0; i < n; i++)
				scanf("%d", g + i);
			if(!g[0])
				break;
			int strong = 0, weak = 0;
			memset(G, 0, sizeof G);
			memset(C, 0, sizeof C);
			for(int i = 0; i < n; i++)
				if(g[i] == c[i])
					strong++;
				else
				{
					G[g[i]]++;
					C[c[i]]++;
				}
			for(int i = 1; i < 10; i++)
				weak += min(C[i], G[i]);
			printf("    (%d,%d)\n", strong, weak);
		}
	}
    return 0;
}
