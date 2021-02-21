#include <bits/stdc++.h>

using namespace std;
int main()
{
	int n;
	scanf("%d\n", &n);
	while(n--)
	{
		char s1[100], s2[100];
		gets(s1);
		gets(s2);
		printf("%s\n%s\n", s2, s1);
		map<char, char> m;
		for(int i = 0; s1[i]; i++)
			m[s1[i]] = s2[i];
		
		while(gets(s1), s1[0])
		{
			for(int i = 0; s1[i]; i++)
				if(m.find(s1[i]) != m.end())
					printf("%c", m[s1[i]]);
				else
					printf("%c", s1[i]);
			printf("\n");
			s1[0] = 0;
		}
		if(n)
			printf("\n");
	}
}
