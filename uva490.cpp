#include <bits/stdc++.h>

using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	
	char palavras[100][101];
	int k = 0, maior = 0;
	memset(palavras, 0, sizeof palavras);
	while (~scanf("%[^\n]%*c", palavras[k]))
		maior = max(maior, (int)strlen(palavras[k++]));
	for(int i = 0; i < maior; i++)
	{
		for (int j = k - 1; ~j; j--)
			printf("%c", palavras[j][i] ? palavras[j][i] : ' ');
		printf("\n");
	}
}