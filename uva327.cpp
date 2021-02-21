#include <bits/stdc++.h>

using namespace std;

int main() 
{  
	char linha[200], trimed[200];
    while(gets(linha))
	{
		map<char, int> m;
		printf("Expression: %s\n", linha);
		int k = 0;
		for(int i = 0; linha[i]; i++)
			if(!isspace(linha[i]))
				trimed[k++] = linha[i];
		trimed[k] = 0;
		vector<int> v;
		int sinal = 1;
		for(int i = 0; trimed[i]; i++)
			if(trimed[i] == '-' && trimed[i + 1] == '-')
			{
				m[trimed[i + 2]] = trimed[i + 2] - 'a';
				v.push_back(sinal*m[trimed[i + 2]]);
				i += 2;
			}
			else if(trimed[i] == '+' && trimed[i + 1] == '+')
			{
				m[trimed[i + 2]] = trimed[i + 2] - 'a' + 2;
				v.push_back(sinal*m[trimed[i + 2]]);
				i += 2;
			}
			else if(trimed[i] == '+')
				sinal = 1;
			else if(trimed[i] == '-')
				sinal = -1;
			else if(trimed[i + 1] == '-' && trimed[i + 2] == '-')
			{
				v.push_back(sinal*(trimed[i] - 'a' + 1));
				m[trimed[i]] = trimed[i] - 'a';
				i += 2;
			}
			else if(trimed[i + 1] == '+' && trimed[i + 2] == '+')
			{
				v.push_back(sinal*(trimed[i] - 'a' + 1));
				m[trimed[i]] = trimed[i] - 'a' + 2;
				i += 2;
			}
			else
			{
				m[trimed[i]] = trimed[i] - 'a' + 1;
				v.push_back(sinal*m[trimed[i]]);
			}
			int res = 0;
			for(int i : v)
				res += i;
		printf("    value = %d\n", res);
		for(auto it : m)
			printf("    %c = %d\n", it.first, it.second);
		
	}
    return 0; 
} 
