#include <bits/stdc++.h>
/* Mal elaborado, nao informa a quantidade maxima de sinais por caso! */
using namespace std;

int main()
{
	int lim = 5 * 3600;
	int x, segundos;
	prox: while(scanf("%d", &segundos), segundos)
	{
		vector<int> v;
		int start = segundos - 5;
		v.push_back(segundos);
		while(scanf("%d", &x), x)
		{
			v.push_back(x);
			start = min(start, x - 5);
		}
		for(segundos = start; segundos <= lim; segundos++)	
		{
			bool vai = true;
			for(int i = 0; i < v.size(); i++)
			{
				int ciclo = segundos / v[i];
				if(ciclo & 1 || segundos%v[i] >= v[i] - 5)
				{
					vai = false;
					break;
				}
				
			}
			if(vai)
			{
				int h = segundos/3600;
				segundos = segundos%3600;
				int m = segundos/60;
				int s = segundos%60;
				printf("%02d:%02d:%02d\n", h, m, s);
				goto prox;
			}
		}
		printf("Signals fail to synchronise in 5 hours\n");
	}
}
