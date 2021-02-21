#include <bits/stdc++.h>

using namespace std;

int main()
{	
	char linha[100010], *p;
	
	while(gets(linha))
	{
		string res;
		vector<char> v;
		vector<string> strings;
		
		p = linha;
		while(*p == '[' || *p == ']') p++;
		
		for(; *p; p++)
			if(*p == '[' || *p == ']')
			{
				while(*p == '[' || *p == ']') p++;
				if(*p)
					v.push_back(*(p - 1));
			}
			
		char *p = strtok(linha, "[]");
		while(p)
		{
			strings.push_back(p);
			p = strtok(NULL, "[]");
		}
		if(!strings.size())
		{
			printf("\n");
			continue;
		}
		deque<string> dq;
		dq.push_front(strings[0]);
		for(int i = 1; i < strings.size(); i++)
			if(v[i - 1] == '[')
				dq.push_front(strings[i]);
			else
				dq.push_back(strings[i]);
		
		for(auto i : dq)
			printf("%s", i.c_str());
		printf("\n");
	}
    return 0;
}
