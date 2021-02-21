#include <bits/stdc++.h>

using namespace std;

bool match(string s, string s2)
{
	return s[0] == s2[0] || s[1] == s2[1];
}

void imprime(vector<vector<string>> &v)
{
	for(int i = 0; i < 52; i++)
		if(v[i].size())
		{
			printf("p%d: ", i +1);
			for(int j = 0; j < v[i].size(); j++)
				printf("%s ", v[i][j].c_str());
			printf("\n");
		}
}

bool update(vector<vector<string>> &v, int pos)
{
	if(v[pos].empty())
		return false;
	if(pos > 2 && match(v[pos].back(), v[pos - 3].back()))
	{
		v[pos - 3].push_back(v[pos].back());
		v[pos].pop_back();
		if(v[pos].empty())
		{
			pos++;
			while(pos < 52 && v[pos].size())
			{
				v[pos - 1] = v[pos];
				pos++;				
			}
			v[pos - 1].clear();
		}
	//	imprime(v);
		return true;
	}
	else if(pos && match(v[pos].back(), v[pos - 1].back()))
	{
		v[pos - 1].push_back(v[pos].back());
		v[pos].pop_back();
		if(v[pos].empty())
		{
			pos++;
			while(pos < 52 && v[pos].size())
			{
				v[pos - 1] = v[pos];
				pos++;
			}
			v[pos - 1].clear();
		}
		return true;
	}
	return false;
}

int main()
{	
	char linha[100000];
	
	while(gets(linha), linha[0] != '#')
	{
		vector <vector<string>> v(52);
		char *p = strtok(linha, " ");		
		while(p)
		{
			int i;
			for(i = 0; v[i].size(); i++);
			v[i].push_back(p);
			update(v, i);
			bool fazer = true;
			while(fazer)
			{
				fazer = false;
				for(int j = 0; j < i; j++)
					fazer = fazer || update(v, j);
				
			}
			p = strtok(NULL, " ");
		}
		
		gets(linha);
		
		p = strtok(linha, " ");		
		
		while(p)
		{
			int i;
			for(i = 0; v[i].size(); i++);
			v[i].push_back(p);
			update(v, i);
			
			bool fazer = true;
			while(fazer)
			{
				fazer = false;
				for(int j = 0; j < i; j++)
					fazer = fazer || update(v, j);
				
			}
			
			p = strtok(NULL, " ");
		}
		if(v[0].size() == 52)
			printf("1 pile remaining: 52\n");
		else
		{
			int k = 0;
			for(int i = 0; v[i].size(); i++)
				k++;
			printf("%d piles remaining: %d", k, v[0].size());
			for(int i = 1; v[i].size(); i++)
				printf(" %d", v[i].size());
			printf("\n");
		}
	}
    return 0;
}
