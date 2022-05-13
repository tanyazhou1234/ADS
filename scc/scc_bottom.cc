#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

void ReadGraph(vector<vector<int>> &graph, int vertice, int edge)
{
    int v, u;
    graph.resize(vertice + 1);
    for (int i = 0; i < edge; i++)
    {
        cin >> v >> u;
        graph[v].push_back(u);
    }
}

void show(vector<vector<int>> &graph)
{
    for (int i = 1; i < graph.size(); i++)
    {
        cout << i << ": ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
class SccFinder
{
    vector<bool> vst, in_stack;
    vector<int> lowlink, dfn;
    stack<int> s;
    int current_time;
    priority_queue<int, vector<int>, greater<int>> bottom;

public:
    SccFinder(int vertice)
    {
        vst.resize(vertice + 1, false);
        in_stack.resize(vertice + 1, false);
        lowlink.resize(vertice + 1, -1);
        dfn.resize(vertice + 1, -1);
        current_time = 1;
    }

    void FindSCC(int u, vector<vector<int>> &graph)
    {
        vst[u] = true;
        s.push(u);
        in_stack[u] = true;

        lowlink[u] = current_time;
        dfn[u] = current_time;
        current_time++;

        for (auto v : graph[u])
        {
            if (!vst[v])
            {
                FindSCC(v, graph);
                lowlink[u] = min(lowlink[u], lowlink[v]);
            }
            else if (in_stack[v])
            {
                lowlink[u] = min(lowlink[u], lowlink[v]);
            }
            else
            {
                ;
            }
        }
        if (lowlink[u] == dfn[u])
        {
            int cnt = 0;
            while (s.top() != u)
            {
                int top = s.top();
                lowlink[top] = lowlink[u];
                s.pop();
                in_stack[top] = false;
                bottom.push(top);
                cnt++;
            }
            s.pop();
            in_stack[u] = false;
            if (cnt != 0)
            {
                bottom.push(u);
            }
            else if (!graph[u].size())
            {
                bottom.push(u);
            }
        }
    }
    void show_lowlink(int vertice)
    {
        for (int i = 1; i <= vertice; i++)
        {
            cout << "node " << i << ": lowlink = " << lowlink[i] << endl;
        }
    }
    void show_bottom()
    {
        // cout << "Bottom: " << endl;
        while (!bottom.empty())
        {
            cout << bottom.top() << " ";
            bottom.pop();
        }
        cout << endl;
    }
    inline bool visited(int u)
    {
        return vst[u];
    }
};

int main()
{
    int vertice, edge;
    while (cin >> vertice && vertice != 0)
    {
        // cout << "***new line: ***" << endl;
        cin >> edge;
        vector<vector<int>> graph;
        ReadGraph(graph, vertice, edge);
        // show(graph);

        SccFinder scc(vertice);
        for (int i = 1; i <= vertice; i++)
        {
            if (scc.visited(i))
                continue;
            scc.FindSCC(i, graph);
        }
        // scc.show_lowlink(vertice);
        scc.show_bottom();
    }
}