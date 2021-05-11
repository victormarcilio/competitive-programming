//https://www.urionlinejudge.com.br/judge/pt/problems/view/2421
#include<bits/stdc++.h>
#pragma warning(disable: 4996)

using namespace std;

bool check(int L, int H, int l1, int h1, int l2, int h2)
{
    return H >= max(h1, h2) && L >= l1 + l2;
}

int main()
{
#ifdef _DEBUGs
    freopen("C:\\Users\\victor_peixoto\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\victor_peixoto\\Desktop\\out.txt", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int x, y, l1, l2, h1, h2;
    cin >> x >> y >> l1 >> h1 >> l2 >> h2;
    if(check(x, y, l1, h1, l2, h2) || check(x, y, h1, l1, l2, h2) || check(x, y, l1, h1, h2, l2) || check(x, y, l1, h1, l2, h2) || check(x, y, h1, l1, h2, l2))
        cout << "S\n";
    else
    {
        swap(x, y);
        if (check(x, y, l1, h1, l2, h2) || check(x, y, h1, l1, l2, h2) || check(x, y, l1, h1, h2, l2) || check(x, y, l1, h1, l2, h2) || check(x, y, h1, l1, h2, l2))
            cout << "S\n";
        else            
            cout << "N\n";
    }
    
}
