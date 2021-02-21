#include <bits/stdc++.h>
using namespace std;

int main()
{
	char linha[1000];
	
	string noun = "(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)";
	string verb = "(hate|love|know|like)s*";
	string article = "(a|the)";
	string actor = "((a|the)\\s)*" + noun;
	string actlist = actor + "(\\sand\\s" + actor + ")*";
	string action = actlist + "\\s" + verb + "\\s" + actlist;
	string statement = action + "(\\s,\\s" + action + ")*";
	
	while(gets(linha))
	{
		string s(linha);
		printf("%s\n", regex_match(s, regex(statement)) ? "YES I WILL" : "NO I WON'T");
	}
}