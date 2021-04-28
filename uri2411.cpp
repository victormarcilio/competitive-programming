#include<bits/stdc++.h>
#pragma warning(disable: 4996)

using namespace std;

int main()
{
#ifdef _LOCALs
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, mov;
    cin >> n;
    int x = 4, y = 3, ans = 0;
    set<pair<int, int>> holes{ {1,3}, {2,3}, {2,5}, {5,4} };
    while (n--)
    {
        cin >> mov;
        if (mov == 1)
        {
            x++;
            y += 2;
        }
        else if (mov == 2)
        {
            x += 2;
            y++;
        }
        else if (mov == 3)
        {
            x += 2;
            y--;
        }
        else if (mov == 4)
        {
            x++;
            y -= 2;
        }
        else if (mov == 5)
        {
            x--;
            y -= 2;
        }
        else if (mov == 6)
        {
            x -= 2;
            y--;
        }
        else if(mov == 7)
        {
            x -= 2;
            y++;
        }
        else
        {
            x--;
            y += 2;
        }
        ans++;
        if (x < 0 || x > 7 || y < 0 || y > 7 || holes.find({ x, y }) != holes.end())
            break;
        
    }
    cout << ans << '\n';

}
