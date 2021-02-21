#include <bits/stdc++.h>
using namespace std;

/* Enunciado bugado! nos testes existem outros separadores além
	de números, espaços e os 4 sinais de pontuação informados...
	usar strtok não vai funcionar sem saber todos os separadores*/

int main()
{
	int k, n, caso = 1;
	char excuse[100];
	while(~scanf("%d %d\n", &k, &n))
	{
		vector<string> keys;
		while(k--)
		{
			gets(excuse);
			keys.push_back(excuse);
		}
		vector<pair<string, int>> v;
		while(n--)
		{
			gets(excuse);
			v.push_back({excuse, 0});
			for(int i = 0; excuse[i]; i++)
				if(!isalpha(excuse[i]))
					excuse[i] = ' ';
			char *p = strtok(excuse, " ");
			while(p)
			{
				for(auto i : keys)
					if(!strcasecmp(i.c_str(), p))
						v.back().second++;
				p = strtok(NULL, " ");
			}
		}
		int maior = 0;
		for(auto i : v)
			maior = max(maior, i.second);
		printf("Excuse Set #%d\n", caso++);
		for(auto i : v)
			if(maior == i.second)
				printf("%s\n", i.first.c_str());
		printf("\n");
	}
}