#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int students, year;
    char names[50010];
    while (scanf("%d %d\n", &students, &year) != EOF)
    {
        set<string> shortcuts;
        for(int j = 0; j < students; ++j)
        {
            gets(names);
            string shortcut;
            if(isalpha(names[0]))
                shortcut.push_back(names[0]);
            for(int i = 1; names[i]; i++)
                if(names[i] != ' ' && names[i - 1] == ' ') 
                    shortcut.push_back(names[i]);
            shortcuts.insert(shortcut);
        }
        cout << students - shortcuts.size() << '\n';
    }
}