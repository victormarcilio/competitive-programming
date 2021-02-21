#include <bits/stdc++.h>

using namespace std;

bool taken[2000];
char palavras[2000][30];
char frase[200000], aux[200000];
int counter[26], qtdPalavras = 0;
set<string> dic;
void search(int ind)
{
	if (ind == qtdPalavras)
		return;
	bool vai = true;
	for(int i = 0; palavras[ind][i]; i++)
	{
		counter[palavras[ind][i] - 'A']--;
		if(counter[palavras[ind][i] - 'A'] < 0)
			vai = false;
	}
	bool pronto = true;
	for(int i = 0; i < 26; i++)
		if(counter[i])
			pronto = false;
	if(pronto)
	{
		printf("%s = ", frase);
		for(int i = 0; i < ind; i++)
			if(taken[i])
				printf("%s ", palavras[i]);
		printf("%s\n", palavras[ind]);
	}
	if(vai)
	{
		taken[ind] = true;
		search(ind + 1);
		taken[ind] = false;
	}
	for(int i = 0; palavras[ind][i]; i++)
		counter[palavras[ind][i] - 'A']++;
	search(ind + 1);
}
int main()
{
	while(gets(palavras[qtdPalavras]), palavras[qtdPalavras][0] != '#')
	{
		dic.insert(palavras[qtdPalavras]);
		qtdPalavras++;
	}
	while(gets(frase), frase[0] != '#')
	{
		memset(counter, 0, sizeof counter);
		strcpy(aux, frase);
		bool vai = false;
		char *p = strtok(aux, " ");
		while(p)
		{
			if(dic.find(p) == dic.end())
			{
				vai = true;
				break;
			}
			p = strtok(NULL, " ");
		}
		if(vai)
		{
			for(int i = 0; frase[i]; i++)
				if(isalpha(frase[i]))
					counter[frase[i] - 'A']++;
			search(0);
		}
	}
    return 0;
}
