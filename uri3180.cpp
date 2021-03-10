#include <bits/stdc++.h>
using namespace std;

string beautify(char *st)
{
    int pos = 0;
    int i = 0;
    while (st[i] == ' ')
        i++;
    if (!st[i])
        return "";
    for (; st[i]; i++)
    {
        st[pos++] = st[i];
        while (st[i] == ' ' && st[i + 1] == ' ')
            i++;
    }
    st[pos] = 0;
    if (st[pos - 1] == ' ')
        st[pos - 1] = 0;
    return string(st);
}
char linha[1000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<string, int> mapa;
    int N;
    scanf("%d\n", &N);
    const string sample_end = "***END***";
    string line;

    vector<vector<int>> codes(N);
    vector<unordered_set<int>> has_line(N);
    vector<string> filename;
    for (int i = 0; i < N; i++)
    {
        linha[0] = 0;
        gets(linha);
        filename.push_back(linha);
        while (true)
        {
            linha[0] = 0;
            gets(linha);
            line = beautify(linha);
            if (line.empty())
                continue;
            if (line == sample_end)
                break;
            int &temp = mapa[line];
            if (!temp)
                temp = mapa.size();
            codes[i].push_back(temp);
            has_line[i].insert(temp);
        }
    }
    vector<int> target;
    while (true)
    {
        linha[0] = 0;
        gets(linha);
        line = beautify(linha);
        if (line.empty())
            continue;
        if (line == sample_end)
            break;

        target.push_back(mapa[line]);
    }
    int most = 0;
    vector<string> pirates;
    for (int i = 0; i < target.size() && (int)target.size() - i >= most - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (has_line[j].count(target[i]))
                for (int k = 0; k < codes[j].size(); k++)
                    if (codes[j][k] == target[i])
                    {
                        int inc;
                        for (inc = 1; inc + k < codes[j].size() && inc + i < target.size() &&
                                      codes[j][inc + k] == target[i + inc];)
                            inc++;
                        if (inc > most)
                        {
                            most = inc;
                            pirates.clear();
                            pirates.push_back(filename[j]);
                        }
                        else if (inc == most && pirates.back() != filename[j])
                            pirates.push_back(filename[j]);
                    }
        }
    }
    printf("%d", most);
    for (int i = 0; i < pirates.size(); i++)
        printf(" %s", pirates[i].c_str());
    printf("\n");
}
