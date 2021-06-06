//https://app.codesignal.com/company-challenges/freedomfinancialnetwork/GvruWwC39wkDK7mhf
struct st
{
    double val;
    int time;
    string name;
    
    bool operator<(const st& st2) const
    {
        if(val != st2.val)
            return val < st2.val;
        if(time != st2.time)
            return time < st2.time;
        return name > st2.name;
    }  
};
vector<string> salesLeadsScore(vector<string> names, vector<int> time, vector<int> netValue, vector<bool> isOnVacation) {
    priority_queue<st> pq;
    for(int i = 0; i < isOnVacation.size(); i++)
        if(!isOnVacation[i])
            pq.push({netValue[i]*time[i]/365.0, time[i], names[i]});
    vector<string> ans;
    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        ans.push_back(top.name);
    }
    return ans;
}
