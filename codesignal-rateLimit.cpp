//https://app.codesignal.com/company-challenges/kik/tipc5PdYqJDo7j7p3
void resetMap(map<int, int>& m, int startingAllowance)
{
    for(auto& it : m)
        it.second = startingAllowance;
}

vector<int> rateLimit(vector<vector<int>> sentBatches, vector<vector<int>> receivedMessages, int startingAllowance) {
    map<int, int> remaining;
    for(int i = 0; i < sentBatches.size(); i++)
        for(int j = 1; j < sentBatches[i].size(); j++)
            remaining[sentBatches[i][j]] = startingAllowance;
    
    vector<int> ans;
    
    int received = 0;
    int batch = 0;
    if(sentBatches.empty())
        return {};
    int current_day = sentBatches[0][0];
    if(!receivedMessages.empty())
        current_day = min(current_day, receivedMessages[0][0]);
    current_day /= 86400;
    int old_day;
    while(received < receivedMessages.size() && batch < sentBatches.size())
    {
        old_day = current_day;
        if(receivedMessages[received][0] <= sentBatches[batch][0])
        {
            current_day = receivedMessages[received][0] / 86400;
            if(current_day != old_day)
                resetMap(remaining, startingAllowance);
            for(int i = 1; i < receivedMessages[received].size(); i++)
                remaining[receivedMessages[received][i]]++;
            received++;
        }
        else
        {
            current_day = sentBatches[batch][0] / 86400;
            if(current_day != old_day)
                resetMap(remaining, startingAllowance);
            bool possible = true;
            for(int i = 1; i < sentBatches[batch].size(); i++)
                if(remaining[sentBatches[batch][i]] < 1)
                {
                    possible = false;
                    break;
                }
            if(possible)
            {
                for(int i = 1; i < sentBatches[batch].size(); i++)
                    remaining[sentBatches[batch][i]]--;
            }
            else
                ans.push_back(batch);
            batch++;
        }
    }
    while(batch < sentBatches.size())
    {
        old_day = current_day;
        current_day = sentBatches[batch][0] / 86400;
            if(current_day != old_day)
                resetMap(remaining, startingAllowance);
        bool possible = true;
            for(int i = 1; i < sentBatches[batch].size(); i++)
                if(remaining[sentBatches[batch][i]] < 1)
                {
                    possible = false;
                    break;
                }
            if(possible)
            {
                for(int i = 1; i < sentBatches[batch].size(); i++)
                    remaining[sentBatches[batch][i]]--;
            }
            else
                ans.push_back(batch);
            batch++;
    }
    return ans;
}
