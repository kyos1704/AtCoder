#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, b, c, x;
    cin >> a >> b >> c >> x;

    if (x <= a)
    {
        cout << setprecision(10) << 1.0 << endl;
    }
    else if (x <= b)
    {
        cout << setprecision(10)
             << double(c) / (double(b - a)) << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}