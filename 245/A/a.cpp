#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

bool solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a < c)
    {
        return true;
    }
    else if (a > c)
    {
        return false;
    }
    else if (b <= d)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    if (solve())
    {
        cout << "Takahashi" << endl;
    }
    else
    {
        cout << "Aoki" << endl;
    }
}