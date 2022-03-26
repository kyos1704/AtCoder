#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <climits>
using namespace std;

vector<long long> solve(int n, int m, vector<vector<int>> edge)
{
    vector<long long> s_cost;
    vector<vector<int>> used;
    s_cost.resize(1 << (n));
    for (size_t i = 0; i < s_cost.size(); i++)
    {
        s_cost[i] = INT_MAX / 2;
    }
    used.resize(1 << (n));
    for (size_t i = 0; i < used.size(); i++)
    {
        for (int j = 0; j < 20; j++)
        {
            used[i].push_back(0);
        }
    }

    queue<pair<int, int>> que; //.s,v
    s_cost[0] = 0;
    for (size_t i = 0; i < n; i++)
    {
        s_cost[1 << i] = 1;
        que.push(make_pair(1 << i, i));
    }

    while (!que.empty())
    {
        pair<int, int> p = que.front();
        que.pop();

        int v = p.second;

        for (size_t i = 0; i < edge[v].size(); i++)
        {
            int edge_next = edge[v][i];
            int s_next = p.first ^ (1 << edge_next);
            // cout << bitset<5>(p.first) << " " << edge_next << " " << bitset<5>(s_next) << " cost_now:" << s_cost[p.first] << " cost_next:" << s_cost[s_next] << " edge_used:" << used[s_next][edge_next] << endl;
            if (s_cost[s_next] >= s_cost[p.first] + 1)
            {
                s_cost[s_next] = s_cost[p.first] + 1;
                if (used[s_next][edge_next] == 0)
                {
                    used[s_next][edge_next] = 1;
                    que.push(make_pair(s_next, edge_next));
                }
            }
        }
    }

    return s_cost;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edge;
    edge.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    vector<long long> s_cost = solve(n, m, edge);

    // cout << "solve" << endl;
    long long ans = 0;
    for (int i = 0; i < s_cost.size(); i++)
    {
        ans += s_cost[i];

        // cout << bitset<5>(i) << " " << s_cost[i] << endl;
    }
    cout << ans << endl;
    return 0;
}