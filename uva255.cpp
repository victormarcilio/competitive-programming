#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q, k, n = 0, colq, rowq, colk, rowk, rown, coln;
	map<int, pair<int, int>> m;
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			m[n++] = make_pair(i, j);
	prox: while(scanf("%d %d %d", &k, &q, &n) != EOF)
	{
		if(k == q)
			printf("Illegal state\n");
		else 
		{
			rowk = m[k].first;
			colk = m[k].second;
			rowq = m[q].first;
			colq = m[q].second;
			rown = m[n].first;
			coln = m[n].second;
			
			if(coln == colq && rown == rowq || coln != colq && rown != rowq || rown == rowk && coln == colk)
			{
				printf("Illegal move\n");
				goto prox;
			}
			// pra evitar 2 IFS abaixo (L.37)
			if(colq == colk)
			{
				swap(colq, rowq);
				swap(colk, rowk);
				swap(coln, rown);
			}
			if(rowq == rowk && (colq > colk && coln < colk || colq < colk && coln > colk))
			{
				printf("Illegal move\n");
				goto prox;
			}
			//pra evitar 2 IFS (L.50)
			if(colk == coln)
			{
				swap(colq, rowq);
				swap(colk, rowk);
				swap(coln, rown);
			}
			
			if(rowk == rown && abs(colk - coln) == 1 || q == n)
				printf("Move not allowed\n");
			else
			{
				bool pode = false;
				if(rowk > 0 && rowk - 1 != rown )
					pode = true;
				if(rowk < 7 && rowk + 1 != rown )
					pode = true;
				if(colk > 0 && colk - 1 != coln )
					pode = true;
				if(colk < 7 && rowk + 1 != coln )
					pode = true;
				
				printf("%s\n", pode ? "Continue" : "Stop");
			}
		}
	}
    return 0;
}
