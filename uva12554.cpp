#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, i = 0;
	scanf("%d\n", &t);
	char nomes[100][110];
	while(t--)
		gets(nomes[i++]);
	char musica[][16] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
	int j = 0;
	while(j < i)
		for(int k = 0; k < 16; k++, j++)
			printf("%s: %s\n", nomes[j%i], musica[k]);
}
