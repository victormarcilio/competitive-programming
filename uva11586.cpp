#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	char linha[100010];
	scanf("%d\n", &n);
	int v[100];
	while(n--)
	{
		memset(v, 0, sizeof v);
		gets(linha);
		int m = 0, f = 0;
		for(int i = 0; linha[i]; i++)
		{
			m += (linha[i] == 'M');
			f += (linha[i] == 'F');
		}
		if(m == f && m > 1)
			printf("LOOP\n");
		else
			printf("NO LOOP\n");
	}
	
}
