//https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/alien-language/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    char text[100010], pattern[100010];
    while (t--)
    {
        scanf("%s\n%s\n", text, pattern);
        vector<int> v(200);
        bool found = false;
        for (int i = 0; text[i]; i++)
            v[text[i]]++;

        for (int i = 0; pattern[i]; i++)
            if (v[pattern[i]])
            {
                found = true;
                break;
            }

        printf("%s\n", found ? "YES" : "NO");
    }
}
