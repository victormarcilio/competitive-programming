#include <bits/stdc++.h>

using namespace std;

int main()
{
	char st[1000];
	while(gets(st))
	{
		char *p = strtok(st, " ");
		while(p)
		{
			string s(p);
			for(int i = s.size() - 1; ~i; i--)
				printf("%c", s[i]);
			p = strtok(NULL, " ");
			printf("%c", p ? ' ' : '\n');
		}
	}
	
    return 0;
}
