//https://app.codesignal.com/challenge/pRuhLib5DdetsY4E7
bool isAdmissibleOverpayment(vector<double> prices, vector<string> notes, double x) {
    string dif;
    double val;
    char c;
    
    for(int i = 0; i < prices.size(); i++)
    {    
        istringstream iss(notes[i]);
        iss >> val >> c >> dif;
        if(dif[0] == 'S')
            continue;
        if(dif[0] == 'h')
            x -= prices[i]*val/(val + 100);
        else
            x += prices[i]/(100 - val)*val;
    }
    return x >= 0;    
}
