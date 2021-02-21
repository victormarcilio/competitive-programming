#include <bits/stdc++.h>

using namespace std;

int main() 
{  
    smatch m;
	char linha[1000];
	regex e("(P=.+W|I=.+A|U=.+V).+(P=.+W|I=.+A|U=.+V)");
	int n;
	scanf("%d\n", &n);
	int caso = 1;
	while(n--)
	{
		gets(linha);
		string s(linha);
		regex_search(s, m, e);
		string s1(m[1]), s2(m[2]);
		if(s2 < s1)
			swap(s2, s1);
		char c;
		double v1, v2;
		sscanf(s1.c_str(), "%*[^0-9]%lf%c", &v1, &c);
		if(c == 'm')
			v1 /= 1000.0;
		else if(c == 'k')
			v1 *= 1000;
		else if(c == 'M')
			v1 *= 1000000;
		
		sscanf(s2.c_str(), "%*[^0-9]%lf%c", &v2, &c);
		if(c == 'm')
			v2 /= 1000.0;
		else if(c == 'k')
			v2 *= 1000;
		else if(c == 'M')
			v2 *= 1000000;
		printf("Problem #%d\n", caso++);
		if(s1[0] == 'I' && s2[0] == 'U')
			printf("P=%.2lfW\n\n", v1 * v2);
		else if(s1[0] == 'I')
			printf("U=%.2lfV\n\n", v2 / v1);
		else
			printf("I=%.2lfA\n\n", v1 / v2);
		
		
	}
    return 0; 
} 
