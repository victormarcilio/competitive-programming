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
        auto SEVEN = cards.find('7');
        auto Q = cards.find('Q', SEVEN);
        auto J = cards.find('J', Q);
        auto K = cards.find('K', J);
        auto A = cards.find('A', K);
        while (J != string::npos && Q != string::npos &&
               K != string::npos && A != string::npos &&
               SEVEN != string::npos)
        {
            cards.erase(A, 1);
            cards.erase(K, 1);
            cards.erase(J, 1);
            cards.erase(Q, 1);
            cards.erase(SEVEN, 1);

            SEVEN = cards.find('7');
            Q = cards.find('Q', SEVEN);
            J = cards.find('J', Q);
            K = cards.find('K', J);
            A = cards.find('A', K);
        }
        cout << cards.size() << '\n';
    }
}
