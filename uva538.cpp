#include<bits/stdc++.h>
using namespace std;
/*
	checar V[i]*V[j] < 0 dá overflow! A linha 36 pode ser trocada pela mostrada abaixo
	if((long long)(V[i] * V[j] < 0)
*/

int main() {
    int caso = 1, n, t, v;
	char nome[10000], nome2[10000];
	while(scanf("%d %d%\n", &n, &t), t || n)
	{
		map<string, int> m;
		map<int, string> r;
		vector<int> V;
		for(int i = 0; i < n; i++)
		{
			scanf("%s", nome);
			m[nome] = i;
			r[i] = nome;
			V.push_back(0);
		}
		while(t--)
		{
			scanf("%s %s %d%\n", nome, nome2, &v);
			if(m.find(nome) != m.end() && m.find(nome2) != m.end())
			{
				V[m[nome]] += v;
				V[m[nome2]] -= v;
			}
		}
		printf("Case #%d\n", caso++);
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(V[i] > 0 && V[j] < 0 || V[i] < 0 && V[j] > 0) 
				{
					int valor = min(abs(V[i]), abs(V[j]));
					if(V[i] > 0)
					{
						V[i] -= valor;
						V[j] += valor;
						printf("%s %s %d\n", r[j].c_str(), r[i].c_str(), valor);
					}
					else
					{
						V[j] -= valor;
						V[i] += valor;
						printf("%s %s %d\n", r[i].c_str(), r[j].c_str(), valor);
					}
				}
		
		printf("\n");
	}
    return 0;
}
