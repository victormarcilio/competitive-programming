//https://www.urionlinejudge.com.br/judge/pt/problems/view/2579
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

    int l, c, x, y;
    scanf("%d %d %d %d", &l, &c, &x, &y);

    if ((c * x + y) % 2)
        printf("Esquerda\n");
    else
        printf("Direita\n");

}
