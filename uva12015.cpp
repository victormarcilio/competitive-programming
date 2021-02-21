#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, maior, caso = 1;
	char paginas[10][100];
	int ranks[10];
	scanf("%d\n", &t);
	while(t--)
	{
		scanf("%s %d\n", paginas[0], &maior);
		ranks[0] = maior;
		for(int i = 1; i < 10; i++)
		{
			scanf("%s %d\n", paginas[i], &ranks[i]);
			maior = max(maior, ranks[i]);
		}
		printf("Case #%d:\n", caso++);
		for(int i = 0; i < 10; i++)
			if(ranks[i] == maior)
				printf("%s\n", paginas[i]);
	}
}
