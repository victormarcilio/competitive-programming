//https://app.codesignal.com/company-challenges/instacart/46cSk3fYxmzAs8dPJ
bool deliveryFee(vector<int> intervals, vector<int> fees, vector<vector<int>> deliveries) {
    double val;
    vector<int> interval_deliveries(intervals.size());
    intervals.push_back(25);
    for(int i = 0; i < deliveries.size(); i++)
        for(int j = 0; j < fees.size(); j++)
            if(deliveries[i][0] >= intervals[j] && deliveries[i][0] < intervals[j + 1])
            {
                interval_deliveries[j]++;
                break;
            }
    double ratio = (double)fees[0]/interval_deliveries[0];
    for(int i = 1; i < fees.size(); i++)
        if((double)fees[i]/interval_deliveries[i] != ratio)
            return false;
    return true;
}
