#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);

	int n, m, k = 1;
	//tem teste com linha em branco... ler com \n no final vai falhar
	while (scanf("%d%*c", &n), n)
	{
		string s2, s1;
		char linha[500];
		for (int i = 0; i < n; i++)
		{
			cin.getline(linha, sizeof linha);
			s1 += linha;
		}
		scanf("%d%*c", &m);
		for(int i = 0; i < m; i++)
		{
			cin.getline(linha, sizeof linha);
			s2 += linha;
		}
		if (n == m && s1 == s2)
			printf("Run #%d: Accepted\n", k++);
		else
		{
			string n1, n2;
			for (int i = 0; i < s1.size(); i++)
				if (isdigit(s1[i]))
					n1 += s1[i];
			for (int i = 0; i < s2.size(); i++)
				if (isdigit(s2[i]))
					n2 += s2[i];

			printf("Run #%d: %s\n", k++, n1 == n2 ? "Presentation Error" : "Wrong Answer");
		}
	}
}
