//https://app.codesignal.com/company-challenges/freedomfinancialnetwork/T7SeWcY9ACEPQpdey
struct Date
{
    int month;
    int year;
    
    void operator++(int)
    {
        if(++month == 13)
        {
            month = 1;
            year++;
        }
    }  
    void operator--(int)
    {
        if(!--month)
        {
            month = 12;
            year--;
        }
    }
    bool operator< (const Date& d2) const
    {
        if(year != d2.year)
            return year < d2.year;
        return month < d2.month;
    }
    
    bool operator<= (const Date& d2) const
    {
        return year == d2.year && month == d2.month || *this < d2;
    }
    
};

vector<string> creditPayments(int a, int b, string startDate, string endDate, vector<string> history) {
    vector<string> ans;
    Date start, end;
    start.month = stoi(startDate.substr(0, 2));
    start.year = stoi(startDate.substr(3));
    end.month = stoi(endDate.substr(0, 2));
    end.year = stoi(endDate.substr(3));
    
    map<Date, pair<int, bool>> payments; // (month, year) => (payment, inday)
    Date temp = start;
    for(int i = 0; i < 3; i++)
    {
        temp--;        
        payments[temp] = {b, true};
    }
    for(auto& s: history)
    {
        istringstream iss(s);
        string amount;
        iss >> amount;
        int iamount = stoi(amount.substr(1));
        for(int i = 0; i < 4; i++)
            iss >> amount;
        iss = istringstream(amount);
        char c;
        int month, day, year;
        iss >> month >> c >> day >> c >> year;
        payments[{month, year}] = {iamount, day <= 15};
    }
    int incs = 0;
    while(start <= end)
    {
        Date current = start;
        start++;
        incs++;
        if(incs < 3)
        {
            ans.push_back("Leave as it is, " + to_string(b) + ".");
            continue;
        }
        Date oneb4 = current;
        oneb4--;
        Date twob4 = oneb4;
        twob4--;
        
        if(payments[current].first + payments[oneb4].first + payments[twob4].first  < 3 * b ||
        !payments[current].second && !payments[oneb4].second && !payments[twob4].second
        || !payments[oneb4].first && !payments[current].first)
        {
            b += int(0.5 + a/100.);
            ans.push_back("Add one year, " + to_string(b) + ".");
        }
        else if(payments[current].first >= 2 * b && payments[oneb4].first >= 2 * b && payments[twob4].first >= 2 * b)
        {
            b -= int(0.5 + a/100.);
            ans.push_back("Remove one year, " + to_string(b) + ".");
        }
        else
            ans.push_back("Leave as it is, " + to_string(b) + ".");      
    } 
    return ans;
}
