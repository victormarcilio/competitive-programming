#include <bits/stdc++.h>

using namespace std;

int main()
{
	int b, n, saldo[20], paga, recebe, v;
	while(scanf("%d %d", &b, &n), b || n)
	{
		for(int i = 0; i < b; i++)
			scanf("%d", &saldo[i]);
		for(int i = 0; i < n; i++)
		{
			scanf("%d %d %d", &paga, &recebe, &v);
			paga--;
			recebe--;
			saldo[paga] -= v;
			saldo[recebe] += v;
		}
		for(int i = 0; i < b; i++)
			if(saldo[i] < 0)
			{
				printf("N\n");
				goto aew;
			}
		printf("S\n"); aew: ;
	}
}
