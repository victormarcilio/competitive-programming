#include <bits/stdc++.h>
using namespace std;

int main()
{
	char linha[1000];
	while(gets(linha))
	{
		string s(linha);
		regex e("[[:alpha:]]+");
		sregex_iterator it(s.cbegin(), s.cend(), e);
		sregex_iterator end;
		printf("%d\n", distance(it, end));
	}
}