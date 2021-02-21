#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, v, c = 1;
	scanf("%d", &t);
	while(t--)
	{
		int c1 = 0, c2 = 0;
		printf("Case %d: ", c++);
		scanf("%d", &n);
		while(n--)
		{
			scanf("%d", &v);
			c1 += 10*(v/30 + 1);
			c2 += 15*(v/60 + 1);
		}
		if(c1 == c2)
			printf("Mile Juice %d\n", c1);
		else if(c1 < c2)
			printf("Mile %d\n", c1);
		else
			printf("Juice %d\n", c2);
	}
}
