#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

int count(vector<int> c)
{
    int res = 0;
    for (auto i : c)
    {
        res = res + i;
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> d;
    d.resize(n);
    for (int i = 0; i < n; i++)
    {
        d[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            d[i][j] = (int)1e11;
        }
    }

    vector<pair<int, pair<int, int>>> edge;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        d[a][b] = c;
        d[b][a] = c;
        edge.push_back(make_pair(c, make_pair(min(a, b), max(a, b))));
    }

    //

    vector<vector<int>> next;
    next.resize(n);
    for (int i = 0; i < n; i++)
    {
        next[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            next[i][j] = j;
        }
    }
    vector<vector<int>> check;
    check.resize(n);
    for (int i = 0; i < n; i++)
    {
        check[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            check[i][j] = 0;
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    next[i][j] = next[i][k];
                }
                else if (d[i][k] + d[k][j] == d[i][j])
                {
                    check[j][i] = check[i][j] = -1;
                }
            }
        }
    }

    /*
    cout << "restore route" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            cout << i << " " << j << " next:" << next[i][j] + 1 << " cost:" << d[i][j] + 1 << endl;
        }
    }
    cout << "fin" << endl;
    */

    vector<int> unuse;
    unuse.resize(edge.size());
    int ans = 0;
    for (int i = 0; i < edge.size(); i++)
    {
        auto p = edge[i].second;
        int n = next[p.first][p.second];

        // cout << "start:" << edge[i].second.first + 1 << " end:" << edge[i].second.second + 1 << " next:" << n + 1 << endl;
        if (n != p.second)
        {
            unuse[i] = 1;
        }
        if (check[p.first][p.second] == -1)
        {
            unuse[i] = 1;
        }
    }
    cout << count(unuse) << endl;
}