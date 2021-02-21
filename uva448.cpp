#include <bits/stdc++.h>

using namespace std;

int main()
{
	char opcode, mode, operand;
	map<char, string> opcodes; 
	opcodes['0'] = "ADD";
	opcodes['1'] = "SUB";
	opcodes['2'] = "MUL";
	opcodes['3'] = "DIV";
	opcodes['4'] = "MOV";
	opcodes['5'] = "BREQ";
	opcodes['6'] = "BRLE";
	opcodes['7'] = "BRLS";
	opcodes['8'] = "BRGE";
	opcodes['9'] = "BRGR";
	opcodes['A'] = "BRNE";
	opcodes['B'] = "BR";
	opcodes['C'] = "AND"; 
	opcodes['D'] = "OR";
	opcodes['E'] = "XOR";
	opcodes['F'] = "NOT";
	while(scanf("%c", &opcode) != EOF)
	{
		if(opcode == '\n')
			continue;
	
		printf("%s ", opcodes[opcode].c_str());
		
		if(opcode >= '0' && opcode <= '4')
		{
			int n = 2;
			while(n--)
			{
				do{	scanf("%c", &mode);} while(mode == '\n');
				if(strchr("0123", mode))
					printf("R");
				else if(strchr("4567", mode))
					printf("$");
				else if(strchr("89AB", mode))
					printf("PC+");
				int res = 0;
				
				if(isdigit(mode))
					res = (mode - '0')%4;
				else
					res = (mode - 'A' + 10)%4;
				
				for(int i = 0; i < 3; i++)
				{
					scanf("%c", &operand);
						
					if(operand == '\n')
					{
						i--;
						continue;
					}
					// pq não posso tirar o parentese do segundo termo????
					res = (res << 4) + (isdigit(operand) ? operand - '0' : operand - 'A' + 10);
				}
				printf("%d%c", res, n ? ',' : '\n');
			}
			
		}
		else if(opcode >= '5' && opcode <= '9' || opcode == 'A' || opcode == 'B')
		{
			
			do{	scanf("%c", &mode);} while(mode == '\n');
			int res = 0;
			if(strchr("0123", mode))
				printf("R");
			else if(strchr("4567", mode))
				printf("$");
			else if(strchr("89AB", mode))
				printf("PC+");
			if(isdigit(mode))
				res = (mode - '0')%4;
			else
				res = (mode - 'A' + 10)%4;
			
			for(int i = 0; i < 3; i++)
				{
					scanf("%c", &operand);
					if(operand == '\n')
					{
						i--;
						continue;
					}
					// pq não posso tirar o parentese do segundo termo????
					res = (res << 4) + (isdigit(operand) ? operand - '0' : operand - 'A' + 10);
				}
			
			printf("%d\n", res);
		}
		else if(opcode == 'F')
		{
			do{	scanf("%c", &mode);} while(mode == '\n');
				if(strchr("0123", mode))
					printf("R");
				else if(strchr("4567", mode))
					printf("$");
				else if(strchr("89AB", mode))
					printf("PC+");
				int res = 0;
				
				if(isdigit(mode))
					res = (mode - '0')%4;
				else
					res = (mode - 'A' + 10)%4;
				
				for(int i = 0; i < 3; i++)
				{
					scanf("%c", &operand);
					if(operand == '\n')
					{
						i--;
						continue;
					}
					// pq não posso tirar o parentese do segundo termo????
					res = (res << 4) + (isdigit(operand) ? operand - '0' : operand - 'A' + 10);
				}
			
				printf("%d\n", res);
		}
		else
		{
			int n = 3;
			while(n--)
			{
				do{	scanf("%c", &mode);} while(mode == '\n');
				if(strchr("0123", mode))
					printf("R");
				else if(strchr("4567", mode))
					printf("$");
				else if(strchr("89AB", mode))
					printf("PC+");
				int res = 0;
				
				if(isdigit(mode))
					res = (mode - '0')%4;
				else
					res = (mode - 'A' + 10)%4;
				
				for(int i = 0; i < 3; i++)
				{
					scanf("%c", &operand);
						
					if(operand == '\n')
					{
						i--;
						continue;
					}
					// pq não posso tirar o parentese do segundo termo????
					res = (res << 4) + (isdigit(operand) ? operand - '0' : operand - 'A' + 10);
				}
				printf("%d%c", res, n ? ',' : '\n');
			}
		}
	}
    return 0;
}
