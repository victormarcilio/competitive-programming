#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

struct prefix
{
    string_view value;
    int start_pos;
    int size;
    prefix(string_view s, int p, int len) : value{s}, start_pos{p}, size{len} {}

    bool operator==(const prefix &other) const
    {
        return value == other.value;
    }
    bool operator<(const prefix &other) const
    {
        if (size != other.size)
            return size < other.size;
        return start_pos > other.start_pos;
    }
};

namespace std
{
    template <>
    struct hash<prefix>
    {
        size_t operator()(const prefix &pref) const
        {
            return hash<string_view>()(pref.value);
        }
    };
}
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
    unordered_set<prefix> prefixes;
    prefixes.reserve(1000000);
    int biggest_prefix = smallest.size();

    for (int max_size = biggest_prefix; max_size; max_size--)
        for (int j = 0; j + max_size <= biggest_prefix; j++)
        {
            prefix temp = {string_view{&smallest.c_str()[j], max_size}, j, max_size};
            if (prefixes.find(temp) == prefixes.end())
                prefixes.insert(move(temp));
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
    prefix answer = *prefixes.begin();
    for (decltype(auto) it : prefixes)
        answer = max(answer, it);
    cout << answer.value << '\n';
}
