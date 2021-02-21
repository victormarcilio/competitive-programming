#include <bits/stdc++.h>

using namespace std;

int main()
{
	char s[100], digitos[15];
	int	s1[10], s2[10];
	prox: while(gets(s))
	{
		int k = 0, i = 0;
		while(s[i] == ' ') i++;
		char *p = &s[i];
		for(int i = strlen(s) - 1; i >= 0 && s[i] == ' '; i--)
			s[i] = 0;
		for(; s[i]; i++)
			if(isdigit(s[i]) || k == 9 && s[i] == 'X')
				digitos[k++] = s[i];
			else
				if(s[i] != '-')
				{
					printf("%s is incorrect.\n", p);
					goto prox;
				}
		if(k != 10)
			printf("%s is incorrect.\n", p);
		else
		{
			s1[0] = digitos[0] - '0';
			for(int i = 1; i < 9; i++)
				s1[i] = s1[i - 1] + digitos[i] - '0';
			if(digitos[9] == 'X')
				s1[9] = s1[8] + 10;
			else
				s1[9] = s1[8] + digitos[9] - '0';
			
			s2[0] = s1[0];
			for(int i = 1; i < 10; i++)
				s2[i] = s2[i - 1] + s1[i];
			printf("%s is %scorrect.\n", p, s2[9]% 11 ? "in" : "");

		}
	}
}
