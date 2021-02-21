#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, cont = 0, v;
	char comando[10];
	scanf("%d\n", &n);
	while(n--)
	{
		scanf("%s", comando);
		if(comando[0] == 'r')
			printf("%d\n", cont);
		else
		{
			scanf("%d\n", &v);
			cont += v;
		}
	}
}
