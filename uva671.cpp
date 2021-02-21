#include <bits/stdc++.h>
using namespace std;

bool analisa(string s1, string s2)
{
	int size1 = s1.size(), size2 = s2.size();
	if (abs(size1 - size2) > 1)
		return false;
	int difs = 0;
	if (size1 == size2)
	{
		for (int i = 0; i < size1; i++)
			if (s1[i] != s2[i])
				difs++;
			return difs == 1;
	}

	char c1[20], c2[20];
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
	while (n--)
	{
		set<string> words;
		vector<string> v;
		char palavra[30];
		while (scanf("%s\n", palavra), palavra[0] != '#')
		{
			v.push_back(palavra);
			words.insert(palavra);
		}

		while (scanf("%s\n", palavra), palavra[0] != '#')
		{
			if (words.find(palavra) != words.end())
				printf("%s is correct\n", palavra);
			else
			{
				printf("%s:", palavra);
				for (auto i : v)
					if (analisa(i, palavra))
						printf(" %s", i.c_str());
				printf("\n");
			}
		}
		if(n)
			printf("\n");
	}
}