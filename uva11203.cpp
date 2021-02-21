#include <bits/stdc++.h>

using namespace std;
int main()
{
	char linha[100];
	int t;
	scanf("%d\n", &t);
	while(t--)
	{
		gets(linha);
		if(regex_match (linha, regex("(\\?+)M(\\?+)E\\1\\2")))
			printf("theorem\n");
		else
			printf("no-theorem\n");
	}
	return 0;
}
