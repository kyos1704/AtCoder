#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

long long solve(int k, int s, int t, int x, vector<vector<int>> edge)
{
    vector<vector<vector<int>>> dp;
    dp.resize(k);
    for (int i = 0; i < dp.size(); i++)
    {
        dp[i].resize(edge.size());
        for (int j = 0; j < dp[i].size(); j++)
        {
            dp[i][j].resize(2);
        }
    }

    //初期値
    dp[0][s][x == s] = 1;

    // dp
    for (int i = 0; i < dp.size() - 1; i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
        {
            for (int b = 0; b < 2; b++)
            {
                for (int e = 0; e < edge[j].size(); e++)
                {
                    int eee = edge[j][e];
                    dp[i + 1][eee][(b + (x == eee)) % 2] += dp[i][j][b];
                    dp[i + 1][eee][(b + (x == eee)) % 2] %= 998244353;
                }
            }
        }
    }

    return dp[dp.size() - 1][t][0] % 998244353;
}

int main()
{
    int n, m, k, s, t, x;
    cin >> n >> m >> k >> s >> t >> x;

    s--;
    t--;
    x--;

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
    cout << solve(k + 1, s, t, x, edge) << endl;
}
