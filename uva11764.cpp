#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, v, velho, c = 1;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		scanf("%d", &v);
		int b = 0, a = 0;
		while(--n)
		{
			velho = v;
			scanf("%d", &v);
			if(v > velho)
				a++;
			if(v < velho)
				b++;
		}
		printf("Case %d: %d %d\n", c++, a, b);
	}
}
