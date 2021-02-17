#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    string from, to;
    map<string, string> transform;
    while (M--)
    {
        cin >> from >> to;
        transform[from] = to;
    }
    string current = "A";
    while(N--)
    {
        string mutated = "";
        for(int i = 0; i < current.size(); i++)
        {
            int j = i + 1;
            while(j < current.size() && current[i] == current[j])
                ++j;
            mutated += transform[current.substr(i, j - i)];
            i = j - 1;
        }
        swap(mutated, current);
    }
    int A = 0;
    for (auto i : current)
        if(i == 'A')
            A++;
    cout << A << ' ' << current.size() - A << '\n';
}
