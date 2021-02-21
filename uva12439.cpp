#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int n, d1, y1, d2, y2, m1, m2, dias, caso = 1;
	int meses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	map<string, int> mapa;
	mapa["January"] = 0; mapa["February"] = 1; mapa["March"] = 2; mapa["April"] = 3;
	mapa["May"] = 4; mapa["June"] = 5; mapa["July"] = 6; mapa["August"] = 7;
	mapa["September"] = 8; mapa["October"] = 9; mapa["November"] = 10; mapa["December"] = 11;
	
	scanf("%d\n", &n);
	char mes1[20], mes2[20];
	while(n--)
	{
		scanf("%s %d%*c%d\n", mes1, &d1, &y1);
		if(y1 % 4 == 0 && y1 % 100 != 0 || y1 % 400 == 0)
			meses[1] = 29;
		else
			meses[1] = 28;
		scanf("%s %d%*c%d\n", mes2, &d2, &y2);
		m1 = mapa[mes1];
		m2 = mapa[mes2];
		
		int leaps = 0;
		if(y1 != y2)
		{
			while(1)
			{
				if(m1 == 1 && d1 == 29)
					leaps++;
				d1++;
				if(d1 > meses[m1])
				{
					m1++;
					d1 = 1;
					if(m1 == 12)
					{
						y1++;
						m1 = 1;
						break;
					}
				}
			}
			
			if(y2 % 4 == 0 && y2 % 100 != 0 || y2 % 400 == 0)
				meses[1] = 29;
			else
				meses[1] = 28;
			
			while(m2 || d2 > 1)
			{
				if(m2 == 1 && d2 == 29)
					leaps++;
				d2--;
				if(!d2)
				{
					m2--;
					d2 = meses[m2];
				}
			}
			
			leaps += 97*((y2 - y1)/400);
			int years = (y2 - y1)%400;
			
			for(int i = 0; i < years; i++, y1++)
				if(y1 % 4 == 0 && y1 % 100 != 0 || y1 % 400 == 0)
					leaps++;			
		}
		else
		{
			if(y1 % 4 == 0 && y1 % 100 != 0 || y1 % 400 == 0)
				if(m1 < 2 && (m2 > 1 || m2 == 1 && d2 == 29))
					leaps++;
		}
		printf("Case %d: %d\n", caso++, leaps);
	}
	
    return 0;
}
