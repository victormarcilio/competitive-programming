//https://www.urionlinejudge.com.br/judge/pt/problems/view/3313
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
#ifdef DEBUG
    freopen("C:\\Users\\PeixotoV\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\PeixotoV\\Desktop\\humm.pdf", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s;
    int caso = 1;
    while (cin >> s, s != "*")
    {
        auto len = s.length();
        s += s;
        set<string_view> strings;
        for (int i = 0; i < len; i++)
          strings.insert({ &s[i], len });
       
        auto last = strings.end();
        last--;
        cout << "Caso " << caso++ << ": " << *strings.begin() << ' ' << *last << '\n';
    }
}
