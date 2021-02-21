#include <bits/stdc++.h>
using namespace std;

void parse(char * eq, vector<int> &x, vector<int> &livre)
{
	int i = 0, sinal = 1;
	if(eq[0] == 'x')
	{
		x.push_back(1);
		sinal = (eq[1] == '-'? -1 : 1);
		i+= 2;
	}
	else if(!isdigit(eq[0]))
	{
		sinal = (eq[0] == '-'? -1 : 1);
		i++;
	}
	for(; eq[i]; i++)
	{
		if(eq[i] == 'x')
		{
			x.push_back(sinal);
			sinal = (eq[i + 1] == '-'? -1 : 1);
			i++;
		}
		else
		{
			int num = eq[i] - '0';
			while(isdigit(eq[i + 1]))
			{
				num = num * 10 + eq[i + 1] - '0';
				i++;
			}
			if(eq[i + 1] == 'x')
			{
				x.push_back(sinal*num);
				i++;
				if(eq[i + 1])
				{
					sinal = (eq[i + 1] == '-'? -1 : 1);
					i++;
				}
			}
			else
			{
				livre.push_back(sinal*num);
				if(eq[i + 1])
				{
					sinal = (eq[i + 1] == '-'? -1 : 1);
					i++;
				}
			}
		}
	}
	
}

int main()
{
	int n;
	
	scanf("%d\n", &n);
	char esq[1000], dir[1000];
	while(n--)
	{
		memset(esq, 0, sizeof esq);
		memset(dir, 0, sizeof dir);
		scanf("%[^=]%*c%s\n", esq, dir);
		vector<int> xesq, Esq, xdir, Dir;
	
		parse(esq, xesq, Esq);
		parse(dir, xdir, Dir);
		
		int lesq = 0, ldir = 0, XESQ = 0, XDIR = 0;
		
		for(auto i : Esq)
			lesq += i;
		
		for(auto i : xesq)
			XESQ += i;
		
		for(auto i : Dir)
			ldir += i;
		
		for(auto i : xdir)
			XDIR += i;
		
		if(XDIR == XESQ && ldir != lesq)
			printf("IMPOSSIBLE\n");
		else if(XDIR == XESQ && ldir == lesq)
			printf("IDENTITY\n");
		else
			printf("%d\n", (int)floor(double((ldir - lesq))/(XESQ - XDIR)));
		
	}
}