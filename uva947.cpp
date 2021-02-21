#include <bits/stdc++.h>

using namespace std;

vector<int> check(string &correta, string &guess)
{
	int iguais = 0, dif = 0;
	map<char, int> c, g;
	for(int i = 0; i < correta.size(); i++)
		if(correta[i] == guess[i])
			iguais++;
		else
		{
			c[correta[i]]++;
			g[guess[i]]++;
		}
		
	vector<int> res;
	res.push_back(iguais);
	
	for (auto i : c)
		dif += min(i.second, g[i.first]);
	res.push_back(dif);
	
	return res;
}

int main()
{
	int n, i, x, y;
	scanf("%d\n", &n);
	char code[6];

	while(n--)
	{
		scanf("%s %d %d\n", code, &x, &y);
		vector<int> dicas;
		dicas.push_back(x); dicas.push_back(y);
		int res = 0;
		int tam = strlen(code);
		string correta = "", lim = "", guess = "", CODE(code);
		for(int i = 0; i < tam; i++)
		{
			correta += "1";
			lim += "9";
			guess += "1";
		}

		while(guess != lim)
		{
			res += dicas == check(CODE, guess);
			int k = 0;
			guess[k]++;
			while(guess[k] > '9')
			{
				guess[k] = '1';
				guess[++k]++;				
			}
			
		}
		res += dicas == check(CODE, guess);
		printf("%d\n", res);
	}
    return 0;
}
