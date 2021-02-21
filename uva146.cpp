#include <bits/stdc++.h>

using namespace std;

int main()
{	
	char s[100];
	while(gets(s), s[0] != '#')
		printf("%s\n", next_permutation(s, s + strlen(s)) ? s : "No Successor");
    return 0;
}
