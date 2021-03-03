#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int P, H, O;
    while (cin >> P >> H >> O)
        cout << (O - P >= H ? "Props win!\n" : "Hunters win!\n");
}
