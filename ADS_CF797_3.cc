#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void read_data(queue<int> &s, queue<int> &f)
{
    int n, value;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        s.push(value); // start time
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        f.push(value); // finished time
    }
}

int main()
{
    int t;
    cin >> t;
    queue<int> st; // start time
    queue<int> fi; // finish time
    for (int i = 0; i < t; i++)
    {
        read_data(st, fi);
        int start = st.front();
        st.pop();
        int finish = fi.front();
        fi.pop();
        vector<int> duration;
        duration.push_back(finish - start);
        while (!st.empty())
        {
            int next = st.front();
            st.pop();
            if (next > finish)
            {
                start = next;
            }
            else
            {
                start = finish;
            }
            finish = fi.front();
            fi.pop();
            duration.push_back(finish - start);
        }
        // output
        // cout << "out:" << endl;
        for (int j = 0; j < duration.size(); j++)
        {
            cout << duration[j] << " ";
        }
        cout << endl;
    }
}