#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;

    vector<int> A, B;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        B.push_back(b);
    }

    int use_a, use_b;
    use_a = true;
    use_b = true;
    for (int i = 1; i < n; i++)
    {
        int use_a_n, use_b_n;
        use_a_n = false;
        use_b_n = false;
        if (use_a)
        {
            if (abs(A[i - 1] - A[i]) <= k)
            {
                use_a_n = true;
            }
            if (abs(A[i - 1] - B[i]) <= k)
            {
                use_b_n = true;
            }
        }
        if (use_b)
        {
            if (abs(B[i - 1] - A[i]) <= k)
            {
                use_a_n = true;
            }
            if (abs(B[i - 1] - B[i]) <= k)
            {
                use_b_n = true;
            }
        }
        use_a = use_a_n;
        use_b = use_b_n;
    }
    if (use_a || use_b)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
