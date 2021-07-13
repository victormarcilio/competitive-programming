//https://app.codesignal.com/interview-practice/task/Hm98RnqK9Be575yoj/description
bool sumOfTwo(vector<int> a, vector<int> b, int v) {
    set<int> s{begin(a), end(a)};
    for(auto i : b)
        if(s.count(v - i))
            return true;
    return false;
}
