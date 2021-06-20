//https://app.codesignal.com/company-challenges/asana/igEBmm3ykm4zwYkcQ
int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct Date
{
    int sday;
    int day;
    int month;
    int year;
    
    bool operator< (const Date& d) const
    {
        if (year != d.year)
            return year < d.year;
        if(month != d.month)
            return month < d.month;
        return day < d.day;
    }
    
    void operator++()
    {
        day++;
        sday++;
        if(sday == 7)
            sday = 0;
        if(day > months[month])
        {
            day = 1;
            month++;
            if(month == 13)
            {
                month = 1;
                year++;
                if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
                    months[2] = 29;
                else
                    months[2] = 28;
            }
        }
    }
    void operator--()
    {
        day--;
        sday--;
        if(sday < 0)
            sday = 6;
        if(day == 0)
        {
            month--;
            if(month == 0)
            {
                year--;
                month = 12;
                if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
                    months[2] = 29;
                else
                    months[2] = 28;
            } 
            day = months[month];
        }
    }
};

vector<string> recurringTask(string firstDate, int k, vector<string> daysOfTheWeek, int n) {
    Date param;
    char slash;
    istringstream iss(firstDate);
    iss >> param.day >> slash >> param.month >> slash >> param.year;
    param.sday = 0;
    Date today{0, 20, 6, 2021}; //Sunday
    while(today < param)
        ++today;
    while(param < today)
        --today;
    map<string, int> m {{"Sunday", 0}, {"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}, {"Saturday", 6}};
    vector<int> chosen(7);
    vector<int> count(7);
    for(auto s: daysOfTheWeek)
        chosen[m[s]] = 1;
    vector<string> answer;
    while(answer.size() < n)
    {
        cout << today.day << ' ' << today.month << ' ' << today.year << endl;
        if(chosen[today.sday])
        {
            if(!count[today.sday])
            {
                ostringstream oss;
                oss << setfill('0') << setw(2) << today.day << "/" << setw(2) << today.month << "/" << today.year;  
                answer.push_back(oss.str());
                count[today.sday] = k - 1;
            }
            else
                count[today.sday]--;
        }
        ++today;
    }
    return answer;
}
