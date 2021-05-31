//https://app.codesignal.com/company-challenges/two-sigma/JFbFHYb3CmnKDFaSQ
vector<vector<int>> serverFarm(vector<int> jobs, int servers) {
    vector<vector<int>> ans(servers);
    priority_queue<pair<int, int>> serv, job;
    for(int i = 0; i < servers; i++)
        serv.push({0, -i});
    for(int i = 0; i < jobs.size(); i++)
        job.push({jobs[i], -i});
    while(!job.empty())
    {
        auto [jobDur, jobInd] = job.top();
        job.pop();
        auto [AvailableTime, serverInd] = serv.top();
        serv.pop();
        ans[-serverInd].push_back(-jobInd);
        serv.push({AvailableTime - jobDur, serverInd});
    }
    return ans;
}
