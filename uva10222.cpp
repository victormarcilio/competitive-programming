#include <bits/stdc++.h>

using namespace std;

int main()
{
	char v[500];
	v[']'] = 'p'; v['t'] = 'e'; v['j'] = 'g'; v['m'] = 'b'; 
	v['['] = 'o'; v['r'] = 'w'; v['h'] = 'f'; v['n'] = 'v'; 
	v['p'] = 'i'; v['e'] = 'q'; v['g'] = 'd'; v['b'] = 'c'; 
	v['o'] = 'u'; v['\''] = 'l'; v['f'] = 's'; v['v'] = 'x';
	v['i'] = 'y'; v[';'] = 'k'; v['d'] = 'a'; v['c'] = 'z'; 
	v['u'] = 't'; v['l'] = 'j'; v['.'] = 'm'; v[' '] = ' ';
	v['y'] = 'r'; v['k'] = 'h'; v[','] = 'n'; 
	for(char i = 'A'; i <= 'Z'; i++)
		v[i] = v[tolower(i)];
	char st[1000];
	while(gets(st))
	{
		for(int i = 0; st[i]; i++)
			printf("%c", v[st[i]]);
		printf("\n");
	}
	
    return 0;
}
