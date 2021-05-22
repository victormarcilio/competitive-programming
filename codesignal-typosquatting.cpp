//https://app.codesignal.com/company-challenges/godaddy/PonZ8nXXvbZtMzZAf
int typosquatting(int n, string domain) {
    set<string> memo;
    memo.insert(domain);
    queue<string> q, q2;
    q.push(domain);
    int k = 0;
    int acc = 0;
    while(!q.empty())
    {
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            for(int i = 0; i < front.size() - 1; i++)
            {
                auto temp = front;
                if(temp[i] != '.' && temp[i + 1] != '.')
                {
                    swap(temp[i], temp[i + 1]);
                    if(!memo.count(temp))
                    {
                        memo.insert(temp);
                        acc++;
                        q2.push(temp);
                    }
                }
            }    
        }
        if(acc <= n)
            k++;
        else
            break;
        q = move(q2);
    }
    if(acc <= n)
        return -1;
    return k;
}
