#include <bits/stdc++.h>

using namespace std;

int main()
{
	char c[500];
	int v[300];
	v['W'] = 64; v['H'] = 32; v['Q'] = 16; v['E'] = 8; v['S'] = 4; v['T'] = 2; v['X'] = 1; 
	while(gets(c), c[0] != '*')
	{
		char *p = strtok(c, "/");
		int res = 0;
		while(p)
		{
			int cont = 0;
			for(char *p2 = p; *p2; p2++) 
				cont += v[*p2];
			res += (cont == 64);
			p = strtok(NULL, "/");
		}
		printf("%d\n", res);
	}
}
