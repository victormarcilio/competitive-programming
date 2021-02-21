#include<bits/stdc++.h>
using namespace std;

char pagina[60][61];
map<char, vector<string> > m;

void limpa()
{
	for(int i = 0; i < 60; i++)
	{
		pagina[i][60] = 0;
		for(int j = 0; j < 60; j++)
			pagina[i][j] = '.';
	}	
}

void imprime(int l, int c, char letra)
{
	for(int i = 0; i < 5 && i + l < 60; i++)
		for(int j = 0; j < 6 && j + c < 60; j++)
			if(j + c >= 0 && m[letra][i][j] == '*')
				pagina[i + l][j + c] = '*';
			
}

int main() 
{
	char comando[1000];
	char quebra[61];
	memset(quebra, '-', sizeof quebra);
	quebra[60] = 0;
	int arg1, arg2, arg3;
	limpa();
	m['A'].push_back(".***.."); m['B'].push_back("****.."); m['C'].push_back(".****."); m['D'].push_back("****.."); m['E'].push_back("*****."); m['F'].push_back("*****."); m['G'].push_back(".****."); m['H'].push_back("*...*."); m['I'].push_back("*****.");
	m['A'].push_back("*...*."); m['B'].push_back("*...*."); m['C'].push_back("*...*."); m['D'].push_back("*...*."); m['E'].push_back("*....."); m['F'].push_back("*....."); m['G'].push_back("*....."); m['H'].push_back("*...*."); m['I'].push_back("..*...");
	m['A'].push_back("*****."); m['B'].push_back("****.."); m['C'].push_back("*....."); m['D'].push_back("*...*."); m['E'].push_back("***..."); m['F'].push_back("***..."); m['G'].push_back("*..**."); m['H'].push_back("*****."); m['I'].push_back("..*...");
	m['A'].push_back("*...*."); m['B'].push_back("*...*."); m['C'].push_back("*....."); m['D'].push_back("*...*."); m['E'].push_back("*....."); m['F'].push_back("*....."); m['G'].push_back("*...*."); m['H'].push_back("*...*."); m['I'].push_back("..*...");
	m['A'].push_back("*...*."); m['B'].push_back("****.."); m['C'].push_back(".****."); m['D'].push_back("****.."); m['E'].push_back("*****."); m['F'].push_back("*....."); m['G'].push_back(".***.."); m['H'].push_back("*...*."); m['I'].push_back("*****.");																																									
	m['J'].push_back("..***."); m['K'].push_back("*...*."); m['L'].push_back("*....."); m['M'].push_back("*...*."); m['N'].push_back("*...*."); m['O'].push_back(".***.."); m['P'].push_back("****.."); m['Q'].push_back(".***.."); m['R'].push_back("****..");
	m['J'].push_back("...*.."); m['K'].push_back("*..*.."); m['L'].push_back("*....."); m['M'].push_back("**.**."); m['N'].push_back("**..*."); m['O'].push_back("*...*."); m['P'].push_back("*...*."); m['Q'].push_back("*...*."); m['R'].push_back("*...*.");
	m['J'].push_back("...*.."); m['K'].push_back("***..."); m['L'].push_back("*....."); m['M'].push_back("*.*.*."); m['N'].push_back("*.*.*."); m['O'].push_back("*...*."); m['P'].push_back("****.."); m['Q'].push_back("*...*."); m['R'].push_back("****..");
	m['J'].push_back("*..*.."); m['K'].push_back("*..*.."); m['L'].push_back("*....."); m['M'].push_back("*...*."); m['N'].push_back("*..**."); m['O'].push_back("*...*."); m['P'].push_back("*....."); m['Q'].push_back("*..**."); m['R'].push_back("*..*..");
	m['J'].push_back(".**..."); m['K'].push_back("*...*."); m['L'].push_back("*****."); m['M'].push_back("*...*."); m['N'].push_back("*...*."); m['O'].push_back(".***.."); m['P'].push_back("*....."); m['Q'].push_back(".****."); m['R'].push_back("*...*.");																																									
	m['S'].push_back(".****."); m['T'].push_back("*****."); m['U'].push_back("*...*."); m['V'].push_back("*...*."); m['W'].push_back("*...*."); m['X'].push_back("*...*."); m['Y'].push_back("*...*."); m['Z'].push_back("*****."); m[' '].push_back("......");
	m['S'].push_back("*....."); m['T'].push_back("*.*.*."); m['U'].push_back("*...*."); m['V'].push_back("*...*."); m['W'].push_back("*...*."); m['X'].push_back(".*.*.."); m['Y'].push_back(".*.*.."); m['Z'].push_back("...*.."); m[' '].push_back("......");
	m['S'].push_back(".***.."); m['T'].push_back("..*..."); m['U'].push_back("*...*."); m['V'].push_back(".*.*.."); m['W'].push_back("*.*.*."); m['X'].push_back("..*..."); m['Y'].push_back("..*..."); m['Z'].push_back("..*..."); m[' '].push_back("......");
	m['S'].push_back("....*."); m['T'].push_back("..*..."); m['U'].push_back("*...*."); m['V'].push_back(".*.*.."); m['W'].push_back("**.**."); m['X'].push_back(".*.*.."); m['Y'].push_back("..*..."); m['Z'].push_back(".*...."); m[' '].push_back("......");
	m['S'].push_back("****.."); m['T'].push_back(".***.."); m['U'].push_back(".***.."); m['V'].push_back("..*..."); m['W'].push_back("*...*."); m['X'].push_back("*...*."); m['Y'].push_back("..*..."); m['Z'].push_back("*****."); m[' '].push_back("......");
	
																																																							
	
	while(scanf("%s", comando) != EOF)
	{
		if(!strcmp(comando, ".EOP"))
		{
			
			for(int i = 0; i < 60; i++)
				printf("%s\n", pagina[i]);
			limpa();
			printf("\n%s\n\n", quebra);
		}
		
		else if(comando[1] == 'C')
		{
			scanf("%*[^15]%d %d |%[^|]|", &arg1, &arg2, comando);
			if(arg1 == 1)
			{
				for(int i = 30 - strlen(comando)/2, k = 0; i < 60 && comando[k]; i++, k++)
					if(i >= 0 && comando[k] != ' ')
						pagina[arg2 - 1][i] = comando[k];
			}
			else
			{
				string temp(comando);
				while(temp.size() < 10)
					temp = " " + temp + " ";
				for(int i = (temp.size() - 10)/2, k = 0; k < 10 + (temp.size() - 10)%2; i++, k++)
					imprime(arg2 - 1, k * 6 - ((temp.size() - 10)%2 ? 3 : 0), temp[i]);
			}
		}
		else if(comando[1] == 'P')
		{
			scanf("%*[^15]%d %d %d |%[^|]|", &arg1, &arg2, &arg3, comando);
			
			if(arg1 == 1)
			{
				for(int i = arg3 - 1, k = 0; comando[k] && i < 60; i++, k++)
					if(comando[k] != ' ')
						pagina[arg2 - 1][i] = comando[k];
			}
			else
			{
				for(int i = 0, k = 0; comando[k] && i < 60; i+= 6, k++)
					imprime(arg2 - 1, i + arg3 - 1, comando[k]);
			}
		}
		else if(comando[1] == 'L')
		{
			scanf("%*[^15]%d %d |%[^|]|", &arg1, &arg2, comando);
			
			if(arg1 == 1)
			{
				for(int i = 0, k = 0; comando[k] && i < 60; i++, k++)
					if(comando[k] != ' ')
						pagina[arg2 - 1][i] = comando[k];
			}
			else
			{
				for(int i = 0, k = 0; comando[k] && i < 60; i+= 6, k++)
					imprime(arg2 - 1, i, comando[k]);
			}
		}
		else
		{
			scanf("%*[^15]%d %d |%[^|]|", &arg1, &arg2, comando);
			if(arg1 == 1)
			{
				for(int i = 59, k = strlen(comando) - 1; k >= 0 && i >= 0; i--, k--)
					if(comando[k] != ' ')
						pagina[arg2 - 1][i] = comando[k];
			}
			else
			{
				for(int i = 54, k = strlen(comando) - 1; k >= 0 && i >= 0; i-= 6, k--)
					imprime(arg2 - 1, i, comando[k]);
			}
		}
	}
	
    return 0;
}
