//https://app.codesignal.com/interview-practice/task/3PcnSKuRkqzp8F6BN/description
bool areFollowingPatterns(vector<string> strings, vector<string> patterns) {
    unordered_map<string, string> m, m2;
    for(int i = 0; i < strings.size(); i++)
    {
        m[strings[i]] = patterns[i];
        m2[patterns[i]] = strings[i];
    }
    for(int i = 0; i < strings.size(); i++)
        if(m[strings[i]] != patterns[i] || m2[patterns[i]] != strings[i])
            return false;
    
    
    return true;
}
