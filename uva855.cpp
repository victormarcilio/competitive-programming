#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int t;
	int st[50000], av[50000];
	scanf("%d", &t);
	while(t--)
	{
		int s, a, f;
		scanf("%d %d %d", &s, &a, &f);
		for(int i = 0; i < f; i++)
			scanf("%d %d", &st[i], &av[i]);
		
		sort(av, av + f);
		sort(st, st + f);
		int i = f & 1 ? f/2 : f/2 - 1;
		printf("(Street: %d, Avenue: %d)\n", st[i], av[i]);
	}
    return 0;
}
