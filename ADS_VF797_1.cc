#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t, n, h1, h2, h3; // case number, input & output
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        if (n % 3 == 0)
        {
            h3 = n / 3 - 1;
            h2 = n / 3;
            h1 = n / 3 + 1;
        }
        else if (n % 3 == 1)
        {
            h3 = n / 3 - 1;
            h2 = n / 3;
            h1 = n / 3 + 2;
        }
        else
        {
            h3 = n / 3 - 1;
            h2 = n / 3 + 1;
            h1 = n / 3 + 2;
        }

        cout << h2 << " " << h1 << " " << h3 << endl;
    }
}