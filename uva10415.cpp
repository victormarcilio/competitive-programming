#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	char musica[300];
	scanf("%d%*c", &n);
	map<char, string> m;
	m['c'] = "0234789";
	m['d'] = "234789";
	m['e'] = "23478";
	m['f'] = "2347";
	m['g'] = "234";
	m['a'] = "23";
	m['b'] = "2";
	m['C'] = "3";
	m['D'] = "1234789";
	m['E'] = "123478";
	m['F'] = "12347";
	m['G'] = "1234";
	m['A'] = "123";
	m['B'] = "12";
	
	int v[400];
	
	while(n--)
	{
		memset(v, 0, sizeof v);
		gets(musica);
		if(musica[0])
		{
			for(auto it : m[musica[0]])
				v[it - '0']++;
			for(int i = 1; musica[i]; i++)
				for(auto it : m[musica[i]])
					if(!strchr(m[musica[i - 1]].c_str(), it))
						v[it - '0']++;
		}
		for(int i = 1; i < 10 ; i++)
			printf("%d ", v[i]);
		printf("%d\n", v[0]);
	}
    return 0;
}
