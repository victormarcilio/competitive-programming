template<typename T>
T exp_mod(T base, T expo, T mod)
{
    T ans = 1;
    while (expo)
    {
        if (expo & 1)
            ans = ans * base % mod;
        expo >>= 1;
        base = base * base % mod;
    }
    return ans;
}

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

    static int different_divisors(const map<long long, int>& m)
    {
        int ans = 1;
        for (const auto& it : m)
            ans *= (it.second + 1);
        return ans;
    }
    int different_divisors(long long val)
    {
        return different_divisors(decompose(val));
    }

    long long sum_of_divisors(const map<long long, int>& m)
    {
        long long ans = 1;
        for (const auto& it : m)
        {
            long long current = 1;
            for (int i = 0; i <= it.second; i++)
                current *= it.first;
            
            ans *= (current - 1)/(it.first - 1);
        }
        return ans;
    }
    long long sum_of_divisors(long long val)
    {
        return sum_of_divisors(decompose(val));
    }
    
    long long sum_of_divisors_mod_K(const map<long long, int>& m, long long K)
    {
        long long ans = 1;
        for (const auto& it : m)
        {
            long long current = 1;
            for (int i = 0; i <= it.second; i++)
                current *= it.first;
            
            ans = (current - 1) / (it.first - 1) % K * ans % K;
        }
        return ans;
    }
    long long sum_of_divisors_mod_K(long long val, long long K)
    {
        return sum_of_divisors_mod_K(decompose(val), K);
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

struct WeightedGraph
{
    using ii = pair<int, int>;
    using vi = vector<int>;
    using vvii = vector<vector<pair<int, int>>>;
    const int INF = 1'000'000'000;
    vvii adjList;
    int V;
    unordered_map<int, vi> djikstra_cache;

    void addEdge(int from, int to, int weight)
    {
		adjList[from].emplace_back(to, weight);
    }
    WeightedGraph(int N) : V{ N + 1}, adjList{N + 1} {}


    int djikstra(int from, int to)
    {
        if (djikstra_cache.find(from) == djikstra_cache.end())
            djikstra_cache[from] = djikstra(from);
        return djikstra_cache[from][to];
    }
    vector<int> djikstra(int from)
    {
        vector<int> distances(V, INF);
        vector<bool> processed(V);
        distances[from] = 0;
        priority_queue<pair<int, int>, vector<ii>, greater<ii>> pq;
        pq.push({ 0, from });
        while (!pq.empty())
        {
            auto [curr_dist, no] = pq.top();
            pq.pop();
            if (processed[no])
                continue;
            processed[no] = true;
            for (auto [dest, edge_dist] : adjList[no])
            {
                int new_dist = curr_dist + edge_dist;
                if (new_dist < distances[dest])
                {
                    //if (processed[dest])
                    //    throw "Negative cycle!\n";
                    distances[dest] = new_dist;
                    pq.push({new_dist, dest});
                }
            }
        }
        return distances;
    }
};
