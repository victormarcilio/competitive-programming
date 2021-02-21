#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, caso = 1;
	char linha[100010];
	scanf("%d\n", &n);
	int v[100];
	while(n--)
	{
		memset(v, 0, sizeof v);
		gets(linha);
		int pos = 0;
		for(int i = 0; linha[i]; i++)
		{
			if(linha[i] == '+')
				v[pos] = (v[pos] + 1)%256;
			else if(linha[i] == '-')
				v[pos] = (v[pos] + 255)%256;
			else if(linha[i] == '>')
				pos = (pos + 1)%100;
			else if(linha[i] == '<')
				pos = (pos + 99)%100;
		}
		
		printf("Case %d: %02X", caso++, v[0]);
		for(int i = 1; i < 100; i++)
			printf(" %02X", v[i]);
		printf("\n");
	}
	
}
