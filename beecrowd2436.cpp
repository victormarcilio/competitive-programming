//https://www.beecrowd.com.br/judge/pt/problems/view/2436
#include <iostream>

using namespace std;

int m[1010][1010];

int main()
{
    int l, c, x, y;
    scanf("%d %d %d %d", &l, &c, &x, &y);
    
    for(int i = 1; i <= l; ++i)
        for(int j = 1; j <= c; ++j)
            scanf("%d", &m[i][j]);
    while(m[x][y])
    {
        m[x][y] = 0;
        if(m[x + 1][y])
            ++x;
        else if(m[x - 1][y])
            --x;
        else if(m[x][y + 1])
            ++y;
        else if(m[x][y - 1])
            --y;
    }
    printf("%d %d\n", x, y);
    return 0;
}
