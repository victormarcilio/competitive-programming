#include <bits/stdc++.h>

/* Treta com o NÓS e VÓS... tem que ir pelo ascii code mesmo*/ 

using namespace std;

int main()
{
	//freopen("C:/Users/slipn/Desktop/in", "r", stdin);
	//freopen("C:/Users/slipn/Desktop/out", "w", stdout);
	char en[35], pt[40];
	int primeira = true;
	char pronomes[][10] = {"eu", "tu", "ele/ela", "n0s", "v0s ", "eles/elas"};
	pronomes[3][1] = pronomes[4][1] = 243;
	char sufix[][6][5] = { {"o", "as", "a", "amos", "ais", "am"}, {"o", "es", "e", "emos", "eis", "em" }, {"o", "es", "e", "imos", "is", "em"} };
	while (~scanf("%s %s\n", pt, en))
	{
		if (!primeira)
			printf("\n");
		primeira = false;
		int len = strlen(pt);
		printf("%s (to %s)\n", pt, en);
		if (len < 1 || pt[len - 1] != 'r')
		{
			printf("Unknown conjugation\n");
			continue;
		}
		char tv = pt[len - 2];
		pt[len - 2] = 0;
		if (tv == 'a')
			for (int i = 0; i < 6; i++)
					printf("%-10s%s%s\n", pronomes[i], pt, sufix[0][i]);
		else if (tv == 'e')
			for (int i = 0; i < 6; i++)
				printf("%-10s%s%s\n", pronomes[i], pt, sufix[1][i]);
		else if (tv == 'i')
			for (int i = 0; i < 6; i++)
				printf("%-10s%s%s\n", pronomes[i], pt, sufix[2][i]);
		else
			printf("Unknown conjugation\n");
	}
}