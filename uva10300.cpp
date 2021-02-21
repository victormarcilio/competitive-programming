#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, a, b, c;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		int budget = 0;
		while(n--)
		{
			scanf("%d %d %d", &a, &b, &c);
			budget += a * c;
		}
		printf("%d\n", budget);
	}
}
