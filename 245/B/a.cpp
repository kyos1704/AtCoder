#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

bool contains(vector<int> A, int a)
{
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == a)
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
    vector<int> A;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < 3000; i++)
    {
        if (contains(A, i))
        {
            continue;
        }
        cout << i << endl;
        return 0;
    }
}
