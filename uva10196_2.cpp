/*
	Para reduzir o tamanho do código anterior adicionei uma segunda dimensão na matriz
	e faço 2 checagens. Na segunda é invertido o tabuleiro (por causa da direção dos peões)
	e alternado o case das letras.
 */

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int pos1[] = {1, -1};
	int pos2[] = {2, -2};
	vector<int> v1(pos1, pos1 + 2), v2(pos2, pos2 + 2);
	char board[2][8][9], c, cor[][6] = {"white", "black"};
	int flag, game = 1;
	while(1)
	{
		flag = 0;
		for(int i = 0; i < 8; i++)
			gets(board[0][i]);
		for(int i = 0; i < 8; i++)
			for(int j = 0; j < 8; j++)
				flag += board[0][i][j] != '.';
		if(!flag)
			break;
		for(int i = 0; i < 8; i++)
		{
			strcpy(board[1][i], board[0][7 - i]);
			for(int j = 0; j < 8; j++)
				if(islower(board[1][i][j]))
					board[1][i][j] = toupper(board[1][i][j]);
				else if(isupper(board[1][i][j]))
					board[1][i][j] = tolower(board[1][i][j]);
		}
		for(int k = 0; k < 2; k++)
			for(int i = 0; i < 8; i++)
				for(int j = 0; j < 8; j++)
				{
					c = board[k][i][j];
					if(c == 'p')
					{					
						if(j > 0 && i < 7 && board[k][i + 1][j - 1] == 'K' || j < 7 && i < 7 && board[k][i + 1][j + 1] == 'K')
						{
							printf("Game #%d: %s king is in check.\n", game++, cor[k]);
							goto prox;
						}
					}
					else if(c == 'n')
					{
						for(auto u : v1)
							for(auto v : v2)
							{
								int x = i + u, y = j + v;
								if(x >= 0 && x <= 7 && y >= 0 && y <= 7 && board[k][x][y] == 'K')
								{
									printf("Game #%d: %s king is in check.\n", game++, cor[k]);
									goto prox;
								}
								
								x = i + v, y = j + u;
								if(x >= 0 && x <= 7 && y >= 0 && y <= 7 && board[k][x][y] == 'K')
								{
									printf("Game #%d: %s king is in check.\n", game++, cor[k]);
									goto prox;
								}
							}
					}
					else if(c == 'r')
					{					
						for(flag = i + 1; flag < 8 && board[k][flag][j] == '.'; flag++);
						if(flag < 8 && board[k][flag][j] == 'K')
						{
							printf("Game #%d: %s king is in check.\n", game++, cor[k]);
							goto prox;
						}
						for(flag = i - 1; flag >= 0 && board[k][flag][j] == '.'; flag--);
						if(flag >= 0 && board[k][flag][j] == 'K')
						{
							printf("Game #%d: %s king is in check.\n", game++, cor[k]);
							goto prox;
						}
						for(flag = j + 1; flag < 8 && board[k][i][flag] == '.'; flag++);
						if(flag < 8 && board[k][i][flag] == 'K')
						{
							printf("Game #%d: %s king is in check.\n", game++, cor[k]);
							goto prox;
						}
						for(flag = j - 1; flag >= 0 && board[k][i][flag] == '.'; flag--);
						if(flag >= 0 && board[k][i][flag] == 'K')
						{
							printf("Game #%d: %s king is in check.\n", game++, cor[k]);
							goto prox;
						}
					}
					else if(c == 'b' || c == 'q')
					{					
						for(flag = 1; flag + i < 8 && flag + j < 8 && board[k][flag + i][flag + j] == '.'; flag++);
							if(flag + i < 8 && flag + j < 8 && board[k][flag + i][flag + j] == 'K')
							{
								printf("Game #%d: %s king is in check.\n", game++, cor[k]);
								goto prox;
							}
						for(flag = -1; flag + i >= 0 && flag + j >= 0 && board[k][flag + i][flag + j] == '.'; flag--);
							if(flag + i >= 0 && flag + j >= 0 && board[k][flag + i][flag + j] == 'K')
							{
								printf("Game #%d: %s king is in check.\n", game++, cor[k]);
								goto prox;
							}
						for(flag = 1; flag + i < 8 && j - flag >= 0 && board[k][flag + i][j - flag] == '.'; flag++);
							if(flag + i < 8 && j - flag >= 0 && board[k][flag + i][j - flag] == 'K')
							{
								printf("Game #%d: %s king is in check.\n", game++, cor[k]);
								goto prox;
							}
						for(flag = 1; i - flag >= 0 && flag + j < 8 && board[k][i - flag][flag + j] == '.'; flag++);
							if(i - flag >= 0 && flag + j < 8 && board[k][i - flag][flag + j] == 'K')
							{
								printf("Game #%d: %s king is in check.\n", game++, cor[k]);
								goto prox;
							}
					}
					// gambiarrinha pra não ter que repetir o codigo de torre e bispo pra rainha
					if(c == 'q')
						board[k][i][j--] = 'r';					
				}
		
		printf("Game #%d: no king is in check.\n", game++);
		prox: gets(board[0][0]);
	}
    return 0;
}
