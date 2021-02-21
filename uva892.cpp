#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	char linha[1000], texto[100000] = "";
	while (fgets(linha, sizeof linha, stdin), strcmp(linha, "#\n"))
		strcat(texto, linha);

	string s(texto);
	regex e("([[:alpha:]]+)(-\n)([^\\s]+)");
	regex e2("[^[:alpha:]\\n\\s]");
	printf("%s",regex_replace(regex_replace(s, e, "\n$1$3\n"), e2, ("")).c_str());

}