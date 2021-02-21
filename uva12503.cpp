#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, a, pos;
	int v[101];
	char comando[10];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d\n", &n);
		pos = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", comando);
			if(comando[0] == 'L')
			{
				v[i] = -1;
				pos--;
			}
			else if(comando[0] == 'R')
			{
				v[i] = 1;
				pos++;
			}
			else
			{
				scanf(" %s %d", comando, &a);
				v[i] = v[a];
				pos += v[i];
			}
		}
		printf("%d\n", pos);
	}
}
