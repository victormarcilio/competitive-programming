#include <bits/stdc++.h>

using namespace std;

bool teste(char *c, int codigo)
{
	int tam = strlen(c) - codigo;
	if(c[0] == '0' && tam >= 4 && tam <= 7 && codigo <= 6 )
		return true;
	if(c[0] == '0' && c[1] == '0' && tam >= 4 && tam <= 10 && codigo <= 5)
		return true;
	return false;
}
int main()
{
	map<string, pair<string, int>> m;
	char codigo[30], cidade[30], *p;
	int preco, minutos;
	
	while(scanf("%s", codigo), strcmp("000000", codigo))
	{
		scanf(" %[^$]%*1c%d", cidade, &preco);
		m[codigo] = make_pair(cidade, preco);
	}

	prox: while(scanf("%s %d\n", codigo, &minutos) == 2)
	{
		if(codigo[0] != '0')			
			printf("%-15s %-5s%30s%5d%6.2lf%7.2lf\n", codigo, "Local", codigo, minutos, 0.0, 0.0);
		else
		{
			for( auto it : m)
				if(strstr(codigo, it.first.c_str()) == codigo)
				{
					if(teste(codigo, it.first.size()))
					{
						char *p = codigo + it.first.size();
						printf("%-15s %-25s%10s%5d%6.2lf%7.2lf\n", codigo, it.second.first.c_str(), p, minutos, it.second.second/100., minutos*it.second.second/100.);
						goto prox;
					}
				}
			
			printf("%-15s %-35s%5d%13.2lf\n", codigo, "Unknown", minutos, -1.0);
		}
	}
    return 0;
}
