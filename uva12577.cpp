#include <bits/stdc++.h>

using namespace std;

int main()
{
	char palavra[100];
	int caso = 1;
	while(gets(palavra), strcmp(palavra, "*"))		
		printf("Case %d: Hajj-e-A%sar\n", caso++, palavra[0] == 'H' ? "kb" : "sgh");

}
