#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    string command;
    cin >> N;
    map<int, int> counter;
    vector<int> presents;
    while (N--)
    {
        cin >> command;
        if (command[1] == 'O')
        {
            if (!presents.size())
            {
                cout << "EMPTY\n";
                continue;
            }
            if (!--counter[presents.back()])
                counter.erase(counter.find(presents.back()));
            presents.pop_back();
        }
        else if (command[1] == 'U')
        {
            int present;
            cin >> present;
            presents.push_back(present);
            ++counter[present];
        }
        else
        {
            if (!presents.size())
            {
                cout << "EMPTY\n";
                continue;
            }
            else
                cout << counter.begin()->first << '\n';
        }
    }
}