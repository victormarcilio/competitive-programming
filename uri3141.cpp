#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char name[60];
    gets(name);
    int bm, bd, by, m, y, d;
    scanf("%d/%d/%d %d/%d/%d", &d, &m, &y, &bd, &bm, &by);
    if(bd == d && bm == m)
        printf("Feliz aniversario!\n");
    printf("Voce tem %d anos %s.\n", y - by - !(m > bm || m == bm & d >= bd), name);
}
