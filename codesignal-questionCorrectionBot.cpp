// https://app.codesignal.com/company-challenges/quora/sEStnM9dD9euiHWz6
string questionCorrectionBot(string question) {
    string ans;
    while(question.back() == ' ')
        question.pop_back();
    int i = question.find_first_not_of(' ');
    ans += toupper(question[i]);
    for(i++; i < question.size(); i++)
        if(question[i] == ' ' )
        {
            if(ans.back() != ' ')
                ans += ' ';
        }
        else if(question[i] == ',')
        {
            while(ans.back() == ' ')
                ans.pop_back();
            ans += ", ";
        }
        else if(question[i] == '?')
            break;
        else
            ans += question[i];
    ans += '?';
    return ans;
}
