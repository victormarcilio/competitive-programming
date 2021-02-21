#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	
	scanf("%d\n", &n);
	char eq[1000];
	prox: while(n--)
	{
		gets(eq);
		char *p = strtok(eq, "|");
		vector<string> v;
		while(p)
		{
			v.push_back(p);
			p = strtok(NULL, "|");
		}
		for(int i = 0; i < v.size(); i++)
		{
			map<char, pair<int, int>> m;
			for(char i = 'a'; i <= 'z'; i++)
				m[i] = {0, 0};
			
			strcpy(eq, v[i].c_str());
			p = strtok(eq, "(&)");
			while(p)
			{
				if(*p == '~')
					m[*(p + 1)].second = 1;
				else
					m[*p].first = 1;
				p = strtok(NULL, "(&)");
			}
			for(auto it : m)
				if(it.second.first && it.second.second)
					goto ops;
			printf("YES\n");
			goto prox;
			ops: ;
		}
		printf("NO\n");
		
	}
}