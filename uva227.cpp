#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int cont = 1, x, y;
	char pz[5][6], line[100];
	while (scanf("%[^\n]%*c", pz[0]), pz[0][0] != 'Z')
	{
		if (cont > 1)
			printf("\n");
		char moves[10000] = "";
		printf("Puzzle #%d:\n", cont++);
		for (int i = 1; i < 5; i++)
			scanf("%[^\n]%*c", pz[i]);
		do
		{
			scanf("%[^\n]%*c", line);
			strcat(moves, line);
		} while (line[strlen(line) - 1] != '0');

		for(int i = 0; i < 5; i++)
			for(int j = 0; j < 5; j++)
				if (pz[i][j] == ' ')
				{
					x = i;
					y = j;
				}
		int i;
		for (i = 0; moves[i + 1]; i++)
		{
			if (moves[i] == 'A')
			{
				if (x == 0)
				{
					printf("This puzzle has no final configuration.\n");
					break;
				}
				swap(pz[x][y], pz[x - 1][y]);
				x--;
			}
			else if (moves[i] == 'B')
			{
				if (x == 4)
				{
					printf("This puzzle has no final configuration.\n");
					break;
				}
				swap(pz[x][y], pz[x + 1][y]);
				x++;
			}
			else if (moves[i] == 'L')
			{
				if (y == 0)
				{
					printf("This puzzle has no final configuration.\n");
					break;
				}
				swap(pz[x][y], pz[x][y - 1]);
				y--;
			}
			else
			{
				if (y == 4)
				{
					printf("This puzzle has no final configuration.\n");
					break;
				}
				swap(pz[x][y], pz[x][y + 1]);
				y++;
			}
		}
		if (moves[i] == '0')
		{
			for (int j = 0; j < 5; j++)
			{
				printf("%c", pz[j][0]);
				for (int k = 1; k < 5; k++)
					printf(" %c", pz[j][k]);
				printf("\n");
			}
		}
	}
}