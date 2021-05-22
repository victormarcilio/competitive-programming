//https://app.codesignal.com/company-challenges/freedomfinancialnetwork/dkMAufMxQC9wx8igS
double coverDebts(int s, vector<int> debts, vector<int> interests) {
    priority_queue<pair<double, double>> pq, aux;
    for(int i = 0; i < debts.size(); i++)
        pq.push({interests[i]/100., debts[i]});
    double ans = 0;
    double monthly = s*0.1;
    while(!pq.empty())
    {
        double current = monthly;
        while(current > 0 && !pq.empty())
        {
            auto[juros, divida] = pq.top();    
            pq.pop();
            if(divida > current)
            {
                pq.push({juros, divida - current});
                ans += current;
                break;
            }
            current -= divida;
            ans += divida;
        }
        while(!pq.empty())
        {
            auto[juros, divida] = pq.top();
            aux.push({juros, divida *(1 + juros)});
            pq.pop();
        }
        pq = move(aux);
    }
    return ans;
}
