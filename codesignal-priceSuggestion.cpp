//https://app.codesignal.com/company-challenges/thumbtack/q2JebsccgXd9wmELw
vector<int> priceSuggestion(vector<int> contractData) {
    if(contractData.empty())
        return {};
    sort(begin(contractData), end(contractData));
    int s = contractData.size() >> 1;
    vector<int> left{contractData.begin(), contractData.begin() + s};
    vector<int> right{contractData.begin() + s, contractData.end()};
    
    if(s & 1)
        return {left[s >> 1], right[s >> 1]};
    else
        return{(int)floor(0.5*(left[s >> 1] + left[(s >> 1) - 1])),
        (int)ceil(0.5*(right[s >> 1] + right[(s >> 1) - 1]))};   
    
}
