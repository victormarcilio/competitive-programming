#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    string especie, raca, nome;
    while (cin >> N)
    {
        cin.ignore();
        int accepted = 0;
        while (N--)
        {
            getline(cin, especie);
            getline(cin, raca);
            getline(cin, nome);
            cin.ignore();

            if (especie == "cachorro" && nome.find(' ') != -1)
            {
                istringstream s(nome);
                string part;
                while (s >> part)
                    if(part[0] == raca[0])
                    {
                        ++accepted;
                        break;
                    }
            }
        }
        cout << accepted << '\n';
    }
}
