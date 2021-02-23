#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> list1, list2;
    char linha[1000000];
    gets(linha);
    char *p = strtok(linha, " ");
    while (p)
    {
        list1.emplace_back(p);
        p = strtok(NULL, " ");
    }
    gets(linha);
    p = strtok(linha, " ");
    while (p)
    {
        list2.emplace_back(p);
        p = strtok(NULL, " ");
    }
    gets(linha);

    if (strcmp(linha, "nao"))
        list1.insert(find(begin(list1), end(list1), linha), begin(list2), end(list2));
    else
        list1.insert(end(list1), begin(list2), end(list2));
    cout << list1[0];
    for (int i = 1; i < list1.size(); i++)
        cout << ' ' << list1[i];
    cout << '\n';
}
