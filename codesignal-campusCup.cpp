//https://app.codesignal.com/company-challenges/dropbox/RMJDiTprBf5HQY3oa

map<string, int> schools;

bool f(string const&s1, string const& s2)
{
    if(schools[s1] != schools[s2])
        return schools[s1] > schools[s2];
    return s1 < s2;
}

vector<string> campusCup(vector<string> emails) {
    map<string, int> points;
    for(auto it : emails)
        points[it.substr(it.find('@') + 1)] += 20;
    vector<string> ans;
    for(auto it : points)
    {
        ans.push_back(it.first);
        if(it.second >= 500)
            schools[it.first] = 25;
        else if(it.second >= 300)
            schools[it.first] = 15;
        else if(it.second >= 200)
            schools[it.first] = 8;
        else if(it.second >= 100)
            schools[it.first] = 3;

    }
    sort(begin(ans), end(ans), f);
    return ans;
}

