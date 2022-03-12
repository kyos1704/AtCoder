#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

long long solve(long long x, string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'U')
        {
            x = x / 2;
        }
        if (s[i] == 'R')
        {
            x = x * 2 + 1;
        }
        if (s[i] == 'L')
        {
            x = x * 2;
        }
    }
    return x;
}

string convert(string s)
{
    vector<int> use;
    use.resize(s.size());
    vector<int> u_pos;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == 'U')
        {
            u_pos.push_back(i);
        }
        else if (u_pos.size() != 0)
        {
            int u_pos_last = u_pos[u_pos.size() - 1];
            use[u_pos_last] = -1;
            use[i] = -1;
            u_pos.pop_back();
        }
    }
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (use[i] != -1)
        {
            res += s[i];
        }
    }
    return res;
}

int main()
{
    long long n, x;
    string s;
    cin >> n >> x >> s;

    s = convert(s);
    // cout << s << endl;

    cout << solve(x, s) << endl;
}