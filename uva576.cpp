#include <bits/stdc++.h>
using namespace std;

int main()
{
	char linha[1000];
	while(scanf("%[^\n]\n", linha), strcmp(linha, "e/o/i"))
	{
		char s[3][100];
		sscanf(linha, "%[^/]/%[^/]/%[^\n]", s[0], s[1], s[2]);
		
		regex e("[aeiouy]+");
		string S1(s[0]);
		string S2(s[1]);
		string S3(s[2]);
		sregex_iterator it1(S1.cbegin(), S1.cend(), e);
		sregex_iterator it2(S2.cbegin(), S2.cend(), e);
		sregex_iterator it3(S3.cbegin(), S3.cend(), e);
		sregex_iterator end;
				
		int d1 = distance(it1, end);
		int d2 = distance(it2, end);
		int d3 = distance(it3, end);
		
		if(d1 == 5 && d2 == 7 && d3 == 5)
			printf("Y\n");
		else if(d1 - 5)
			printf("1\n");
		else if(d2 - 7)
			printf("2\n");
		else
			printf("3\n");
	}
}