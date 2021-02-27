#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<pair<int, int>, string>> people;
    int P, Q, M, H;
    int midnight = 24 * 60;
    char name[150];
    scanf("%d %d", &P, &Q);
    for(int i = 0; i < Q; i++)
    {
        scanf("%d:%d %s", &H, &M, name);
        int minutes = 60 * (H ? H : 24) + M;
        if(abs(minutes - midnight) <= P)
            people.push_back({{minutes, i}, name}); 
    }
    sort(begin(people), end(people));
    for(int i = 0; i < people.size(); i++)
        printf("%s\n", people[i].second.c_str());
}
