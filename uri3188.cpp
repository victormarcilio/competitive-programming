#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<string> phones(n);
        for(int i = 0; i < n; i++)
            cin >> phones[i];
        bool pode = true;
        sort(begin(phones), end(phones));
        for(int i = 1; i < n; i++)
            if(phones[i].rfind(phones[i - 1], phones[i - 1].size() - 1) != string::npos)
            {
                pode = false;
                break;
            }
        cout << (pode ? "YES\n" : "NO\n");
    }
}
