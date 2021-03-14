#include<bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int O, D, K, proibido;
    while(scanf("%d %d %d", &O, &D, &K), O)
    {
        bitset<100001> visitados;
        for(int i = 0; i < K; i++)
        {
            scanf("%d", &proibido);
            visitados[proibido] = 1;
        }
        queue<pair<int, int>> q;
        q.push({O, 0});
        bool achou = false;
        while(!q.empty())
        {
            auto front = q.front();
            int current = front.first;
            int level = front.second;
            q.pop();
            if(current== D)
            {
                achou = true;
                printf("%d\n", level);
                break;
            }
            if(!(current & 1) && !visitados[current >> 1])
            {
                q.push({current >> 1, level + 1});
                visitados[current >> 1] = 1;
            }
            if(current > 1 && !visitados[current - 1])
            {
                q.push({current - 1, level + 1});
                visitados[current - 1] = 1;
            }
            if(current < 100000 && !visitados[current + 1])
            {
                q.push({current + 1, level + 1});
                visitados[current + 1] = 1;
            }
            if(current * 2 <= 100000 && !visitados[current * 2])
            {
                q.push({current * 2, level + 1});
                visitados[current * 2] = 1;
            }
            if(current * 3 <= 100000 && !visitados[current * 3])
            {
                q.push({current * 3, level + 1});
                visitados[current * 3] = 1;
            }
        }
        if(!achou)
            puts("-1");
    }
}
