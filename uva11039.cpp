#include <bits/stdc++.h>

using namespace std;

int main()
{	
	int n, t, x;
	scanf("%d", &n);
	while(n--)
	{
		priority_queue<int> pq[2]; // red 0
		scanf("%d", &t);
		if(!t)
		{
			printf("0\n");
			continue;
		}
		while(t--)
		{
			scanf("%d", &x);
			if(x > 0)
				pq[0].push(-x);
			else
				pq[1].push(x);
		}
		
		if(pq[0].empty() || pq[1].empty())
		{
			printf("1\n");
			continue;
		}
		bool blue = true;
		int atual = -pq[0].top();
		int cont = 1;
		
		if(-pq[0].top() < -pq[1].top())
			pq[0].pop();
		else
		{
			blue = false;
			atual = -pq[1].top();
			pq[1].pop();
		}
		while(!pq[blue].empty())
		{
			while(!pq[blue].empty() && -pq[blue].top() < atual)
				pq[blue].pop();
			if(!pq[blue].empty())
			{
				atual = -pq[blue].top();
				pq[blue].pop();
				blue = !blue;
				cont++;
			}
		}
		
		
		printf("%d\n", cont);
	}
	
    return 0;
}
