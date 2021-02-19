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
        if (cards.find('A') != string::npos && cards.find('K') != string::npos &&
            cards.find('Q') != string::npos && cards.find('J') != string::npos)
            cout << "Aaah muleke\n";
        else
            cout << "Ooo raca viu\n";
    }
}
