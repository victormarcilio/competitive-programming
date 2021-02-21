#include <bits/stdc++.h>

using namespace std;

int main()
{
	map<char, char> v;
	v['='] = '-'; v['-'] = '0'; v['0'] = '9'; v['9'] = '8'; v['8'] = '7'; v['7'] = '6'; v['6'] = '5'; v['5'] = '4'; v['4'] = '3'; v['3'] = '2'; v['2'] = '1'; v['1'] = '`';
	v['\\'] = ']'; v[']'] = '['; v['['] = 'P'; v['P'] = 'O'; v['O'] = 'I'; v['I'] = 'U'; v['U'] = 'Y'; v['Y'] = 'T'; v['T'] = 'R'; v['R'] = 'E'; v['E'] = 'W'; v['W'] = 'Q'; 
	v['\''] = ';'; v[';'] = 'L'; v['L'] = 'K'; v['K'] = 'J'; v['J'] = 'H'; v['H'] = 'G'; v['G'] = 'F'; v['F'] = 'D'; v['D'] = 'S'; v['S'] = 'A'; 
	v['/'] = '.'; v['.'] = ','; v[','] = 'M'; v['M'] = 'N'; v['N'] = 'B'; v['B'] = 'V'; v['V'] = 'C'; v['C'] = 'X'; v['X'] = 'Z';
	char s[100000];
	while(gets(s))
	{
		for(int i = 0; s[i]; i++)
			if(v.find(s[i]) != v.end())
				printf("%c", v[s[i]]);
			else
				printf("%c", s[i]);
		printf("\n");
	}
}
