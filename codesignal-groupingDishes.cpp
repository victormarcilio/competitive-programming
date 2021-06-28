//https://app.codesignal.com/interview-practice/task/xrFgR63cw7Nch4vXo/solutions
vector<vector<string>> groupingDishes(vector<vector<string>> dishes) {
    map<string, vector<string>> m;
    for(int i = 0; i < dishes.size(); i++)
        for(int j = 1; j < dishes[i].size(); j++)
            m[dishes[i][j]].push_back(dishes[i][0]);
        
    vector<vector<string>> ans;
    for(auto& it : m)
    {
        ans.push_back(vector<string>());
        vector<string>& last = ans.back();
        last.push_back(it.first);
        for(int i = 0; i < it.second.size(); i++)
            last.push_back(it.second[i]);
        if(last.size() < 3)
            ans.pop_back();
    }
    for(int i = 0; i < ans.size(); i++)
        sort(begin(ans[i]) + 1, end(ans[i]));
    return ans;
}
