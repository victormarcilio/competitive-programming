#include <bits/stdc++.h>

using namespace std;

int main()
{
	char linha[1000];
	int m[26], M[26];
	while(gets(linha))
	{
		memset(m, 0, sizeof m);
		memset(M, 0, sizeof M);
		
		for(int i = 0; linha[i]; i++)
			if(isalpha(linha[i]))
				if(isupper(linha[i]))
					M[linha[i] - 'A']++;
				else
					m[linha[i] - 'a']++;
		int maior = 0;
		for(int i = 0; i < 26; i++)
			maior = max(maior, (max(m[i], M[i])));
		for(int i = 0; i < 26; i++)
			if(M[i] == maior)
				printf("%c", 'A' + i);
		for(int i = 0; i < 26; i++)
			if(m[i] == maior)
				printf("%c", 'a' + i);
		printf(" %d\n", maior);
	}
}
