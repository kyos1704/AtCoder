#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    n++;
    m++;
    vector<int> A, C;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < n + m - 1; i++)
    {
        int c;
        cin >> c;
        C.push_back(c);
    }

    vector<int> B;
    /*
    B[0] = C[0] / A[0];
    C[1] = B[1] * A[0] + B[0] * A[1];
    B[1] = (C[1] - B[0] * A[1]) / A[0];
    C[2] = B[2] * A[0] + B[1] * A[1] + B[0] * A[2];
    B[2] = (C[2] - B[1] * A[1] - B[0] * A[2]) / A[0];
    */
    /*
    C[1] = B[0] * A[1];
    B[0] = C[1] / A[1]
    C[2] = B[1] * A[1] + B[0] * A[2];
    B[1] = (C[2] - B[0] * A[2]) / A[1];
    C[3] = B[2] * A[1] + B[1] * A[2] + B[0] * A[3];
    B[2] = (C[3] - (B[1] * A[2] + B[0] * A[3]) )/ A[1]
    */
    B.resize(m);
    int diff = -1;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] != 0)
        {
            diff = i;
            break;
        }
    }

    for (int i = 0; i < B.size(); i++)
    {
        B[i] = C[i + diff];
        for (int j = 1; j + diff <= A.size(); j++)
        {
            if (i - j >= 0 && i - j < i)
            {
                B[i] -= B[i - j] * A[j + diff];
            }
        }
        B[i] /= A[diff];
    }

    for (int i = 0; i < B.size(); i++)
    {
        cout << B[i];
        if (i + 1 != m)
        {
            cout << " ";
        }
    }
    cout << endl;
}
