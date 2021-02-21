#include <bits/stdc++.h>

using namespace std;


int main()
{
	int a;
	char b[12];
	char numeros[10][5][4] = {{" - ", "| |", "   ", "| |", " - "}, //0
							{"   ", "  |", "   ", "  |", "   "}, //1
							{" - ", "  |", " - ", "|  ", " - "}, //2 
							{" - ", "  |", " - ", "  |", " - "}, //3
							{"   ", "| |", " - ", "  |", "   "}, //4
							{" - ", "|  ", " - ", "  |", " - "}, //5
							{" - ", "|  ", " - ", "| |", " - "}, //6
							{" - ", "  |", "   ", "  |", "   "}, //7
							{" - ", "| |", " - ", "| |", " - "}, //8
							{" - ", "| |", " - ", "  |", " - "}};//9 
	char one[5][4] = {"   ", "  |", "   ", "  |", "   "};
	char two[5][4] = {" - ", "  |", " - ", "|  ", " - "};
	char three[5][4] = {" - ", "  |", " - ", "  |", " - "};
	char four[5][4] = {"   ", "| |", " - ", "  |", "   "};
	char five[5][4] = {" - ", "|  ", " - ", "  |", " - "};
	char six[5][4] = {" - ", "|  ", " - ", "| |", " - "};
	char seven[5][4] = {" - ", "  |", "   ", "  |", "   "};
	char eight[5][4] = {" - ", "| |", " - ", "| |", " - "};
	char nine[5][4] = {" - ", "| |", " - ", "  |", " - "};
	char zero[5][4] = {" - ", "| |", "   ", "| |", " - "};
	
	//for(int i = 0; i < 10; i++)
	//	for(int j = 0; j < 5; j++)
	//		printf("%s\n", numeros[i][j]);
	
	while(scanf("%d %s", &a, b), a)
	{
		//primeira linha
		for(int i = 0; b[i]; i++)
		{
			printf("%c", numeros[b[i] - '0'][0][0]);
			for(int j = 0; j < a; j++)
				printf("%c", numeros[b[i] - '0'][0][1]);
			printf("%c", numeros[b[i] - '0'][0][2]);
			printf("%c", b[i + 1] ? ' ' : '\n');
		}

		
		for(int k = 0; k < a; k++)
		{
			for(int i = 0; b[i]; i++)
			{
				printf("%c", numeros[b[i] - '0'][1][0]);
				for(int j = 0; j < a; j++)
					printf("%c", numeros[b[i] - '0'][1][1]);
				printf("%c", numeros[b[i] - '0'][1][2]);
				printf("%c", b[i + 1] ? ' ' : '\n');
			}
		}
		
		// linha do meio
		for(int i = 0; b[i]; i++)
		{
			printf("%c", numeros[b[i] - '0'][2][0]);
			for(int j = 0; j < a; j++)
				printf("%c", numeros[b[i] - '0'][2][1]);
			printf("%c", numeros[b[i] - '0'][2][2]);
			printf("%c", b[i + 1] ? ' ' : '\n');
		}
		
		for(int k = 0; k < a; k++)
		{
			for(int i = 0; b[i]; i++)
			{
				printf("%c", numeros[b[i] - '0'][3][0]);
				for(int j = 0; j < a; j++)
					printf("%c", numeros[b[i] - '0'][3][1]);
				printf("%c", numeros[b[i] - '0'][3][2]);
				printf("%c", b[i + 1] ? ' ' : '\n');
			}
		}
		//ultima linha
		for(int i = 0; b[i]; i++)
		{
			printf("%c", numeros[b[i] - '0'][4][0]);
			for(int j = 0; j < a; j++)
				printf("%c", numeros[b[i] - '0'][4][1]);
			printf("%c", numeros[b[i] - '0'][4][2]);
			printf("%c", b[i + 1] ? ' ' : '\n');
		}
		printf("\n");
	}
}
