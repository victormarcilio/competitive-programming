#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, down, up, wait;
    long long total = 0, max_cap;
    cin >> max_cap >> n;
    while (n--)
    {
        cin >> down >> up >> wait;
        total -= down;
        if (total < 0)
        {
            cout << "impossible\n";
            return 0;
        }
        total += up;
        if (total > max_cap || (total < max_cap && wait))
        {
            cout << "impossible\n";
            return 0;
        }
    }
    if (total || wait)
        cout << "im";
    cout << "possible\n";
    
}
