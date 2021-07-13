//https://app.codesignal.com/interview-practice/task/CfknJzPmdbstXhsoJ/description
bool containsDuplicates(vector<int> a) {
    sort(begin(a), end(a));
    for(int i = 1; i < a.size(); i++)
        if(a[i] == a[i - 1])
            return true;
    return false;
}
