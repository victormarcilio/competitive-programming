//https://www.urionlinejudge.com.br/judge/pt/problems/view/3306
#include<iostream>
#include <vector>
#include<numeric>
using namespace std;

int main(int argc, char** argv)
{
#ifdef DEBUG
    freopen("C:\\Users\\PeixotoV\\Desktop\\in.txt", "r", stdin);
    //freopen("C:\\Users\\PeixotoV\\Desktop\\humm.pdf", "w", stdout);
#endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, Q, op, A, B, V;
    cin >> N >> Q;

    vector<int> difs(N + 2), v(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> v[i];
    while (Q--)
    {
        cin >> op >> A >> B;
        if (op == 1)
        {
            cin >> V;
            difs[A] += V;
            difs[B + 1] -= V;
        }
        else
        {
            int acc = 0;

            for (int i = 0; i <= A; i++)
                acc += difs[i];
            int ans = v[A] + acc;
            for (int i = A + 1; i <= B; i++)
            {
                acc += difs[i];
                ans = gcd(ans, acc + v[i]);
            }
            cout << ans << '\n';
        }
    }
}
