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
    int n, L, Q;
    float l, q;
    cin >> n >> l >> q;
    L = l * 10;
    Q = q * 10;
    vector<string> nomes(n);
    for (int i = 0; i < n; i++)
        cin >> nomes[i];
    int k = 0;
    while (L >= Q)
    {
        L -= Q;
        k++;
        if (k == n)
            k = 0;
    }
    if (L == 0)
    {
        k--;
        if (k < 0)
            k = n - 1;
        printf("%s %.1f\n", nomes[k].c_str(), Q / 10.0);
    }
    else
        printf("%s %.1f\n", nomes[k].c_str(), L / 10.0);
}
