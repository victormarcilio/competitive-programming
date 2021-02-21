#include <bits/stdc++.h>

using namespace std;

void check(char c, set<char> &s, map<char, vector<pair<char, char> >> &m)
{
	for(int i = 0; i < m[c].size(); i++)
		for(int j = i + 1; j < m[c].size(); j++)
			if(m[c][i].first == m[c][j].first && m[c][i].second != m[c][j].second)
			{
				s.erase(c);
				return;
			}
			else if(m[c][i].first != m[c][j].first && m[c][i].second == m[c][j].second)
			{
				s.erase(c);
				return;
			}
}

int main()
{
	int n, ind;
	scanf("%d\n", &n);
	char b1[7], b2[7], c[5];
	
	prox: while(n--)
	{
		set<char> suspeitos;
		map<char, vector<pair<char, char> >> m;
		for(char i = 'A'; i < 'M'; i++)
			suspeitos.insert(i);
		
		for(int i = 0; i < 3; i++)
		{
			scanf("%s %s %s", b1, b2, c);
			for(int i = 0; b1[i]; i++)
				m[b1[i]].push_back(make_pair('L', c[0]));
			for(int i = 0; b2[i]; i++)
				m[b2[i]].push_back(make_pair('R', c[0]));
			
			if(c[0] == 'e')
			{
				for(int i = 0; b1[i]; i++)
					suspeitos.erase(b1[i]);
				for(int i = 0; b2[i]; i++)
					suspeitos.erase(b2[i]);
			}
			else
			{
				set<char> temp;
				for(int i = 0; b1[i]; i++)
					temp.insert(b1[i]);
				for(int i = 0; b2[i]; i++)
					temp.insert(b2[i]);
				
				for(char i = 'A'; i < 'M'; i++)
					if(temp.find(i) == temp.end())
						suspeitos.erase(i);
			}		
		}
		
		for(char i = 'A'; i < 'M'; i++)
			if(suspeitos.find(i) != suspeitos.end())
				check(i, suspeitos, m);
		char culpado = *suspeitos.begin();
		for(auto it : m[culpado])
			if(it.second == 'e')
				continue;
			else if( it.second == 'u' && it.first == 'L' || it.second == 'd' && it.first == 'R')
			{
				printf("%c is the counterfeit coin and it is heavy.\n", culpado);
				break;
			}
			else
			{
				printf("%c is the counterfeit coin and it is light.\n", culpado);
				break;
			}
				
	}
}
