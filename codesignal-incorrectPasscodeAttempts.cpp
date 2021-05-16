//https://app.codesignal.com/company-challenges/dropbox/ffibMFaS7mzKZkAE3
bool incorrectPasscodeAttempts(string passcode, vector<string> attempts) {
    int c = 0;
    for(auto i : attempts)
        if(i != passcode)
        {
            c++;
            if(c == 10)
                return true;
        }
        else
            c = 0;
    return false;
}
