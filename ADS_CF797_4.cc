#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int t;
    cin >> t; // test case number

    for (int t_num = 0; t_num < t; t_num++)
    {
        int n, k;
        cin >> n >> k;

        vector<int> s;
        char input;
        for (int i = 0; i < k; i++)
        {
            cin >> input;
            if (input == 'B')
            {
                s.push_back(1);
            }
            else
            {
                s.push_back(0);
            }
        }
        int max_b = accumulate(s.begin(), s.begin() + k, 0); // sum
        int sum_b = max_b;
        int cur;
        for (int i = k; i < n; i++)
        {
            // inut
            cin >> input;
            if (input == 'B')
            {
                s.push_back(1);
            }
            else
            {
                s.push_back(0);
            }
            // jduge
            if (max_b < k)
            {
                cur = sum_b - s[i - k] + s[i]; // sum
                sum_b = cur;
                if (cur > max_b)
                {
                    max_b = cur;
                }
            }
        }
        if (max_b >= k)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << k - max_b << endl;
        }
    }
}
