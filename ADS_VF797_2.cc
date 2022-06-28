#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void read_data(vector<int> &a, vector<int> &b)
{
    int n;
    cin >> n;
    int value;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        a.push_back(value);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        b.push_back(value);
    }
}

void show(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    int t; // test case number
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        vector<int> a, b;
        read_data(a, b);

        vector<int> diff;
        bool flag = true;
        for (int j = 0; j < a.size(); j++)
        {
            diff.push_back(a[j] - b[j]);
            if (diff[j] < 0)
            {
                flag = false;
                break;
            }
        }
        // show(a);
        // show(b);
        // show(diff);
        //  cout << "works here" << endl;
        //  cout << diff.size() << endl;
        set<int> st(diff.begin(), diff.end());
        if (flag && st.size() == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            int max_diff = *max_element(diff.begin(), diff.end());
            for (int j = 0; j < diff.size(); j++)
            {
                if (diff[j] != max_diff)
                {
                    if (b[j] != 0)
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}