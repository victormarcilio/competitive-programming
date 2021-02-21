
#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n, caso = 1, antigo, novo, primeiro;
	
	while (scanf("%d\n", &n), n)
	{
		printf("Case %d:\n", caso++);
		scanf("%d", &antigo);
		primeiro = antigo;
		while (--n)
		{
			scanf("%d", &novo);
			if (novo != antigo + 1)
			{
				printf("0");
				if (antigo == primeiro)
					printf("%d\n", primeiro);
				else
				{
					char prim[15], sec[15];
					sprintf(prim, "%d", primeiro);
					sprintf(sec, "%d", antigo);
					int i = 0;
					for (; prim[i] == sec[i]; i++)
						printf("%c", prim[i]);
					printf("%s-%s\n", &prim[i], &sec[i]);
				}
				primeiro = novo;
			}
			antigo = novo;
		}
		printf("0");
		if (antigo == primeiro)
			printf("%d\n", primeiro);
		else
		{
			char prim[15], sec[15];
			sprintf(prim, "%d", primeiro);
			sprintf(sec, "%d", antigo);
			int i = 0;
			for (; prim[i] == sec[i]; i++)
				printf("%c", prim[i]);
			printf("%s-%s\n", &prim[i], &sec[i]);
		}
		printf("\n");
	}
}

