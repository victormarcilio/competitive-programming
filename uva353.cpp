#include <bits/stdc++.h>

using namespace std;

bool f(string s)
{

	int tam = s.size();
	for(int i = 0; i < tam/2; i++)
		if(s[i] != s[tam - i - 1])
			return false;
	return true;
}

int main()
{
	char linha[100];
	while(gets(linha))
	{
		int tam = strlen(linha);
		string st = linha;

		set<string> S;
		for(int TAM = 1 ; TAM <= tam; TAM++)
		{
			for(int k = 0; k + TAM - 1< tam; k++)
			{
				if(f(st.substr(k, TAM)))
					S.insert(st.substr(k, TAM));
			}
		}
		printf("The string '%s' contains %d palindromes.\n", linha, S.size());
	}
	
    return 0;
}
