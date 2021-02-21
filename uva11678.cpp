#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, v;
	while(scanf("%d %d", &a, &b), a)
	{
		set<int> A, B, C;
		for(int i = 0; i < a; i++)
		{
			scanf("%d", &v);
			A.insert(v);
			C.insert(v);
		}
		for(int i = 0; i < b; i++)
		{
			scanf("%d", &v);
			B.insert(v);
			C.insert(v);
		}
		
		for(auto x : C)
		{
			if(A.find(x) != A.end() && B.find(x) != B.end())
			{
				A.erase(x);
				B.erase(x);
			}
		}
		
		printf("%d\n", min(A.size(), B.size()));
	}
}
