#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, v, velho, c = 1;
	scanf("%d", &t);
	printf("Lumberjacks:\n");
	char linha[100];
	bool cres;
	while(t)
	{
		n = 9;
		scanf("%d", &velho);
		scanf("%d", &v);
		cres = v > velho;
		int b = 0, a = 0;
		while(--n)
		{
			velho = v;
			scanf("%d", &v);
			
			if(v < velho && cres || v > velho && !cres)
			{
				printf("Unordered\n");
				gets(linha);
				goto aew;
			}
		}
		printf("Ordered\n");
		aew: t--;
	}
}
