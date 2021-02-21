#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int caso = 1, r, c, m, n, N;
	scanf("%d", &n);
	int v[400];
	char linha[30];
	while(n--)
	{
		memset(v, 0, sizeof v);
		scanf("%d %d %d %d\n", &r, &c, &m, &N);
		while(r--)
		{
			gets(linha);
			for(int i = 0; linha[i]; i++)
				v[linha[i]]++;
		}
		int maior = 0;
		for(int i = 'A'; i <= 'Z'; i++)
			maior = max(maior, v[i]);
		int sum = 0;
		for(int i = 'A'; i <= 'Z'; i++)
			sum += v[i] * (v[i] == maior ? m : N);
		
		printf("Case %d: %d\n", caso++, sum);
	}
	
    return 0;
}
