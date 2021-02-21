#include <bits/stdc++.h>

using namespace std;

void print(const vector<int> &v, char* dir)
{
	for(int i = 0; i < v.size(); i++)
			if(i & 1)
				printf("%c", v[i]);
			else
				printf("%d", v[i]);
		printf("%s\n", dir);
}

int main() 
{  
	char esq[100], dir[20];
	while(~scanf("%[^=]%[^\n]\n", esq, dir))
	{
		int k = 0, high = 0;
		for(int i = 0; esq[i]; i++)
		{
			if(esq[i] == '*' || esq[i] == '/')
				high++;
			if(!isspace(esq[i]))
				esq[k++] = esq[i];
		}
		esq[k] = 0;
		vector<int> v; // 0 - operand, 1 - operator
		
		for(int i = 0; esq[i]; i++)
		{
			int sinal = 1;
			if(esq[i] == '-')
			{
				sinal = -1;
				i++;
			}
			if(esq[i] == '+')
				i++;
			
			int num = esq[i] - '0';
			while(isdigit(esq[i + 1]))
			{
				num = num * 10 + esq[i + 1] - '0';
				i++;
			}			
			v.push_back(sinal*num);
			if(esq[i + 1])
			{
				v.push_back(esq[i + 1]);
				i++;
			}
		}
		print(v, dir);
		while(high--)
		{
			int i;
			for(i = 1; v[i] != '*' && v[i] != '/'; i += 2);
			if(v[i] == '*')
				v[i - 1] *= v[i + 1];
			else
				v[i - 1] /= v[i + 1];
			v.erase(v.begin() + i, v.begin() + i + 2);
			print(v, dir);
		}
		while(v.size() > 1)
		{
			if(v[1] == '+')
				v[0] += v[2];
			else
				v[0] -= v[2];
			v.erase(v.begin() + 1, v.begin() + 3);
			print(v, dir);
		}
		printf("\n");
	}
	
    return 0; 
} 
