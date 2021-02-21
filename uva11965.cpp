#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	
	int n, l, caso = 1;
	char linha[1000];
	cin >> n;
	while (n--)
	{
		cin >> l;
		cin.ignore();
		printf("Case %d:\n", caso++);
		while (l--)
		{
			int k = 0;
			cin.getline(linha, sizeof linha);
			for (int i = 0; linha[i]; i++)
			{
				linha[k++] = linha[i];
				if(linha[i] == ' ')
					while (linha[i + 1] == ' ')
						i++;
			}
			linha[k] = 0;
			printf("%s\n", linha);
		}
		if (n)
			printf("\n");
	}
}