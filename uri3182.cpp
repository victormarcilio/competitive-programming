#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, b, h, w;
    cin >> n >> b >> h >> w;
    
    int best = b + 1, price, spots;
    while(h--)
    {
        cin >> price;
        for(int i = 0; i < w; i++)
        {
            cin >> spots;
            if(spots >= n)
                best = min(best, price*n);
        }
    }
    if(best > b)
        cout << "stay home\n";
    else
        cout << best << '\n';
}