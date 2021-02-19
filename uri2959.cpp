#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A, B, N, M, P;

    cin >> N >> M >> P;
    vector<int> groups(N + 1);
    iota(begin(groups), end(groups), 0);
    while(M--)
    {
        cin >> A >> B;
        while(groups[A] != A)
            A = groups[A];
        while(B != groups[B])
            B = groups[B];
        if(B != A)
            groups[B] = groups[A];
    }
    while(P--)
    {
        cin >> A >> B;
        while(A != groups[A])
            A = groups[A];
        while(B != groups[B])
            B = groups[B];
        cout << (groups[A] == groups[B] ? "Lets que lets\n" : "Deu ruim\n");
    }
}