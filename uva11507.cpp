#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	char linha[400000];
	string nova = "aa";
	map<pair<string, string>, string> m;
	
	m[make_pair("+x", "+y")] = "+y";
	m[make_pair("+x", "-y")] = "-y";
	m[make_pair("+x", "+z")] = "+z";
	m[make_pair("+x", "-z")] = "-z";
	
	m[make_pair("-x", "+y")] = "-y";
	m[make_pair("-x", "-y")] = "+y";
	m[make_pair("-x", "+z")] = "-z";
	m[make_pair("-x", "-z")] = "+z";
	
	m[make_pair("+y", "+y")] = "-x";
	m[make_pair("+y", "-y")] = "+x";
	m[make_pair("+y", "+z")] = "+y";
	m[make_pair("+y", "-z")] = "+y";
	
	m[make_pair("-y", "+y")] = "+x";
	m[make_pair("-y", "-y")] = "-x";
	m[make_pair("-y", "+z")] = "-y";
	m[make_pair("-y", "-z")] = "-y";
	
	m[make_pair("+z", "+y")] = "+z";
	m[make_pair("+z", "-y")] = "+z";
	m[make_pair("+z", "+z")] = "-x";
	m[make_pair("+z", "-z")] = "+x";
	
	m[make_pair("-z", "+y")] = "-z";
	m[make_pair("-z", "-y")] = "-z";
	m[make_pair("-z", "+z")] = "+x";
	m[make_pair("-z", "-z")] = "-x";
	
	while(scanf("%d\n", &n), n)
	{
		
		string pos = "+x";
		gets(linha);
		if(linha[0] != 'N')
		{
			nova[0] = linha[0];
			nova[1] = linha[1];
			pos = m[make_pair(pos, nova)];
		}
		for(int i = 2; linha[i]; i += 3)
		{
			if(linha[i + 1] != 'N')
			{
				if((pos[1] == 'y' || pos[1] == 'z') && pos[1] != linha[i + 2])
					continue;
				nova[0] = linha[i + 1];
				nova[1] = linha[i + 2];
				pos = m[make_pair(pos, nova)];
			}
		}
		
		printf("%s\n", pos.c_str());
	}
	
}
