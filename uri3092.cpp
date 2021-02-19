#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int rounds;
    cin >> rounds;
    string cards;
    while (rounds--)
    {
        cin >> cards;
        auto Q = cards.find('Q');
        auto J = cards.find('J', Q);
        auto K = cards.find('K', J);
        auto A = cards.find('A', K);
        if (J != string::npos && Q != string::npos &&
            K != string::npos && A != string::npos)
            cout << "Agora vai\n";
        else
            cout << "Agora apertou sem abracar\n";
    }
}
