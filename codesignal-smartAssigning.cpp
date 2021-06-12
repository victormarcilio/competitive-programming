//https://app.codesignal.com/company-challenges/asana/vpDXQhiLagoaM27KL
string smartAssigning(vector<string> names, vector<bool> statuses, vector<int> projects, vector<int> tasks) {
    int high = 10000;
    int ans;
    for(int i = 0; i < names.size(); i++)
        if(!statuses[i] && tasks[i] * 100 + projects[i] < high)
        {
            high = tasks[i] * 100 + projects[i];
            ans = i;
        }
    return names[ans];
}
