#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

bool solve(map<int, vector<int>> R, map<int, vector<int>> L)
{
    for (const auto &item : L)
    {
        auto l = item.second;
        auto r = R[item.first];
        if (l.size() == 0 || r.size() == 0)
        {
            continue;
        }
        // cout<<item.first<<" "<<l.size()<<" "<<r.size()<<endl;
        int l_max = *max_element(l.begin(), l.end());
        int r_min = *min_element(r.begin(), r.end());
        if (r_min < l_max)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> X;
    vector<int> Y;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        X.push_back(x);
        Y.push_back(y);
    }
    string s;
    cin >> s;

    map<int, vector<int>> R;
    map<int, vector<int>> L;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            L[Y[i]].push_back(X[i]);
        }
        else
        {
            R[Y[i]].push_back(X[i]);
        }
    }

    // cout<<"solve"<<endl;
    if (solve(R, L))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}