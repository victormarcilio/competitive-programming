#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d\n", &n);
	char linha[1000];
	map<string, int> m;
	while(n--)
	{
		gets(linha);
		char *p = strtok(linha, " ");
		m[p]++;
	}
	for(auto it : m)
		printf("%s %d\n", it.first.c_str(), it.second);
}
