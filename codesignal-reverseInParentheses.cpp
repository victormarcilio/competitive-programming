//https://app.codesignal.com/arcade/intro/level-3/9DgaPsE2a7M6M2Hu6
string reverseInParentheses(string inputString) {
    auto close = inputString.find_first_of(')');
    while(close != string::npos)
    {
        auto open = close - 1;
        while(inputString[open] != '(')
            open--;
        int i = open + 1;
        int j = close - 1;
        while(i < j)
        {
            swap(inputString[i], inputString[j]);
            i++;
            j--;
        }
        inputString.erase(close, 1);
        inputString.erase(open, 1);        
        close = inputString.find_first_of(')');        
    }
    return inputString;
}
