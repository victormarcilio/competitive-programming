#include <bits/stdc++.h>

using namespace std;

int v[1000];

struct carta
{
	char naipe, valor;
	
	bool operator <(carta c) const
	{
		if(naipe != c.naipe)
			return v[naipe] < v[c.naipe];
		return v[valor] < v[c.valor];
	}
	carta(char n, char v)
	{
		naipe = n;
		valor = v;
	}
};

int main()
{
	for(char i = '2'; i <= '9'; i++)
		v[i] = i - '2';
	v['N'] = 'E';
	v['E'] = 'S';
	v['S'] = 'W';
	v['H'] = 'Z';
	v['D'] = 'C';
	v['C'] = 'A';
	v['W'] = 'N';
	v['T'] = 10;
	v['J'] = 11;
	v['Q'] = 12;
	v['K'] = 13;
	v['A'] = 14;
	char vez, linha[100];

	while(scanf("%c\n", &vez), vez != '#')
	{
		map<char, vector<carta> > m;
		
		gets(linha);
		for(int i = 0; linha[i]; i+= 2)
			m[vez = v[vez]].push_back(carta(linha[i], linha[i + 1]));
		gets(linha);
		for(int i = 0; linha[i]; i+= 2)
			m[vez = v[vez]].push_back(carta(linha[i], linha[i + 1]));
		
		sort(m['N'].begin(), m['N'].end());
		sort(m['S'].begin(), m['S'].end());
		sort(m['W'].begin(), m['W'].end());
		sort(m['E'].begin(), m['E'].end());
		
		printf("S:");
		for(auto x : m['S'])
			printf(" %c%c", x.naipe, x.valor);
		
		printf("\nW:");
		for(auto x : m['W'])
			printf(" %c%c", x.naipe, x.valor);
		
		printf("\nN:");
		for(auto x : m['N'])
			printf(" %c%c", x.naipe, x.valor);
		
		printf("\nE:");
		for(auto x : m['E'])
			printf(" %c%c", x.naipe, x.valor);
		printf("\n");
	}
}
