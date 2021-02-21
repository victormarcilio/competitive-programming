#include <bits/stdc++.h>

using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	
	char palavra[101000];

	while (cin.getline(palavra, sizeof palavra))
	{
		if (!palavra[0])
		{
			printf("\n");
			continue;
		}
		int k = 0;
		for (int i = 0; palavra[i]; i++)
			if (palavra[i] == '!')
				printf("\n");
			else if (isdigit(palavra[i]))
				k += palavra[i] - '0';
			else
			{
				if (palavra[i] == 'b')
					while (k--)
						printf(" ");
				else
					while (k--)
						printf("%c", palavra[i]);
				k = 0;
			}
		printf("\n");
	}
}