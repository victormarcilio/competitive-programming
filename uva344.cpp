//https://onlinejudge.org/external/3/344.pdf
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<map<char,int>> v(101);
    vector<pair<int, string>> values{{100, "c"}, {90, "cx"}, {50, "l"}, {40, "lx"}, {10, "x"}, {9, "ix"}, {5, "v"}, {4, "iv"},{1,"i"}};
    for(int i = 1; i <= 100; i++)
    {
        int k = i;
        for(auto par : values)
        {
            while(k >= par.first)
            {
                k -= par.first;
                for(auto j : par.second)
                    v[i][j]++;
            }
        }        
        for(char c : "ivcxl")
            v[i][c] += v[i - 1][c];
    }
    while(scanf("%d", &n), n)
        printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, v[n]['i'], v[n]['v'], v[n]['x'], v[n]['l'], v[n]['c']);
}
