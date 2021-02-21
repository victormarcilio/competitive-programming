#include <bits/stdc++.h>
/*
	Provavelmente tem caso de teste iniciando com espaço em branco!
	ler com o N com %d\n e usar gets acaba eliminando os espaços em branco do inicio
	da primeira string!!
*/
using namespace std;

int main()
{
	int v[5000];
	v['a'] = v[' '] = v['d'] = v['g'] = v['j'] = v['m'] = v['p'] = v['t'] = v['w'] = 1;
	v['b'] = v['e'] = v['h'] = v['k'] = v['n'] = v['q'] = v['u'] = v['x'] = 2;
	v['c'] = v['f'] = v['i'] = v['l'] = v['o'] = v['r'] = v['v'] = v['y'] = 3;
	v['s'] = v['z'] = 4;
	int n, caso = 1;
	char linha[110];
	gets(linha);
	while(gets(linha))
	{
		int k = 0;
		for(int i = 0; linha[i]; i++)
			k += v[linha[i]];
		printf("Case #%d: %d\n", caso++, k);
	}
}
