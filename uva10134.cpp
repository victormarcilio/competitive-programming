
#include <bits/stdc++.h>
using namespace std;


int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	int n;
	scanf("%d%*c", &n);
	char ins[10];
	cin.getline(ins, sizeof ins);
	while (n--)
	{
		int fish = 0, bait = 0, insts = 7, fishings = 2;
		while (cin.getline(ins, sizeof ins), ins[0])
		{
			insts++;
			if (ins[0] == 'b' && bait < 6)
				bait++;
			else if (ins[0] == 'f' && bait > 1)
			{
				fishings++;
				if (fishings > 2 && insts > 6)
				{
					bait -= 2;
					fish++;
					insts = fishings = 0;
				}
			}
		}
		printf("%d\n", fish);
		if (n)
			printf("\n");
	}
}
