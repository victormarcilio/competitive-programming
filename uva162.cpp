#include <bits/stdc++.h>

using namespace std;

int main()
{
	char linha[100], *p;
	prox: while(gets(linha), linha[0] != '#')
	{
		stack<char> s[2];
		queue<char> q[2], mesa;
		int cont[] = {0, 0};
		
		int vez = 1; //non-dealer;
		p = linha + 1;
		for(int i = 0; i < 13; i++, p += 3)
		{
			s[vez].push(*p);
			vez = !vez;
		}
		for(int j = 0; j < 3; j++)
		{
			gets(linha);
			p = linha + 1;
			for(int i = 0; i < 13; i++, p += 3)
			{
				
				s[vez].push(*p);
				vez = !vez;
			}
			
		}
	
		while(!s[0].empty())
		{
			q[0].push(s[0].top());
			q[1].push(s[1].top());
			s[1].pop();
			s[0].pop();
		}
		int vezes = 1;
		bool face = false;
		int k = 0;
		while(1)
		{
			if(q[vez].empty())
			{
				//ENUNCIADO trolante pra dar Presentation Error
				printf("%d%3d\n", !vez + 1, q[!vez].size());
				goto prox;
			}
			char topo = q[vez].front();
			q[vez].pop();
			mesa.push(topo);
			vezes--;
			
			if(topo == 'A' || topo == 'K' || topo == 'J' || topo == 'Q')
			{
				face = true;
				vez = !vez;
				if(topo == 'A')
					vezes = 4;
				else if (topo == 'K')
					vezes = 3;
				else if(topo == 'Q')
					vezes = 2;
				else
					vezes = 1;
			}
			else if(!vezes)
			{
				vez = !vez;
				if(face)
				{
					face = false;
					while(!mesa.empty())
					{
						q[vez].push(mesa.front());
						mesa.pop();
					}
				}
				vezes = 1;
			}
		}
		
		
	}
}
