#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, n, b, c = 1, g2;
	scanf("%d", &n);
	char g[100];
	while(n--)
	{
		scanf("%d", &a);
		gets(g);
		b = 0;
		for(int i = 0; g[i]; i++)
			if(isdigit(g[i]))
			{
				b = g[i] - '0';
				break;
			}
		printf("Case %d: %.5g\n", c++, a * 0.5 + b * 0.05);
	}
}
