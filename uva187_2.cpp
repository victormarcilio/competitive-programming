#include <bits/stdc++.h>

using namespace std;

int main()
{
	int i = 0;
	map<int, string> m;
	int key;
	char desc[100];
	while(scanf("%d", &key), key)
	{
		gets(desc);
		m[key] = desc;
	}
	gets(desc);
	
	int antigo = -1, soma = 0, transaction, num;
	vector<int> partes, valores;
	while(scanf("%3d%3d%d", &transaction, &key, &num), transaction)
	{
		if(transaction != antigo)
		{
			if(soma)
			{
				printf("*** Transaction %d is out of balance ***\n", antigo);
				for( int i = 0; i < partes.size(); i++)
					printf("%3d %-30s %10.2lf\n", partes[i], m[partes[i]].c_str(), valores[i]/100.0);
				printf("999 %-30s %10.2lf\n\n", "Out of Balance", -soma/100.0);
			}
			antigo = transaction;
			soma = num;
			partes.clear();
			valores.clear();
			partes.push_back(key);
			valores.push_back(num);
		}
		else
		{
			soma += num;
			partes.push_back(key);
			valores.push_back(num);
		}
		
	}
	if(soma)
	{
		printf("*** Transaction %d is out of balance ***\n", antigo);
		for( int i = 0; i < partes.size(); i++)
			printf("%3d %-30s %10.2lf\n", partes[i], m[partes[i]].c_str(), valores[i]/100.0);
		printf("999 %-30s %10.2lf\n\n", "Out of Balance", -soma/100.0);
	}
}
