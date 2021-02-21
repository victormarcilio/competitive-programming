#include <bits/stdc++.h>

using namespace std;

struct p
{
	int ind;
	int pontos;
	int tempo;
	
	bool operator< (p p2) const
	{
		if(pontos != p2.pontos)
			return pontos > p2.pontos;
		if(tempo != p2.tempo)
			return tempo < p2.tempo;
		return ind < p2.ind;
	}
	p(int i)
	{
		ind = i;
		pontos = 0;
		tempo = 0;
	}
	p(){}
};

int main()
{	
	p players[101];
	int n, player, problem, tempo;
	scanf("%d%*[^0-9]", &n);
	char linha[20], res;
	int penalty[101][10];
	int resolvidos[101][10];
	while(n--)
	{
		set<int> s;
		memset(penalty, 0, sizeof penalty);
		memset(resolvidos, 0, sizeof resolvidos);
		for(int i = 1; i < 101; i++)
			players[i] = p(i);
		while(gets(linha), !feof(stdin) && linha[0])
		{
			sscanf(linha, "%d %d %d %c", &player, &problem, &tempo, &res);
			if(res == 'C' && !resolvidos[player][problem])
			{
				resolvidos[player][problem] = true;
				players[player].pontos++;
				players[player].tempo += penalty[player][problem] + tempo;
			}
			else if(res == 'I')
				penalty[player][problem] += 20;
			s.insert(player);
		}
		sort(players + 1, players + 101);
		for(int i = 1; i < 101; i++)
			if(s.find(players[i].ind) != s.end())
				printf("%d %d %d\n", players[i].ind, players[i].pontos, players[i].tempo);
		
		if(n)
			printf("\n");
	}
    return 0;
}
