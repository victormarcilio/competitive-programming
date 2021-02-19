#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int weights[4];
    int integer, fract;
    for (int i = 0; i < 4; i++)
    {
        scanf("%d.%d", &integer, &fract);
        weights[i] = integer * 10 + fract;
    }
    sort(begin(weights), end(weights));
    if (weights[3] == weights[0] + weights[1] + weights[2] ||
        weights[0] + weights[3] == weights[1] + weights[2])
        puts("YES");
    else
        puts("NO");
}
