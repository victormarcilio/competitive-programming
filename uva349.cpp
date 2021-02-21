
#include <bits/stdc++.h>
using namespace std;


int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int x, c, n, caso = 1;

	next: while (scanf("%d %d", &c, &n), c)
	{
		int bad = 0;
		vector<vector<int>> votes;
		for (int i = 0; i < n; i++)
		{
			vector<int> vote;
			bool ok = true;
			vector<int> votos = { 0, 0, 0, 0, 0, 0 };
			for (int j = 0; j < c; j++)
			{
				scanf("%d", &x);
				if (x > 0 && x <= c)
				{
					vote.push_back(x);
					if (++votos[x] > 1)
						ok = false;
				}
				else
					ok = false;
			}
			if (ok)
				votes.push_back(vote);
			else
				bad++;
		}
		printf("Election #%d\n", caso++);
		if (bad)
			printf("   %d bad ballot(s)\n", bad);
		int playing[] = { 0, 1, 1, 1, 1, 1 };
		map<int, vector<int>> m;
		vector<int> votos(c + 1);
		for (int i = 0; i < votes.size(); i++)
			for (int j = 0; j < votes[i].size(); j++)
				if (playing[votes[i][j]])
				{
					votos[votes[i][j]]++;
					break;
				}
		for (int i = 1; i <= c; i++)
			m[votos[i]].push_back(i);
		while (m.size() > 1)
		{
			if (m.rbegin()->first > votes.size() / 2)
			{
				printf("   Candidate %d is elected.\n", m.rbegin()->second[0]);
				goto next;
			}
			playing[m.begin()->second[0]] = 0;
			m.clear();
			votos = vector<int>(c + 1);
			for (int i = 0; i < votes.size(); i++)
				for (int j = 0; j < votes[i].size(); j++)
					if (playing[votes[i][j]])
					{
						votos[votes[i][j]]++;
						break;
					}
			for (int i = 1; i <= c; i++)
				if(votos[i])
					m[votos[i]].push_back(i);
		}
		if (m.begin()->second.size() == 1)
			printf("   Candidate %d is elected.\n", m.rbegin()->second[0]);
		else
		{ 
			vector<int> &ref = m.begin()->second;
			printf("   The following candidates are tied: %d", ref[0]);
			for (int i = 1; i < ref.size(); i++)
				printf(" %d", ref[i]);
			printf("\n");
		}
	}

}
