#include <bits/stdc++.h>

using namespace std;
string S1, S2;

// Nessa aqui eu bestei pq na linha 25 só tava checando a pilha!

void imprime(vector<char> v)
{
	printf("%c", v[0]);
	for(int i = 1; i < v.size(); i++)
		printf(" %c", v[i]);
	printf("\n");
}

void f(stack<char> s, int pos1, int pos2, vector<char> v)
{
	if(pos1 == S1.size())
	{
		while(!s.empty() && s.top() == S2[pos2++])
		{
			s.pop();
			v.push_back('o');
		}
		if(s.empty() && pos2 == S2.size())
			imprime(v);
		return;
	}
	s.push(S1[pos1]);
	v.push_back('i');
	f(s, pos1 + 1, pos2, v);
	s.pop();
	v.pop_back();
	if(!s.empty() && s.top() == S2[pos2])
	{
		s.pop();
		v.push_back('o');
		f(s, pos1, pos2 + 1, v);
	}
}

int main()
{	
	char s1[100], s2[100];
	while(~scanf("%s\n", s1))
	{
        scanf("%s\n", s2);
		S1 = s1;
		S2 = s2;
		
		vector<char> v;
		stack<char> s;
		printf("[\n");
		f(s, 0, 0, v);
		printf("]\n");
	}
    return 0;
}
