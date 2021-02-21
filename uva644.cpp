#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out2", "w", stdout);

	int k = 0, caso = 1;
	char s[500][100];
	while (~scanf("%s\n", s[k]))
	{
		if (s[k][0] == '9')
		{
			for (int i = 0; i < k; i++)
				for (int j = i + 1; j < k; j++)
					if (strstr(s[i], s[j]) == s[i] || strstr(s[j], s[i]) == s[j])
					{
						printf("Set %d is not immediately decodable\n", caso++);
						goto prox;
					}
					printf("Set %d is immediately decodable\n", caso++);
			prox: k = 0;
		}
		else
			k++;
	}

	return 0;
}