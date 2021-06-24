//https://app.codesignal.com/company-challenges/thumbtack/fEnagAYuHR3msAYfK
struct pro
{
    string name;
    int distance;
    int travel;
    int score;
    int matching;
    pro(string name, int d, int t): name{name}, distance{d}, travel{t}
    {
        matching = distance <= travel;
        if(matching)
            score = distance;
        else
            score = distance - travel;
    }
    
    bool operator<(const pro& p2) const
    {
        if(matching != p2.matching)
            return matching > p2.matching;
        if(score != p2.score)
            return score < p2.score;
        return name < p2.name;
    }
};

vector<string> requestMatching(vector<string> pros, vector<int> distances, vector<int> travelPreferences) {
    vector<pro> v;
    for(int i = 0; i < pros.size(); i++)
        v.push_back({pros[i], distances[i], travelPreferences[i]});
    sort(begin(v), end(v));
    vector<string> ans;
    for(int i = 0; i < min(5, (int)v.size()); i++)
        ans.push_back(v[i].name);
    return ans;
}
