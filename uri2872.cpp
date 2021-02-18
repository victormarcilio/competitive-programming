#include <bits/stdc++.h>
using namespace std;

//Test cases probably has some extra spaces
//Trying to read the packages as full lines gives presentation error

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    int package;
    while (cin >> line)
    {
        vector<int> packages;
        while (cin >> line, line[0] != '0')
        {
            cin >> package;
            packages.push_back(package);
        }
        sort(begin(packages), end(packages));
        for (auto &it : packages)
            cout << "Package " << setw(3) << setfill('0') << it << '\n';
        if (packages.size())
            cout << '\n';
    }
}