#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

vector<pair<int, int>> input(int n)
{
    vector<int> res1;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        res1.push_back(tmp);
    }
    vector<int> res2;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        res2.push_back(tmp);
    }

    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++)
    {
        res.push_back(make_pair(res1[i], res2[i]));
    }
    return res;
}

void multiset_int_output(multiset<int> s)
{
    cout << "s:";
    for (auto itr = s.begin(); itr != s.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
}

bool solve(vector<pair<string, pair<int, int>>> list)
{
    multiset<int> s;
    for (int i = 0; i < list.size(); i++)
    {
        // multiset_int_output(s);
        // cout << list[i].first << " " << list[i].second.first << " " << list[i].second.second << endl;
        if (list[i].first == "c")
        {
            auto it = s.lower_bound(list[i].second.second);
            if (it == s.end())
            {
                return false;
            }
            s.erase(it);
        }
        else
        {
            s.insert(list[i].second.second);
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> c = input(n);
    vector<pair<int, int>> h = input(m);

    auto op = [](pair<int, int> a, pair<int, int> b) -> int
    {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first < b.first;
    };

    vector<pair<string, pair<int, int>>> ch;
    for (int i = 0; i < c.size(); i++)
    {
        ch.push_back(make_pair("c", c[i]));
    }
    for (int i = 0; i < h.size(); i++)
    {
        ch.push_back(make_pair("h", h[i]));
    }

    auto sort_op =
        [](pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) -> int
    {
        if(a.second.first!=b.second.first){
            return a.second.first > b.second.first;
        }else if(a.second.second!=b.second.second){
            return a.second.second > b.second.second;
        }else{
            return a.first == "h" && b.first != "h";
        } };

    sort(ch.begin(), ch.end(), sort_op);

    if (solve(ch))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
