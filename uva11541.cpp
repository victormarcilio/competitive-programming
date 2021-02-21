#include <bits/stdc++.h>

using namespace std;
int main()
{
	int n, k, caso = 1;
	char c;
	scanf("%d\n", &n);
	while(n--)
	{
		printf("Case %d: ", caso++);
		while(scanf("%c", &c), c != '\n')
		{
			scanf("%d", &k);
			for(int i = 0; i < k; i++)
				printf("%c", c);
		}
		printf("\n");
	}
    return 0;
}
