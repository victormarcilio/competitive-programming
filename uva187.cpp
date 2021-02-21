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
	
	int antigo = -1, soma = 0;
	vector<int> partes, valores;
	while(gets(desc), (strstr(desc, "000") != desc))
	{
		int transaction = (desc[0] - '0')*100 + (desc[1] - '0')*10 + desc[2] - '0';
		key = (desc[3] - '0')*100 + (desc[4] - '0')*10 + desc[5] - '0';
		
		int sinal = 1;
		int num = 0;
		for(int i = 6; desc[i]; i++)
			if(isdigit(desc[i]))
				num = num * 10 + desc[i] - '0';
			else if(desc[i] == '-')
				sinal = -1;
	
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
			soma = sinal*num;
			partes.clear();
			valores.clear();
			partes.push_back(key);
			valores.push_back(sinal*num);
		}
		else
		{
			soma += sinal*num;
			partes.push_back(key);
			valores.push_back(sinal*num);
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
