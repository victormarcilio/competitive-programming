#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int H, E, A, O, W, X;

    cin >> H >> E >> A >> O >> W >> X;
    cout << (H + E + A + X >= O + W ? "Middle-earth is safe.\n" : "Sauron has returned.\n");
}
