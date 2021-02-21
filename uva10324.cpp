#include <bits/stdc++.h>

using namespace std;

int main()
{
	char st[1000000];
	int n, a, b, c = 1;
	while(gets(st))
	{
		printf("Case %d:\n", c++);
		scanf("%d", &n);
		prox : while(n--)
		{			
			scanf("%d %d\n", &a, &b);
			if(a > b)
				swap(a, b);
			for(int i = a + 1; i <= b; i++)
				if(st[i] != st[i - 1])
				{
					printf("No\n");
					goto prox;
				}
			printf("Yes\n");
		}
	}
	
}
