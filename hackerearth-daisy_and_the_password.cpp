#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    string s1, s2;
    cin >> t;
    while (t--)
    {
        cin >> s1 >> s2;
        set<string> s;
        for(int i = 0; i < s1.size(); i++)
            s.insert(s1.substr(0, i) + s1 + s1.substr(i));
        
        if(s.count(s2))
            printf("Possible\n");
        else
            printf("Impossible\n");
    }
}
