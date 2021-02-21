#include <bits/stdc++.h>
using namespace std;

bool analisa(string s1, string s2)
{
	int size1 = s1.size(), size2 = s2.size();
	if (abs(size1 - size2) > 1)
		return false;
	if (size1 == size2) 
	{
		int difs = 0;
		for (int i = 0; i < size1; i++)
			if (s1[i] != s2[i])
				difs++;
		if (difs == 1)
			return true;

		for (int i = 0; i < size1; i++)
			if (s1[i] != s2[i])
			{
				swap(s1[i], s1[i + 1]);
				return s1 == s2;
			}
	}

	char c1[30], c2[30];
	if (size1 < size2)
		swap(s1, s2);
	strcpy(c1, s1.c_str());
	strcpy(c2, s2.c_str());
	for(int i = 0; c1[i]; i++)
		if (c1[i] != c2[i])
		{
			while (c1[i])
			{
				c1[i] = c1[i + 1];
				i++;
			}
			return !strcmp(c1, c2);
		}
	return false;
}

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n;
	scanf("%d\n", &n);
	vector<string> v;
	set<string> s;
	char palavra[30];
	while (n--)
	{
		scanf("%s%*c", palavra);
		v.push_back(palavra);
		s.insert(palavra);
	}
	scanf("%d\n", &n);
	prox: while (n--)
	{
		scanf("%s\n", palavra);
		if (s.find(palavra) != s.end())
			printf("%s is correct\n", palavra);
		else
		{
			for (auto i : v)
				if (analisa(palavra, i))
				{
					printf("%s is a misspelling of %s\n", palavra, i.c_str());
					goto prox;
				}
			printf("%s is unknown\n", palavra);
		}
	}
	
}