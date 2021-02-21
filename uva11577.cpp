#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	char linha[2000];
	scanf("%d\n", &n);
	while(n--)
	{
		gets(linha);
		map<char, int> m;
		for(int i = 0; linha[i]; i++)
			if(isalpha(linha[i]))
				m[tolower(linha[i])]++;
		int maior = 0;
		for( auto it : m)
			maior = max(maior, it.second);
		
		for( auto it : m)
			if(maior == it.second)
				printf("%c", it.first);
		printf("\n");
	}
}
