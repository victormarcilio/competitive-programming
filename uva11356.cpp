#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int n, d, m, y, dias, caso = 1;
	int meses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	map<string, int> mapa;
	mapa["January"] = 0; mapa["February"] = 1; mapa["March"] = 2; mapa["April"] = 3;
	mapa["May"] = 4; mapa["June"] = 5; mapa["July"] = 6; mapa["August"] = 7;
	mapa["September"] = 8; mapa["October"] = 9; mapa["November"] = 10; mapa["December"] = 11;
	
	scanf("%d", &n);
	char mes[20];
	while(n--)
	{
		scanf("%d-%[^-]%*c%d", &y, mes, &d);
		m = mapa[mes];
		scanf("%d", &dias);
		if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
			meses[1] = 29;
		else
			meses[1] = 28;
		while(dias--)
		{
			d++;
			if(d > meses[m])
			{
				d = 1;
				m++;
				if(m == 12)
				{
					m = 0;
					y++;
					
					if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
						meses[1] = 29;
					else
						meses[1] = 28;
				}
			}
		}
		
		printf("Case %d: %d-", caso++, y);
		for(auto it : mapa)
			if(it.second == m)
			{
				printf("%s", it.first.c_str());
				break;
			}
		printf("-%02d\n", d);
	}
	
    return 0;
}
