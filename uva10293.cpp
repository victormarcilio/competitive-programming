#include <bits/stdc++.h>

using namespace std;
int main()
{
	char st[10000] = "";
	char linha[100];
	while(gets(linha))
	{
		if(linha[0] == '#')
		{
			map<int, int> m;
			char *p = strtok(st, " .,!?");
			while(p)
			{
				int tam = 0;
				for(char *p2 = p; *p2; p2++)
					if(isalpha(*p2))
						tam++;
				m[tam]++;
				p = strtok(NULL, " .,!?");
			}
			for(auto it : m)
				printf("%d %d\n", it.first, it.second);
			printf("\n");
			st[0] = 0;
		}
		else
		{
			int len = strlen(st);
			if(st[len - 1] == '-')
				strcpy(&st[len - 1], linha);
			else
			{
				st[len] = ' ';
				strcpy(&st[len + 1], linha);
			}
			
		}
	}
}
