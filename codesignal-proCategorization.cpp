//https://app.codesignal.com/company-challenges/thumbtack/ctLXa98xZc3YYGXet
vector<vector<vector<string>>> proCategorization(vector<string> pros, vector<vector<string>> preferences) {
    map<string, vector<string>> skill_ppl;
    for(int i = 0; i < pros.size(); i++)
        for(int j = 0; j < preferences[i].size(); j++)
            skill_ppl[preferences[i][j]].push_back(pros[i]);
    vector<vector<vector<string>>> ans;
    for(auto& it : skill_ppl)
    {
        sort(it.second.begin(), it.second.end());
        ans.push_back({{it.first}, {it.second.begin(), it.second.end()}});
    }
    return ans;
}
