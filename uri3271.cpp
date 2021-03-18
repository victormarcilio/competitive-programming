#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[4], b[4];
    for(int i = 0; i < 4; i++)
        cin >> a[i];
    for(int i = 0; i < 4; i++)
        cin >> b[i];
    int s1 = accumulate(a, a + 4, 0);
    int s2 = accumulate(b, b + 4, 0);
    if(s1 == s2)
        cout << "Tie\n";
    else if(s1 > s2)
        cout << "Gunnar\n";
    else
        cout << "Emma\n";
}
