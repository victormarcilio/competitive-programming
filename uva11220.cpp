#include <bits/stdc++.h>

using namespace std;
int main()
{
	int n;
	scanf("%d\n", &n);
	int caso = 1;
	char linha[2000];
	while(n--)
	{
		printf("Case #%d:\n", caso++);
		while(gets(linha), linha[0])
		{
			char *p = strtok(linha, " ");
			int k = 0;
			while(p)
			{
				if(strlen(p) > k)
					printf("%c", p[k++]);
				p = strtok(NULL, " ");
			}
			printf("\n");
			linha[0] = 0;
		}
		if(n)
			printf("\n");
	}
    return 0;
}
