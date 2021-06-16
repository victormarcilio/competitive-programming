//https://app.codesignal.com/company-challenges/jet/S3doy5C4u5F866CiD
vector<vector<string>> catalogUpdate(vector<vector<string>> catalog, vector<vector<string>> updates) {
    for(int i = 0; i < updates.size(); i++)
    {
        bool found = false;
        for(int j = 0; j < catalog.size(); j++)
            if(catalog[j][0] == updates[i][0])
            {
                catalog[j].push_back(updates[i][1]);
                found = true;
                break;
            }
        if(!found)
            catalog.push_back(updates[i]);
    }
    sort(begin(catalog), end(catalog));
    for(int i = 0; i < catalog.size(); i++)
        sort(catalog[i].begin() + 1, catalog[i].end());
    return catalog;
}
