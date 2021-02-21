#include <bits/stdc++.h>
/* leitura com treta, provavelmente tem casos onde a string da descrição é vazia */
using namespace std;

int main()
{
	int n, h1, h2, m1, m2, d = 1, lim = 60*18;
	char garbage[500000];
	int v[1600];
	while(scanf("%d\n", &n) != EOF)
	{
		memset(v, 0, sizeof v);
		for(int i = 0; i < n; i++)
		{
			gets(garbage);
			h1 = (garbage[0] - '0') * 10 + garbage[1] - '0';
			m1 = (garbage[3] - '0') * 10 + garbage[4] - '0';
			h2 = (garbage[6] - '0') * 10 + garbage[7] - '0';
			m2 = (garbage[9] - '0') * 10 + garbage[10] - '0';
			h1 = h1*60 + m1;
			h2 = h2*60 + m2;
			for(int i = h1; i < h2; i++)
				v[i]++;
		}
		int maior = 0;
		int acum = 0;
		int ini = 600;
		for(int i = 600; i < lim; i++)
			if(!v[i])
				acum++;
			else
			{
				if(acum > maior)
				{
					maior = acum;
					ini = i - acum;
				}
				acum = 0;
			}
			
		if(acum > maior)
		{
			maior = acum;
			ini = lim - acum;
		}
		if(maior > 59)
			printf("Day #%d: the longest nap starts at %d:%02d and will last for %d hours and %d minutes.\n", d++, ini/60, ini%60, maior/60, maior%60 );
		else
			printf("Day #%d: the longest nap starts at %d:%02d and will last for %d minutes.\n", d++, ini/60, ini%60, maior);
	}
}
