#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int n, caso = 1, k, h, m, t, H, M, ti, TI;
	scanf("%d", &n);
	while(n--)
	{
		int melhor = 10000000;
		scanf("%d %d:%d", &k, &h, &m);
		ti = h * 60 + m;
		for(int i = 0; i < k; i++)
		{
			scanf("%d:%d %d", &H, &M, &t);
			TI = H * 60 + M;
			
			// Esse teste é necessário... não foi informado que os onibus sairiam no mesmo dia
			// submeti sem ele pra confirmar e tomei WA
			if(TI < ti)
				TI += 24*60;
			melhor = min(melhor, TI - ti + t);
		}
		printf("Case %d: %d\n", caso++, melhor);
	}
    return 0;
}
