#include <bits/stdc++.h>

using namespace std;

int main()
{
	char s[1000];
	bool primeiro = true;
	while(scanf("%s", &s) != EOF)
	{
		if(!primeiro)
			printf("\n");
		primeiro = false;
		int cont = 0, leap = 0;
		int tam = strlen(s);
		int n; 
		if(tam > 4)
			n = atoi(&s[tam - 4]);
		else 
			n = atoi(s);
		int sum = 0, sum11[2] = {0, 0};
		
		for(int i = 0, pos = 0; s[i]; i++, pos = !pos)
		{
			sum += s[i] - '0';
			sum11[pos] += s[i] - '0';
		}
		if(n%4 == 0 && n%100 != 0 || n%400 == 0)
			leap = cont = printf("This is leap year.\n");
		
		if(sum%3 == 0 && (s[tam - 1] == '0' || s[tam - 1] == '5'))
			cont += printf("This is huluculu festival year.\n");
		
		if(abs(sum11[0] - sum11[1])%11 == 0 && leap && (s[tam - 1] == '0' || s[tam - 1] == '5'))
			printf("This is bulukulu festival year.\n");
		
		if(!cont)
			printf("This is an ordinary year.\n");
		
		
	}
    return 0;
}
