struct Primo {
    //Raiz do valor maximo no problema: Problema diz até 10^8, LIM deve ser 10^4
    static const int LIM = 10'007;
    bitset<LIM> b;
    vector<int> primos;

    Primo()
    {
        b.set();
        primos = { 2 };
        for (int i = 4; i < LIM; i += 2)
            b[i] = false;
        for (long long j = 3; j < LIM; j += 2)
            if (b[j])
            {
                for (long long i = j * j, inc = j + j; i < LIM; i += inc)
                    b[i] = false;
                primos.push_back(j);
            }
    }

    map<long long, int> decompose(long long val)
    {
        map<long long, int> ans;
        for (auto p : primos)
            if (val % p == 0)
            {
                int expo = 0;
                while (val % p == 0)
                {
                    expo++;
                    val /= p;
                }
                ans[p] = expo;
                if (val == 1)
                    break;
            }
        if (val > 1)
            ans[val] = 1;
        return ans;
    }
};

struct UnionFind
{
    vector<int> group;
    vector<int> sizes;
    int N;
    UnionFind(int n) : N{ n + 1 }
    {
        group = vector<int>(N);
        sizes = vector<int>(N);
        iota(begin(group), end(group), 0);
        fill(begin(sizes), end(sizes), 1);
    }

    int get_group_number(int ind)
    {
        if (group[ind] == ind)
            return ind;
        return group[ind] = get_group_number(group[ind]);
    }
    //returns true if a merge happened
    bool merge(int ind1, int ind2)
    {
        int group1 = get_group_number(ind1);
        int group2 = get_group_number(ind2);
        if (group1 != group2)
        {
            if (sizes[group1] > sizes[group2])
            {
                sizes[group1] += sizes[group2];
                group[group2] = group[group1];
            }
            else
            {
                sizes[group2] += sizes[group1];
                group[group1] = group[group2];
            }
        }
        return group1 != group2;
    }

    int get_group_size(int ind)
    {
        return sizes[get_group_number(ind)];
    }
    bool is_same_group(int x, int y)
    {
        return get_group_number(x) == get_group_number(y);
    }
};