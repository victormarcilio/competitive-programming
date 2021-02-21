#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);

	int t, n;
	scanf("%d", &t);
	char nome[100];
	while (t--)
	{
		scanf("%d\n", &n);
		vector<string> v(1, "");
		vector<vector<int>> votos;
		for(int i = 0; i < n; i++)
		{
			cin.getline(nome, sizeof nome);
			v.push_back(nome);
		}
		while (cin.getline(nome, sizeof nome) && nome[0])
		{
			char *p = strtok(nome, " ");
			vector<int> temp;
			while (p)
			{
				temp.push_back(atoi(p));
				p = strtok(NULL, " ");
			}
			votos.push_back(temp);
		}

		bool qualificados[1001];
		memset(qualificados, true, sizeof qualificados);
		int maior = 0, menor = 1000;
		map<string, int> m;
		while (maior != menor)
		{
			maior = 0;
			menor = 1000;
			m = map<string, int>();
			
			for (int i = 0; i < votos.size(); i++)
			{
				for(int j = 0; ; j++)
					if (qualificados[votos[i][j]])
					{
						m[v[votos[i][j]]]++;
						break;
					}
			}
			for (auto it : m)
			{
				maior = max(maior, it.second);
				menor = min(menor, it.second);
			}

			if (double(maior) / votos.size() > 0.5)
			{
				for(auto it : m)
					if (it.second == maior)
					{
						printf("%s\n", it.first.c_str());
						goto prox;
					}
			}
			for (int i = 1; i < v.size(); i++)
				if (m[v[i]] == menor)
					qualificados[i] = false;
		}
		for (int i = 1; i < v.size(); i++)
			if (m[v[i]] == maior)
				printf("%s\n", v[i].c_str());
		prox: if (t)
			printf("\n");
	}

}
