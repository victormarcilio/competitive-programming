#include <bits/stdc++.h>
using namespace std;

struct prefix
{
    string value;
    int start_pos;
    bool operator<(const prefix &other) const
    {
        if (value.size() != other.value.size())
            return value.size() > other.value.size();
        return start_pos < other.start_pos;
    }

    prefix(string &&s, int p) : value(move(s)), start_pos(p) {}
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; i++)
        cin >> words[i];
    sort(begin(words), end(words), [](string s1, string s2) { return s1.size() < s2.size(); });
    string &smallest = words[0];
    set<prefix> prefixes;
    set<string> uniques;
    int biggest_prefix = smallest.size();

    for (int max_size = biggest_prefix; max_size; max_size--)
        for (int j = 0; j + max_size <= biggest_prefix; j++)
        {
            string temp = smallest.substr(j, max_size);
            if (uniques.find(temp) == uniques.end())
            {
                uniques.insert(temp);
                prefixes.insert({move(temp), j});
            }
        }
    for (int i = 1; i < words.size(); i++)
    {
        decltype(auto) it = prefixes.begin();
        while (it != prefixes.end())
            if (words[i].find(it->value) == string::npos)
                prefixes.erase(it++);
            else
                ++it;
    }
    cout << prefixes.begin()->value << '\n';
}
