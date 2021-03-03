#include <bits/stdc++.h>
using namespace std;

struct Present
{
    string name;
    float cost;
    int grade;
    bool operator<(const Present &p2) const
    {
        if (grade != p2.grade)
            return grade > p2.grade;
        if (cost != p2.cost)
            return cost < p2.cost;
        return name < p2.name;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string name;
    int count;
    while (cin >> name >> count)
    {
        vector<Present> presents(count);
        for (int i = 0; i < count; i++)
        {
            cin.ignore();
            getline(cin, presents[i].name);
            cin >> presents[i].cost >> presents[i].grade;
        }
        sort(begin(presents), end(presents));
        cout << "Lista de " << name << '\n';
        for (auto &present : presents)
            cout << present.name << " - R$" << fixed << setprecision(2) << present.cost << '\n';
        cout << '\n';
    }
}
