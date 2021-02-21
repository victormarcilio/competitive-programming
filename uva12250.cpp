#include <bits/stdc++.h>

using namespace std;

int main()
{
	char palavra[100];
	int caso = 1;
	map<string, string> m;
	m["HELLO"] = "ENGLISH";
	m["HOLA"] = "SPANISH";
	m["HALLO"] = "GERMAN";
	m["BONJOUR"] = "FRENCH";
	m["CIAO"] = "ITALIAN";
	m["ZDRAVSTVUJTE"] = "RUSSIAN";
	while(gets(palavra), strcmp(palavra, "#"))		
		printf("Case %d: %s\n", caso++, m.find(palavra) == m.end() ? "UNKNOWN" : m[palavra].c_str());

}
