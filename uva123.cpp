#include <bits/stdc++.h>

using namespace std;

struct STR
{
	string completa;
	string comp;
	int k;
	bool operator <( STR s2)
	{
		if(s2.comp != comp)
			return comp < s2.comp;
		return k < s2.k;
	}
	
	STR(vector<string> &s1, string s2, int c)
	{
		completa = s1[0];
		for(int i = 1; i < s1.size(); i++)
			completa = completa + " " + s1[i];
		comp = s2;
		k = c;
	}
};

int main()
{	
	int cont = 0;
	char linha[1000];
	vector<STR> STRS;
	set<string> condenadas;
	while(gets(linha), linha[0] != ':')
		condenadas.insert(linha);
	
	while(gets(linha))
	{
		for(int j = 0; linha[j]; j++)
			linha[j] = tolower(linha[j]);
		
		char *p = strtok(linha, " ");
		vector<string> palavras;
		while(p)
		{
			palavras.push_back(p);
			p = strtok(NULL, " ");
		}
		
		for(int i = 0; i < palavras.size(); i++)
			if(condenadas.find(palavras[i]) == condenadas.end())
			{
				for(int j = 0; j < palavras[i].size(); j++)
					palavras[i][j] = toupper(palavras[i][j]);
				STRS.push_back(STR(palavras, palavras[i], cont++));
				for(int j = 0; j < palavras[i].size(); j++)
					palavras[i][j] = tolower(palavras[i][j]);
			}
	}
	sort(STRS.begin(), STRS.end());

	for(int i = 0; i < STRS.size(); i++)
		printf("%s\n", STRS[i].completa.c_str());

    return 0;
}
