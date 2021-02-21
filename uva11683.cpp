#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, c, nv, v;
	while(scanf("%d", &a), a)
	{
		int cont = 0;
		scanf("%d", &c);
		scanf("%d", &nv);
		for(int i = 1; i < c; i++)
		{
			v = nv;
			scanf("%d", &nv);
			if(nv > v)
				cont += nv - v;
		}
		
		printf("%d\n", cont + a - nv);
	}
	
}
