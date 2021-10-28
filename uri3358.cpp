#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>
#include <set>
#include <map>
#include<sstream>
#include <unordered_map>
#include <deque>
#include <bitset>
#include<numeric>
#include<queue>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--)
    {
        string nome;
        cin >> nome;
        bool facil = true;
        int cont = 0;
        for (int i = 0; i < nome.size(); i++)
        {
            if (!strchr("aeiouAEIOU", nome[i]))
                cont++;
            else
                cont = 0;
            if (cont == 3)
                facil = false;
        }
        cout << nome << (facil ? " " : " nao ") << "eh facil\n";
    }
}
