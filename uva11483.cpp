#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n, caso = 1, k;
	char linha[500];
	while (scanf("%d\n", &n), n)
	{
		printf("Case %d:\n#include<string.h>\n#include<stdio.h>\nint main()\n{\n", caso++);
		while (n--)
		{
			scanf("%[^\n]\n", linha);
			string s(linha);
			s = regex_replace(s, regex("\\\\"), "\\\\");
			s = regex_replace(s, regex("\""), "\\\"");
			printf("printf(\"%s\\n\");\n", s.c_str());
		}
		printf("printf(\"\\n\");\nreturn 0;\n}\n");
	}
	
}