#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        unsigned long long k;
        unsigned long long sum = 0;
        cin >> n >> k;
        unsigned long long input;
        vector<unsigned long long> arr;
        for (int j = 0; j < n; j++)
        {
            cin >> input;
            sum += input / k;
            if (input % k != 0)
            {
                arr.push_back(input % k); // save the remainder
            }
        }
        sort(arr.begin(), arr.end(), greater<unsigned long long>{});
        while (arr.size() >= 2)
        {
            if (arr[0] + arr[1] < k)
            {
                break;
            }
            else if (arr[0] + arr.back() >= k)
            {
                sum++;
                arr.pop_back();
                arr.erase(arr.begin());
            }
            else
            {
                arr.pop_back();
            }
        }
        cout << sum << endl;
    }
}