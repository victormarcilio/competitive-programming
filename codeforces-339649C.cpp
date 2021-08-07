//https://codeforces.com/group/nituVTsHQX/contest/339649/problem/C
#include<bits/stdc++.h>

using namespace std;

struct book
{
    int D, T;
    multiset<int> normal, triple, doubly;
    long long total = 0;

    void check()
    {
        while(triple.size() > T)
        {
            doubly.insert(*triple.begin());
            total -= *triple.begin();
            triple.erase(triple.begin());
        }
        while(doubly.size() > D)
        {
            normal.insert(*doubly.begin());
            total -= *doubly.begin();
            doubly.erase(doubly.begin());
        }
        while(triple.size() < T)
        {
            if(!doubly.empty())
            {
                auto last = doubly.end();
                last--;
                triple.insert(*last);
                total += *last;
                doubly.erase(last);
            }
            else if(!normal.empty())
            {
                auto last = normal.end();
                last--;
                triple.insert(*last);
                total += *last * 2;
                normal.erase(last);
            }
            else
                break;
        }
        while(doubly.size() < D)
        {
            if(!normal.empty())
            {
                auto last = normal.end();
                last--;
                doubly.insert(*last);
                total += *last;
                normal.erase(last);
            }
            else
                break;
        }
        bool changed = true;
        while(changed)
        {
            changed = false;
            if(!normal.empty() && !doubly.empty() && *normal.rbegin() > *doubly.begin())
            {
                changed = true;
                total += *normal.rbegin();
                total -= *doubly.begin();
                normal.insert(*doubly.begin());
                doubly.insert(*normal.rbegin());
                normal.erase(--normal.end());
                doubly.erase(--doubly.end());
            }
            if(!triple.empty() && !doubly.empty() && *doubly.rbegin() > *triple.begin())
            {
                changed = true;
                total += *doubly.rbegin();
                total -= *triple.begin();
                doubly.insert(*triple.begin());
                triple.insert(*doubly.rbegin());
                doubly.erase(--doubly.end());
                triple.erase(--triple.end());
            }

            if(!triple.empty() && !normal.empty() && *normal.rbegin() > *triple.begin())
            {
                changed = true;
                total += *normal.rbegin() * 2;
                total -= *triple.begin() * 2;
                normal.insert(*triple.begin());
                triple.insert(*normal.rbegin());
                normal.erase(--normal.end());
                triple.erase(--triple.end());
            }
        }
    }

    void one_plus(int x)
    {
        triple.insert(x);
        total += 3 * x;
        check();
    }
    
    void one_minus(int x)
    {
        if(normal.find(x) != normal.end())
        {
            total -= x;
            normal.erase(normal.find(x));
        }
        else if(doubly.find(x) != doubly.end())
        {
            total -= 2 * x;
            doubly.erase(doubly.find(x));
        }
        else
        {
            total -= 3 * x;
            triple.erase(triple.find(x));
        }
        check();
    }

    void two_minus()
    {
        D--;
        check();
    }

    void two_plus()
    {
        D++;
        check();
    }

    void three_minus()
    {
        T--;
        check();
    }

    void three_plus()
    {
        T++;
        check();
    }
};

int main()
{
    int n, q, d, t, x;
    book b;
    
    cin >> n >> q >> b.D >> b.T;

    for(int i = 0; i < n; i++)
    {
        cin >> x;
        b.normal.insert(x);
        b.total += x;
    }
    b.check();
    cout << b.total << '\n';

    int opc;
    char c;
    for(int i = 0; i < q; i++)
    {
        cin >> opc >> c;
        if(opc == 1)
        {
            cin >> x;
            if(c == '+')
                b.one_plus(x);
            else
                b.one_minus(x);
        }
        else if(opc == 2)
        {
            if(c == '+')
                b.two_plus();
            else
                b.two_minus();
        }
        else
        {
            if(c == '+')
                b.three_plus();
            else
                b.three_minus();
        }
        cout << b.total << '\n';
    }

}