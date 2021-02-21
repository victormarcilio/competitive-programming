#include <bits/stdc++.h>

using namespace std;


int main()
{
	string dic[100];
	char palavra[7];
	string DIC[100];
	int i = 0;
	while(gets(palavra), strcmp("XXXXXX", palavra))
	{
		DIC[i] = dic[i] = palavra;
		i++;
	}
	sort(dic, dic + i);
	sort(DIC, DIC + i);
	for(int k = 0; k < i; k++)
		sort(DIC[k].begin(), DIC[k].end());
	while(gets(palavra), strcmp("XXXXXX", palavra))
	{
		string s(palavra);
		sort(s.begin(), s.end());
		bool achou = false;
		for(int k = 0; k < i; k++)
			if(s == DIC[k])
			{
				achou = true;
				printf("%s\n", dic[k].c_str());
			}
		if(!achou)
			printf("NOT A VALID WORD\n");
		printf("******\n");
	}
}
