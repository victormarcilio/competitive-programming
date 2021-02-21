#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, d, y;
	char haab[18][10] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", 
	"chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax","koyab", "cumhu"};
	
	char maya[20][10] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", 
	"ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
	
	char m[10];
	scanf("%d", &n);
	printf("%d\n", n);
	while(n--)
	{
		scanf("%d. %s %d", &d, m, &y);

		int dias = y * 365 + d;
		for(int i = 0; i < 18; i++)
			if(!strcmp(haab[i], m))
				break;
			else
				dias += 20;
		int year = dias/260;
		
		printf("%d %s %d\n", dias%13 + 1, maya[dias%20], year);
	}
    return 0;
}
