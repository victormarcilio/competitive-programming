//https://app.codesignal.com/company-challenges/godaddy/RjJwsTCiF663krgSP
vector<string> domainType(vector<string> domains) {
    map<string, string> m {{"com", "commercial"}, {"net", "network"}, {"info", "information"}, {"org", "organization"}};
    vector<string> ans;
    for(auto it : domains)
        ans.push_back(m[it.substr(1 + it.find_last_of('.'))]);
    return ans;
}
