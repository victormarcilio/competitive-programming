#include <bits/stdc++.h>

using namespace std;

struct team
{
	string nome;
	int games;
	int wins;
	int scored;
	int against;
	int points;
	int loss;
	team(string s)
	{
		nome = s;
		loss = games = wins = scored = against = points = 0;
	}
	bool operator< (team t2) const
	{
		if (points != t2.points)
			return points > t2.points;
		if(wins != t2.wins)
			return wins > t2.wins;
		if(scored - against != t2.scored - t2.against)
			return scored - against > t2.scored - t2.against;
		if(scored != t2.scored)
			return scored > t2.scored;
		if(games != t2.games)
			return games < t2.games;
		
		string aux(nome);
		string aux2(t2.nome);
		for(int i = 0; i < aux.size(); i++)
			aux[i] = toupper(aux[i]);
		
		for(int i = 0; i < aux2.size(); i++)
			aux2[i] = toupper(aux2[i]);
		
		return aux < aux2;
	}
	team(){}
	
	void print(int i)
	{
		printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i, nome.c_str(), points, games, wins, games - wins - loss, loss, scored - against, scored, against);
	}
};

int main()
{	
	team equipes[30];
	int n, times, jogos, g1, g2;
	scanf("%d\n", &n);
	char t[100], t1[100], t2[100];
	
	while(n--)
	{
		map<string, int> mapa;
		gets(t);
		printf("%s\n", t);
		scanf("%d\n", &times);
		for(int i = 0; i < times; i++)
		{
			gets(t);
			equipes[i] = team(t);
			mapa[t] = i;
		}
		scanf("%d\n", &jogos);
		while(jogos--)
		{
			scanf("%[^#]#%d@%d#%[^\n]\n", t1, &g1, &g2, t2);
			int p1 = mapa[t1], p2 = mapa[t2];
			
			equipes[p1].games++; equipes[p2].games++;
			equipes[p1].scored += g1;
			equipes[p2].scored += g2;
			equipes[p1].against += g2;
			equipes[p2].against += g1;
			if(g1 > g2)
			{
				equipes[p1].wins++;
				equipes[p1].points += 3;
				equipes[p2].loss++;
			}
			else if(g1 < g2)
			{
				equipes[p1].loss++;
				equipes[p2].wins++;
				equipes[p2].points += 3;
			}
			else
			{
				equipes[p1].points++;
				equipes[p2].points++;
			}
		}
		sort(equipes, times + equipes);
		for(int i = 0; i < times; i++)
			equipes[i].print(i + 1);
		
		if(n)
			printf("\n");
	}
    return 0;
}
