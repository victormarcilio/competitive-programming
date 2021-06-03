//https://app.codesignal.com/company-challenges/kik/jAWJJKWi2ib9Ywz9n
bool lessthan5(string s)
{
    bool onletter = false;
    int words = 0;
    for(auto c : s)
    {
        if(isalpha(c))
        {
            if(!onletter)
                words++;
            onletter = true;
        }
        else
            onletter = false;
    }
    return words < 5;
}
bool message_has_spam(string message, string spam)
{
    string temp;
    for(int i = 0; i < message.size(); i++)
        if(isalpha(message[i]))
            temp += tolower(message[i]);
        else
        {
            if(temp == spam)
                return true;
            temp = "";
        }
    return temp == spam;
}

vector<string> spamDetection(vector<vector<string>> messages, vector<string> spamSignals) {
    vector<string> ans;
    int less5 = 0;
 
/* criteria 1 */
    for(auto& m : messages)
        less5 += lessthan5(m[0]);
    
    if((double)less5/messages.size() < 0.9)
        ans.push_back("passed");
    else
    {
        int GCD = gcd(less5, messages.size()); 
        ans.push_back("failed: " + to_string(less5/GCD) + '/' + to_string(messages.size()/GCD));
    }
/* criteria 2 */
    map<string, map<string, int>> messages_per_user;
    map<string, int> message_count_per_user;
    for(auto& message : messages)
    {
        message_count_per_user[message[1]]++;
        messages_per_user[message[1]][message[0]]++;
    }
    vector<string> failed;
    for(auto& user : messages_per_user)
    {
        int max_messages = 0;
        for(auto& msg : user.second)
            max_messages = max(max_messages, msg.second);
        if(message_count_per_user[user.first] > 1 && max_messages * 2 > message_count_per_user[user.first])
            failed.push_back(user.first);
    }
    if(failed.empty())
        ans.push_back("passed");
    else
    {
        sort(begin(failed), end(failed), [](string& s1, string& s2) {return stol(s1) < stol(s2);});
        string temp = "failed:";
        for(auto& user: failed)
            temp += " " + user;
        ans.push_back(temp);
    }
    
/*criteria 3*/
    map<string, int> message_freq;
    for(auto &msg :messages)
        message_freq[msg[0]]++;
    int max_freq = 0;
    string failer;
    for(auto & it : message_freq)
        if(it.second > max_freq)
        {
            max_freq = it.second;
            failer = it.first;
        }
    if(max_freq > 1 && max_freq * 2 > messages.size())
        ans.push_back("failed: " + failer);
    else
        ans.push_back("passed");

/*criteria 4*/
    int spammed_messages = 0;
    set<string> spams_found;
    for(auto & msg: messages)
    {
        bool current_spammed = false;
        for(auto & spam : spamSignals)
            if(message_has_spam(msg[0], spam))
            {
                current_spammed = true;
                spams_found.insert(spam);
            }
        spammed_messages += current_spammed;
    }
    if(spammed_messages * 2 > messages.size())
    {
        string temp = "failed:";
        for(auto& spam : spams_found)
            temp += " " + spam;
        ans.push_back(temp);
    }
    else
        ans.push_back("passed");
    return ans;
}
