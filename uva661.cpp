#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, c, dev[20], on[20], power, maior, v, caso = 1;
	
	while(scanf("%d %d %d", &n, &m, &c), m || c || n)
	{
		memset(on, 0, sizeof on);
		maior = power = 0;
		
		for(int i = 0; i < n; i++)
			scanf("%d", dev + i);
		for(int i = 0; i < m; i++)
		{
			scanf("%d", &v);
			v--;
			if(on[v])
				power -= dev[v];
			else
			{
				power += dev[v];
				maior = max(maior, power);
				if(power > c)
				{
					printf("Sequence %d\nFuse was blown.\n\n", caso++);
					while(++i < m)
						scanf("%d", &v);
				}

			}
			on[v] = !on[v];
		}
		if(maior <= c)
			printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n", caso++, maior);
		
	}
	
}
