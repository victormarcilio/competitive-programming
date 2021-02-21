#include <bits/stdc++.h>
using namespace std;

int main()
{
//	freopen("C:/Users/slipn/Desktop/in", "r", stdin);
//	freopen("C:/Users/slipn/Desktop/out", "w", stdout);

	int n;
	scanf("%d\n", &n);
	int caso = 1;
	while (n--)
	{
		char s1[200], s2[200];
		scanf("%[^\n]%*c", s1);
		scanf("%[^\n]%*c", s2);
		printf("Case %d: ", caso++);
		if (!strcmp(s1, s2))
			printf("Yes\n");
		else
		{
			int i, k;
			for (i = 0, k = 0; s1[i]; i++)
				if (!isspace(s1[i]))
					s1[k++] = s1[i];
			s1[k] = 0;

			for (i = 0, k = 0; s2[i]; i++)
				if (!isspace(s2[i]))
					s2[k++] = s2[i];
			s2[k] = 0;
			if (!strcmp(s1, s2))
				printf("Output Format Error\n");
			else
				printf("Wrong Answer\n");
		}
	}

	return 0;
}