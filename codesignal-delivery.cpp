//https://app.codesignal.com/company-challenges/instacart/xrpDSPv7GzBXB6Mpd
vector<bool> delivery(vector<int> order, vector<vector<int>> shoppers) {
    vector<bool> ans;
    for(auto& shopper : shoppers)
    {
        double total = (shopper[0] + order[0])/(double)shopper[1] + shopper[2];
        ans.push_back(total >= order[1] && total <= order[1] + order[2]);
    }
    return ans;
}
