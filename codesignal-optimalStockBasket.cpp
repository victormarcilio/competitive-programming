//https://app.codesignal.com/company-challenges/two-sigma/ojbKfrAt7qqMW7pQh
void rec(vector<vector<int>>& stocks, int riskBudget, int& best, int acc = 0, int pos = 0)
{
    if(riskBudget < 0)
        return;
    if(pos == stocks.size())
    {
        best = max(best, acc);
        return;
    }
    if(stocks[pos][0] > 0)
        rec(stocks, riskBudget - stocks[pos][1], best, acc + stocks[pos][0], pos + 1);
    rec(stocks, riskBudget, best, acc, pos + 1);
}

int optimalStockBasket(vector<vector<int>> stocks, int riskBudget) {
    int ans = 0;
    rec(stocks, riskBudget, ans);
    return ans;
}
