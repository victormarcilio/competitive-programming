#include <bits/stdc++.h>
using namespace std;

int main()
{
	char linha[1000];
	while(scanf("%s", linha), linha[0] != '*')
	{
		string s(linha);
		
		//forma alternativa de declarar os sinais de + e -
		//string c1 = "[+-]?[[:digit:]]+\\.[[:digit:]]+";
		//string c2 = "[+-]?[[:digit:]]+(\\.[[:digit:]]+)?[Ee][+-]?[[:digit:]]+";
		
		string c1 = "(\\+|\\-)?[[:digit:]]+\\.[[:digit:]]+";
		string c2 = "(\\+|\\-)?[[:digit:]]+(\\.[[:digit:]]+)?[Ee](\\+|\\-)?[[:digit:]]+";
		regex e(c1 + "|" + c2);
		printf("%s is %s\n", linha, regex_match(s, e) ? "legal." : "illegal.");
	}
}