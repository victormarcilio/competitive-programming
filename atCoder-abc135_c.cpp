//https://vjudge.net/problem/AtCoder-abc135_c/origin
//https://atcoder.jp/contests/abc135/tasks/abc135_c?lang=en
#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>
#include <set>
#include <map>
#include<sstream>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <bitset>
#include<numeric>
#include<thread>
#include<queue>
using namespace std;

long long N, A[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i <= N; i++)
        cin >> A[i];
    long long ans = 0, cur;
    for (int i = 0; i < N; i++)
    {
        cin >> cur;
        if (cur >= A[i])
        {
            ans += A[i];
            cur -= A[i];
        }
        else
        {
            ans += cur;
            continue;
        }
        if (cur >= A[i + 1])
        {
            ans += A[i + 1];
            A[i + 1] = 0;
        }
        else
        {
            ans += cur;
            A[i + 1] -= cur;
            continue;
        }
    }
    cout << ans;
}
