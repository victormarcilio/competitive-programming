#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k_ini, i_ini;
	while(scanf("%d", &n), n)
	{
		vector<int> v;
		for(int i = 1; i <= n; i++)
			v.push_back(i);
		if(n%4)
			for(int i = 0; i < 4 - n%4; i++)
				v.push_back(-1);
		printf("Printing order for %d pages:\n", n);
		for(int i = 0, j = v.size() - 1, pagina = 1; i < j && v[i] != -1; i++, j--, pagina++)
		{
			if(v[j] == -1)
				printf("Sheet %d, front: Blank, %d\n", pagina , v[i]);
			else
				printf("Sheet %d, front: %d, %d\n", pagina , v[j], v[i]);
			i++; j--;
			if(i < j &&v[i] != -1)
			{
				if(v[j] == -1)
					printf("Sheet %d, back : %d, Blank\n", pagina , v[i]);
				else
					printf("Sheet %d, back : %d, %d\n", pagina , v[i], v[j]);
			}
		}
	}
}
