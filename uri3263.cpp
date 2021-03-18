#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    if(n & 1)
    {
        for(int i = 0; i < s1.size(); i++)
            if(s1[i] == s2[i])
            {
                cout << "Deletion failed\n";
                return 0;
            }
        cout << "Deletion succeeded\n";
    }
    else
        cout << (s1 == s2 ? "Deletion succeeded\n" : "Deletion failed\n");
}
