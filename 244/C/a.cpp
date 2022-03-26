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
    cin >> n;
    vector<int> used;
    used.resize(2 * n + 2);
    used[0] = 1;
    used[1] = 1;
    cout << 1 << endl
         << flush;

    while (true)
    {
        int m;
        cin >> m;
        if (m == 0)
        {
            return 0;
        }
        used[m] = 1;

        for (int i = 1; i < used.size(); i++)
        {
            if (used[i] != 1)
            {
                cout << i << endl
                     << flush;
                used[i] = 1;
                break;
            }
        }
    }
}
