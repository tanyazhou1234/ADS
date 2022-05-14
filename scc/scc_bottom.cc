#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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

public:
    SccFinder(int vertice)
    {
        vst.resize(vertice + 1, false);
        in_stack.resize(vertice + 1, false);
        lowlink.resize(vertice + 1, -1);
        dfn.resize(vertice + 1, -1);
        current_time = 1;
    }

    void show_bottom(vector<vector<int>> &graph)
    {
        vector<int> bottom;

        for (int u = 1; u < graph.size(); u++)
        {
            bool is_bottom = true;
            for (int i = 0; i < graph[u].size(); i++)
            {
                int v = graph[u][i];
                // cout << u << " " << v << endl;
                if (lowlink[u] != lowlink[v])
                {
                    is_bottom = false;
                    // cout << "here" << endl;
                    break;
                }
            }
            if (is_bottom)
            {
                bottom.push_back(u);
            }
        }
        for (int i = 0; i < bottom.size(); i++)
        {
            cout << bottom[i] << " ";
        }
        cout << endl;
    }

    void FindSCC(int u, vector<vector<int>> &graph)
    {
        vst[u] = true;
        s.push(u);
        in_stack[u] = true;

        lowlink[u] = current_time;
        dfn[u] = current_time;
        current_time++;

        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
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
            }
            s.pop();
            in_stack[u] = false;
        }
    }
    void show_lowlink(int vertice)
    {
        for (int i = 1; i <= vertice; i++)
        {
            cout << "node " << i << ": lowlink = " << lowlink[i] << endl;
        }
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
        scc.show_bottom(graph);
    }
}