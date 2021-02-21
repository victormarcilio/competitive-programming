#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, c;
	char linha[2000010];
	prox: while(scanf("%d\n", &n), n)
	{
		gets(linha);
		int m = 2000000000, r = -1, d = -1;
		for(int i = 0; linha[i]; i++)
			if(linha[i] == 'Z')
			{
				printf("0\n");
				goto prox;
			}
			else if(linha[i] == 'R')
			{
				if(d != -1)
					m = min(m, i - d);
				r = i;
			}
			else if(linha[i] == 'D')
			{
				if(r != -1)
					m = min(m, i - r);
				d = i;
			}
		printf("%d\n", m);
	}
	
}
