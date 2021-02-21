#include <bits/stdc++.h>
using namespace std;
/*Zerar todos os 1000 registradores antes de ler as instruções!*/

int main() {
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);

	int t;
	char linha[5];
	scanf("%d\n", &t);
	vector<int> halt{ 1, 0, 0 };
	while (t--)
	{
		vector<vector<int>> inst(1000, vector<int>(3, 0));
		int i = 0;
		while (fgets(linha, sizeof linha, stdin), linha[0] != '\n' && !feof(stdin))
			inst[i++] = { linha[0] - '0', linha[1] - '0', linha[2] - '0' };
		int cont = 1;
		int pos = 0;
		vector<int> registers(10, 0);
		while (inst[pos] != halt)
		{
			cont++;
			int ins = inst[pos][0], a = inst[pos][1], b = inst[pos][2];
				if (!ins)
			{
				if (registers[b])
				{
					pos = registers[a];
					continue;
				}
			}
			else if (ins == 2)
				registers[a] = b;
			else if (ins == 3)
				registers[a] = (registers[a] + b) % 1000;
			else if (ins == 4)
				registers[a] = (registers[a] * b) % 1000;
			else if (ins == 5)
				registers[a] = registers[b];
			else if (ins == 6)
				registers[a] = (registers[a] + registers[b]) % 1000;
			else if (ins == 7)
				registers[a] = (registers[a] * registers[b]) % 1000;
			else if (ins == 8)
				registers[a] = inst[registers[b]][0] * 100 + inst[registers[b]][1] * 10 + inst[registers[b]][2];
			else if (ins == 9)
					inst[registers[b]] = { registers[a]/100, registers[a] % 100 / 10, registers[a] % 10 };
			pos++;
		}

		printf("%d\n", cont);
		if (t)
			printf("\n");
	}

}
