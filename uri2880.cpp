#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string cipher, crib;
    cin >> cipher >> crib;
    int limit = cipher.size() - crib.size();
    int positions = 0;
    for (int i = 0; i <= limit; i++)
    {
        bool possible = true;
        for (int j = 0; j < crib.size(); j++)
            if (cipher[i + j] == crib[j])
            {
                possible = false;
                break;
            }
        positions += possible;
    }
    cout << positions << '\n';
}
