#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    queue<string> names[20];
    string name;
    while(N--)
    {
        cin >> name;
        names[name.size()].push(name);
    }
    bool found = true;
    while(found)
    {
        found = false;
        for(int i = 2; i < 20; i++)
            if(!names[i].empty())
            {
                if(found)
                    cout << ", ";
                cout << names[i].front();
                names[i].pop();
                found = true;
            }
        cout << '\n';
    }
}
