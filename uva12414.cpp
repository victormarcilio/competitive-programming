#include <bits/stdc++.h>
#include <regex>
using namespace std;
bool check(char *linha, int k)
{
	string s;
	char temp[10];
	for (int i = 0; linha[i]; i++)
	{
		sprintf(temp, "%d", linha[i] - 'A' + k);
		s += temp;
	}
	while (s.size() > 3)
	{
		for (int i = 0; i < s.size() - 1; i++)
			s[i] = ((s[i] - '0' + s[i + 1] - '0') % 10) + '0';
		s.pop_back();
	}

	return s == "100";
}
int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	
	char nomes[20];
	prox: while (~scanf("%s\n", nomes))
	{
		for(int i = 1; i < 10001; i++)
			if (check(nomes, i))
			{
				printf("%d\n", i);
				goto prox;
			}
		printf(":(\n");
	}
}