#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

bool solve()
{
    char s1, s2, s3;
    char t1, t2, t3;
    cin >> s1 >> s2 >> s3 >> t1 >> t2 >> t3;

    if (s1 == t1 && s2 == t2 && s3 == t3)
    {
        return true;
    }
    if (s2 == t1 && s3 == t2 && s1 == t3)
    {
        return true;
    }
    if (s3 == t1 && s1 == t2 && s2 == t3)
    {
        return true;
    }
    return false;
}

int main()
{
    if (solve())
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
