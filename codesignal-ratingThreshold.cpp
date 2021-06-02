//https://app.codesignal.com/company-challenges/thumbtack/eF82g2XJdkWbeWYSr
vector<int> ratingThreshold(double threshold, vector<vector<int>> ratings) {
    vector<int> ans;
    for(int i = 0; i < ratings.size(); i++)
        if(accumulate(begin(ratings[i]), end(ratings[i]), 0.0)/ratings[i].size() < threshold)
            ans.push_back(i);
    return ans;
}
