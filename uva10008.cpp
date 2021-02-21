#include <bits/stdc++.h>

using namespace std;

struct s
{
	char c;
	int v;
	
	bool operator<(s s2)
	{
		if(v != s2.v)
			return v > s2.v;
		return c < s2.c;
	}
};

int main()
{
	s ss[26];
	for(char i = 'A'; i <= 'Z'; i++)
	{
		ss[i - 'A'].c = i;
		ss[i - 'A'].v = 0;
	}
	int n;
	char linha[1000];
	scanf("%d\n", &n);
	
	while(n--)
	{
		gets(linha);
		for(int i = 0; linha[i]; i++)
			if(isalpha(linha[i]))
				ss[toupper(linha[i]) - 'A'].v++;
	}
	sort(ss, ss + 26);
	for(int i = 0; i < 26 && ss[i].v; i++)
		printf("%c %d\n", ss[i].c, ss[i].v);
}
