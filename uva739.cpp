#include <bits/stdc++.h>

using namespace std;
int v[100];
int main()
{
	char code[30];
	v['B'] = v['P'] = v['F'] = v['V'] = 1;
	v['C'] = v['S'] = v['K'] = v['G'] = v['J'] = v['Q'] = v['X'] = v['Z'] = 2;
	v['D'] = v['T'] = 3; 
	v['M'] = v['N'] = 5;
	v['L'] = 4;
	v['R'] = 6;
	
	printf("%9s%-25s%s\n", "", "NAME", "SOUNDEX CODE");
	while(gets(code))
	{
		char enc[] = "0000";
		enc[0] = code[0];
		for(int i = 1, k = 1; code[i] && k < 4; i++)
			if(v[code[i]] && v[code[i]] != v[code[i - 1]])
				enc[k++] = v[code[i]] + '0';
		printf("%9s%-25s%s\n", "", code, enc);
	}
	printf("%19sEND OF OUTPUT\n", "");
    return 0;
}
