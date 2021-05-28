//https://app.codesignal.com/company-challenges/datto/NWoHovD8M48E9Diwr
vector<int> incrementalBackups(int lastBackupTime, vector<vector<int>> changes) {
    set<int> ans;
    for(auto & change : changes)
        if(change[0] > lastBackupTime)
            ans.insert(change[1]);
    return {begin(ans), end(ans)};
}
