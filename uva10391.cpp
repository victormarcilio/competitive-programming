#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	char palavra[100];
	set<string> s;
	while (~scanf("%s\n", palavra))
		s.insert(palavra);

	for (auto st : s)
		for(int i = 1; i < st.size() - 1; i++)
			if (s.find(st.substr(0, i)) != s.end() && s.find(st.substr(i)) != s.end())
			{
				printf("%s\n", st.c_str());
				break;
			}
}