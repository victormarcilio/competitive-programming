#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, number, total = 0;

    cin >> N >> M;
    queue<int> q;

    for(int i = 0; i < 30; i++){
        cin >> number;
        q.push(number);
        total += number;
    }
    int days = 0;
    while(N <= M)
    {
        int avg = total /30 + (total % 30 != 0);

        total = total - q.front() + avg;
        q.pop();
        q.push(avg);
        days++;
        N += avg;
    }
    cout << days << '\n';
}
