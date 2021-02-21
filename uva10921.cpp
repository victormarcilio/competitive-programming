#include <bits/stdc++.h>

using namespace std;

int main()
{
	char v[500];
	v['A'] = v['B'] = v['C'] = '2'; 
	v['D'] = v['E'] = v['F'] = '3';  
	v['G'] = v['H'] = v['I'] = '4';  
	v['J'] = v['K'] = v['L'] = '5';  
	v['M'] = v['N'] = v['O'] = '6';
	v['P'] = v['Q'] = v['R'] = v['S'] = '7';
	v['T'] = v['U'] = v['V'] = '8';
	v['X'] = v['Y'] = v['W'] = v['Z'] = '9';
	
	char st[1000];
	while(gets(st))
	{
		for(int i = 0; st[i]; i++)
			printf("%c", isalpha(st[i]) ? v[st[i]] : st[i]);
		printf("\n");
	}
	
    return 0;
}
