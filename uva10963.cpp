#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, a, b, v;
	scanf("%d", &t);
	while(t--)
	{
		bool yes = true;
		scanf("%d", &n);
		scanf("%d %d", &a, &b);
		v = abs(a - b);
		while(--n)
		{
			scanf("%d %d", &a, &b);
			yes = yes && abs(a - b) == v;
		}
		printf("%s\n", yes ? "yes" : "no");
		if(t)
			printf("\n");
	}
}
