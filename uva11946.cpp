#include <bits/stdc++.h>

using namespace std;
int main()
{
	char code[200];
	for(int i = 0; i < 200; i++)
		code[i] = i;
	
	code['3'] = 'E'; code['0'] = 'O'; code['1'] = 'I'; code['8'] = 'B'; code['9'] = 'P';
	code['4'] = 'A'; code['5'] = 'S'; code['2'] = 'Z'; code['6'] = 'G'; code['7'] = 'T';
	
	int n;
	char linha[1000];
	scanf("%d\n", &n);
	while(n--)
	{
		while(gets(linha), linha[0])
		{
			for(int i = 0; linha[i]; i++)
				printf("%c", code[linha[i]]);
			printf("\n");
			linha[0] = 0;
		}
		if(n)
			printf("\n");
	}
    return 0;
}
