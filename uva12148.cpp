#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int n;
	while(scanf("%d", &n), n)
	{
		int d, m, y, k, k2, d2, m2, y2;
		int soma = 0, count = 0;
		
		scanf("%d %d %d %d", &d, &m, &y, &k);
		m--;
		while(--n)
		{
			d2 = d; m2 = m; y2 = y; k2 = k;
			if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
				meses[1] = 29;
			else
				meses[1] = 28;
			
			scanf("%d %d %d %d", &d, &m, &y, &k);
			m--;
			
			d2++;
			if(d2 > meses[m2])
			{
				d2 = 1;
				m2++;
				if(m2 == 12)
				{
					m2 = 0;
					y2++;
				}
			}
			if(d2 == d && m2 == m && y2 == y)
			{
				count++;
				soma += k - k2;
			}
		}
		printf("%d %d\n", count, soma);
	}
    return 0;
}
