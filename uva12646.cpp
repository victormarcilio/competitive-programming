#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int P, H, O;
    while (cin >> P >> H >> O)
    {
        if (P != H && P != O)
            cout << "A\n";
        else if (H != P && H != O)
            cout << "B\n";
        else if (O != H && O != P)
            cout << "C\n";
        else
            cout << "*\n";
    }
}
