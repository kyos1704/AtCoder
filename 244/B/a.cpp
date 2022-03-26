#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    string t;
    cin >> n >> t;

    int x = 0, y = 0;

    vector<pair<int, int>> v{
        make_pair(1, 0),
        make_pair(0, -1),
        make_pair(-1, 0),
        make_pair(0, 1),
    };
    int vi = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == 'S')
        {
            x += v[vi].first;
            y += v[vi].second;
        }
        if (t[i] == 'R')
        {
            vi++;
            vi = vi % 4;
        }
    }
    cout << x << " " << y << endl;
}
