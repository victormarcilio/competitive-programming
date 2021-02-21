#include <bits/stdc++.h>

using namespace std;

int main()
{
	string strings[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
	int pulos[] = {2, 2, 1, 2, 2, 2, 1};
	set<string> sets[13];
	for(int i = 0; i < 12; i++)
	{
		int pos = i;
		for(int k = 0; k < 7; k++)
		{
			sets[i].insert(strings[pos]);
			pos = (pos + pulos[k])%12;
		}
	}
	
//	for(int i = 0; i < 12; i++)
//	{
//		printf("Escala do %s: ", strings[i].c_str());
//		for(auto x : sets[i])
//			printf("%s ", x.c_str());
//		printf("\n");
//	}
	
	char linha[10100];
	int possivel[20];
	
	while(gets(linha), strcmp(linha, "END"))
	{
		memset(possivel, 1, sizeof possivel);
		
		char *p = strtok(linha, " ");
		while(p)
		{
			for(int i = 0; i < 12; i++)
				if(sets[i].find(p) == sets[i].end())
					possivel[i] = false;
			p = strtok(NULL, " ");
		}
		int i = 0;
		for(; i < 12; i++)
			if(possivel[i])
			{
				printf("%s", strings[i].c_str());
				break;
			}
		for(i++; i < 12; i++)
			if(possivel[i])
				printf(" %s", strings[i].c_str());
			
		printf("\n");
	}
}
