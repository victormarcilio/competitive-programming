//https://app.codesignal.com/interview-practice/task/JAhrxhDQDLDDA3NXe/description
void rec(set<string>& s, vector<int>&a, int sum, vector<int> elements, int acc = 0, int ind = 0)
{
    if(acc == sum)
    {
        sort(begin(elements), end(elements));
        string ans = "(" + to_string(elements[0]);
        for(int i = 1; i < elements.size(); i++)
            ans += ' ' + to_string(elements[i]);
        ans += ")";
        s.insert(ans);
        return;
    }
    if(ind >= a.size())
        return;
    rec(s, a, sum, elements, acc, ind + 1);
    if(a[ind] + acc <= sum)
    {
        elements.push_back(a[ind]);
        rec(s, a, sum, elements, acc + a[ind], ind);
    }
}

string combinationSum(vector<int> a, int sum) {
    set<string> s;
    vector<int> elements;
    rec(s, a, sum, elements);
    string ans;
    for(const auto& it : s)
        ans += it;
    return ans.empty()? "Empty" : ans;
}
