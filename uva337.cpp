
#include <bits/stdc++.h>
using namespace std;

//bom exemplo pra mostrar possivel bug em ifs aninhados: teste do limite de tela junto com o do comando.

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n, caso = 1;
	char blank[11] = "          ";
	char linha[500];
	while (scanf("%d\n", &n), n)
	{
		int x = 0, y = 0;
		char grid[10][11];
		for (int i = 0; i < 10; i++)
			strcpy(grid[i], blank);
		bool over = true;
		while (n--)
		{
			cin.getline(linha, sizeof linha);
			for(int i = 0; linha[i]; i++)
				if (linha[i] == '^')
				{
					i++;
					char c = linha[i];
					if (c == 'b')
						y = 0;
					else if (c == 'c')
						for (int i = 0; i < 10; i++)
							strcpy(grid[i], blank);
					else if (c == 'd' && x < 9)
						x++;
					else if (c == 'e')
						for (int i = y; i < 10; i++)
							grid[x][i] = ' ';
					else if (c == 'h')
						x = y = 0;
					else if (c == 'i')
						over = false;
					else if (c == 'l')
					{
						if(y)
							y--;
					}
					else if (c == 'o')
						over = true;
					else if (c == 'r')
					{
						//se jogar esse if junto do de cima ele vai seguir testando abaixo
						if(y < 9)
							y++;
					}
					else if (c == 'u')
					{
						if(x)
							x--;
					}
					else if (c == '^')
					{
						if (over)
							grid[x][y] = '^';
						else
						{
							for (int i = 9; i > y; i--)
								grid[x][i] = grid[x][i - 1];
							grid[x][y] = '^';
						}
						if (y < 9)
							y++;
					}
					else
					{
						x = c - '0';
						y = linha[++i] - '0';
					}

				}
				else
				{
					if (over)
						grid[x][y] = linha[i];
					else
					{
						for (int i = 9; i > y; i--)
							grid[x][i] = grid[x][i - 1];
						grid[x][y] = linha[i];
					}
					if (y < 9)
						y++;
				}
		}
		printf("Case %d\n+----------+\n", caso++);
		for (int i = 0; i < 10; i++)
			printf("|%s|\n", grid[i]);
		printf("+----------+\n");
	}
}

