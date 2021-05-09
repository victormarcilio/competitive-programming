//https://www.urionlinejudge.com.br/judge/pt/problems/view/2847
#include<bits/stdc++.h>
#pragma warning(disable: 4996)

using namespace std;

int main()
{
#ifdef _DEBUG
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    char line[100010];
    fgets(line, 100010, stdin);
    int rep[200] = {};
    for (char* p = line; *p; p++)
        rep[*p]++;
    int ans = rep['o']/2;
    char phrase[] = "Ilveyu!";
    for (char* c = phrase; *c; c++)
        ans = min(rep[*c], ans);
    printf("%d\n", ans);
}
