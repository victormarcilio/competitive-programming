#include <bits/stdc++.h>

using namespace std;


int main()
{
	int caso = 1, n;
	scanf("%d", &n);
	while(n--)
	{
		double p;
		scanf("%lf", &p);
		double tax = 0;
		if(p <= 180000)
		{
			printf("Case %d: 0\n", caso++, p);
			continue;
		}
		p -= 180000;
		if(p >= 300000)
		{
			p -= 300000;
			tax += 30000;
		}
		else
		{
			tax += p*0.1;
			p = 0;
		}
		
		if(p >= 400000)
		{
			p -= 400000;
			tax += 60000;
		}
		else
		{
			tax += p*0.15;
			p = 0;
		}
		
		if(p >= 300000)
		{
			p -= 300000;
			tax += 60000;
		}
		else
		{
			tax += p*0.2;
			p = 0;
		}
		if(p > 0)
			tax += p/4;
	
		printf("Case %d: %.0lf\n", caso++, max(2000., ceil(tax)));
		
	}
}
