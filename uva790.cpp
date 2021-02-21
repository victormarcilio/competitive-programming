#include <bits/stdc++.h>

using namespace std;

map<string, int> m;

struct team
{
	int ind;
	int problems;
	int tempo;
	int rank;
	bool operator< (team t2) const
	{
		if(problems != t2.problems)
			return problems > t2.problems;
		if(tempo != t2.tempo)
			return tempo < t2.tempo;
		
			return ind < t2.ind;
		
	}
	
	bool operator== (team t2) const
	{
		return problems == t2.problems && tempo == t2.tempo;
	}
	
};

struct input
{
	int eq;
	int p;
	int tempo;
	char v;
	
	bool operator<(input i) const
	{
		if(tempo != i.tempo)
			return tempo < i.tempo;
		return v == 'N';
	}
	
	input(int EQ, int P, int t, char V)
	{
		eq = EQ; p = P; tempo = t; v = V;
	}
};

int main()
{	
	int t, h, m, n;
	char prob, v;
	team teams[26];
	scanf("%d\n", &n);
	int mtx[26][7], resolvidos[26][7];
	
	while(n--)
	{
		memset(mtx, 0, sizeof mtx);
		memset(resolvidos, 0, sizeof resolvidos);
		int maior = 0;
		for (int i = 1; i < 26; i++)
		{
			teams[i].problems = teams[i].tempo = 0;
			teams[i].ind = i;
		}
		char linha[100];
		vector<input> inp;
		while(gets(linha), !feof(stdin) && linha[0])
		{
			sscanf(linha, "%d %c %d:%d %c\n", &t, &prob, &h, &m, &v);
			inp.push_back(input(t, prob - 'A', h*60 + m, v));
			maior = max(maior, t);
			linha[0] = 0;
		}
		sort(inp.begin(), inp.end());
		for(int i = 0; i < inp.size(); i++)
		{
			t = inp[i].eq; v = inp[i].v; prob = inp[i].p;
			int tempo = inp[i].tempo;
			
			if(!resolvidos[t][prob])
				if(v == 'Y')
				{
					teams[t].problems++;
					teams[t].tempo += mtx[t][prob] + tempo;
					resolvidos[t][prob] = 1;
				}
				else
					mtx[t][prob] += 20;
		}
		sort(teams + 1, teams + maior + 1);
		printf("RANK TEAM PRO/SOLVED TIME\n");
		if(teams[1].problems)
			printf("%4d %4d %4d %10d\n", 1, teams[1].ind, teams[1].problems, teams[1].tempo);
		else
			printf("%4d %4d\n", 1, teams[1].ind);
		teams[1].rank = 1;
		for(int i = 2; i < maior + 1; i++)
		{
			if(teams[i] == teams[i - 1])
				teams[i].rank = teams[i - 1].rank;
			else
				teams[i].rank = i;
			if(teams[i].problems)
				printf("%4d %4d %4d %10d\n", teams[i].rank, teams[i].ind, teams[i].problems, teams[i].tempo);
			else
				printf("%4d %4d\n", teams[i].rank, teams[i].ind);
		}
		
		if(n)
			printf("\n");
	}
    return 0;
}
