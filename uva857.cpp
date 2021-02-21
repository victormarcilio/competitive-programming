#include <bits/stdc++.h>

using namespace std;


struct comando
{
	int a, b, c, d, e;
	
	void quantiza()
	{
		if(e <= 60)
			e = e < 30 ? 0 : 60;
		else if(e <= 120)
			e = e < 90 ? 60 : 120;
		else if(e <= 180)
			e = e < 150 ? 120 : 180;
		else if(e <= 240)
			e = e < 210 ? 180 : 240;
		else if(e <= 300)
			e = e < 270 ? 240 : 300;
		else if(e <= 360)
			e = e < 330 ? 300 : 360;
		else if(e <= 420)
			e = e < 390 ? 360 : 420;
		else if(e < 450)
			e = 420;
		else
		{
			e = 0;
			d++;
			if(d == 5)
			{
				c++;
				d = 1;
			}
		}
	}
	comando(int A = 0, int B = 0, int C = 0, int D = 0, int E = 0)
	{
		a = A; b = B; c = C; d = D; e = E;
	}		
	
	bool operator==(comando c2) const
	{
		return c == c2.c && d == c2.d && e == c2.e;
	}
};	

int main()
{
	int n, a, b, c, d, e, newN;
	bool vai[2000];
	comando comandos[2000];
	while(scanf("%d", &n), n != -1)
	{
		newN = n;
		memset(vai, true, sizeof vai);
		for(int i = 0; i < n; i++)
		{
			scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
			comandos[i] = comando(a, b, c, d, e);
			comandos[i].quantiza();
			if(!a)
			{
				for(int j = i - 1; j > -1; j--)
					if(b == comandos[j].b)
					{
						if(comandos[j] == comandos[i])
						{
							vai[i] = vai[j] = false;
							newN -= 2;
						}
						break;
					}
			}
		}
		printf("%d\n", newN);
		for(int i = 0; i < n; i++)
			if(vai[i])
				printf("%d %d %d %d %d\n", comandos[i].a, comandos[i].b, comandos[i].c, comandos[i].d, comandos[i].e);
	}
	printf("-1\n");
}
