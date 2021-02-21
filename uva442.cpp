#include <bits/stdc++.h>

using namespace std;

int main() 
{  
	map<char, pair<int, int>> m;
	char c;
	int x, y, n;
	scanf("%d\n", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%c %d %d\n", &c, &x, &y);
		m[c] = {x, y};
	}
	char linha[200];
	prox: while (gets(linha))
	{
		int i = 0;
		char ant;
		for(; linha[i]; i++)
			if(isalpha(linha[i]))
			{
				ant = linha[i];
				break;
			}
		for(i++; linha[i]; i++)
		{
			if(isalpha(linha[i]))
				if(m[ant].second != m[linha[i]].first)
				{
					printf("error\n");
					goto prox;
				}
				else
					ant = linha[i];
		}
		int res = 0;
		vector<pair<int, int>> v;
		for(i = 0; linha[i]; i++)
		{
			if(linha[i] == ')')
			{
				auto top = v.back(); v.pop_back();
				auto top2 = v.back(); v.pop_back();
				res += top2.first*top2.second*top.second;
				v.push_back({top2.first, top.second});
			}
			else if(linha[i] != '(')
				v.push_back(m[linha[i]]);
		}
		printf("%d\n", res);
		
	}
	
    return 0; 
} 
