#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, down, up, wait;
    long long total = 0, max_cap;
    scanf("%lld %d", &max_cap, &n);
    while (n--)
    {
        scanf("%d %d %d", &down, &up, &wait);
        total -= down;
        if (total < 0)
        {
            printf("impossible\n");
            return 0;
        }
        total += up;
        if (total > max_cap || (total < max_cap && wait))
        {
            printf("impossible\n");
            return 0;
        }
    }
    if (total || wait)
        printf("impossible\n");
    else
        printf("possible\n");
    
}
