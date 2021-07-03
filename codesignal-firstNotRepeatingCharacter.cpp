//https://app.codesignal.com/interview-practice/task/uX5iLwhc6L5ckSyNC/description
char firstNotRepeatingCharacter(string s) {
    vector<int> count(26);
    for(auto c : s)
        count[c - 'a']++;
    for(auto c : s)
        if(count[c - 'a'] == 1)
            return c;
    return '_';
}
