#include <bits/stdc++.h>

using namespace std;

int main() 
{  
	char linha[1000];
	bool parsing = true;
	
	while(gets(linha))
	{
		for(int i = 0; linha[i]; i++)
		{
			if(linha[i] == '\\' && linha[i + 1] == '*')
			{
				parsing = !parsing;
				i++;
			}
			else if(!parsing)
				printf("%c", linha[i]);
			else if(linha[i] == '\\' && (linha[i + 1] == 'b' || linha[i + 1] == 'i'))
				i++;
			else if(linha[i] == '\\' && linha[i + 1] == 's')
			{
				i++;
				while(isdigit(linha[i + 1]))
					i++;
				if(linha[i + 1] == '.')
				{
					i++;
					while(isdigit(linha[i + 1]))
						i++;
				}
			}
			else if(linha[i] == '\\')
				printf("%c", linha[++i]);
			
			else
				printf("%c", linha[i]);
		}
		printf("\n");
	}
	
	
    return 0; 
} 
