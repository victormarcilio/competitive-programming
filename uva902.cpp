#include <bits/stdc++.h>

using namespace std;
char linha[1000000];
int main()
{
	int n;
	
	while(~scanf("%d %s", &n, linha))
	{
		map<string, int> m;
		string s(linha);
		for(int i = 0; i <= s.size() - n; i++)
			m[s.substr(i, n)]++;
		int maior = 0;
		for(auto it : m)
			maior = max(maior, it.second);
		for(auto it : m)
			if(maior == it.second)
			{
				printf("%s\n", it.first.c_str());
				break;
			}
	}
}
