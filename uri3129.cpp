#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    vector<bool> figures(301);
    cin >> N;
    int repeated = 0, figure;
    for(int i = 0; i < N; ++i)
    {
        cin >> figure;
        if(figures[figure])
            ++repeated;
        figures[figure] = true;
    }
    cout << N - repeated << '\n' << repeated << '\n';
}
