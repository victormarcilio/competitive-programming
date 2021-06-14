//https://app.codesignal.com/company-challenges/spacex/Go3gMCouFkB7iuLJ6
string packetDescrambler(vector<int> seq, vector<char> fragmentData, int n) {
    map<int, map<char, int>> m;
    double half = n/2.0;
    for(int i = 0; i < seq.size(); i++)    
        m[seq[i]][fragmentData[i]]++;
    
    string ans;
    int last = *max_element(begin(seq), end(seq));
    for(int i = 0; i <= last; i++)
    {        
        bool found = false;        
        for(auto& it : m[i])
        {
            cout << it.first << ':' << it.second << endl;
            if(it.second > half)
            {
                found = true;
                ans += it.first;
                break;
            }
        }
        if(!found)
            return "";        
    }
    return ans.find_first_of('#') == ans.size() - 1 ? ans : "";    
}
