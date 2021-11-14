#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

class Graph
{
    int V;
    list<int> *l;
public:
    Graph(int v)
    {
        this->V = v;
        l = new list<int>[V + 1];
    }
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    bool isBipartite()
    {
        bool visited[V + 1];
        int colors[V + 1];
        bool ans = true;
        for (int i = 0; i < V + 1; i++)
        {
            visited[i] = false;
        }
        for (int i = 0; i < V + 1; i++)
        {
            colors[i] = -1;
        }
        for (int k = 1; k <= V ; k++)
        {
            if (!visited[k])
            {
                queue<int> q;
                q.push(k);
                colors[k] = 1;
                visited[k] = true;
                while (!q.empty())
                {
                    int x = q.front();
                    q.pop();
                    for (auto node:l[x])
                    {
                        visited[node] = true;
                        if (colors[node] == -1)
                        {
                            colors[node] = 1 - colors[x];
                            q.push(node);
                        }
                        else if (colors[x] == colors[node])
                        {
                            ans = false;
                        }
                    }
                    //if(!ans) break;
                }
            }
            //if(!ans) break;
        }
        return ans;
    }
};

int main()
{
   // freopen("Test.txt", "r", stdin);
    fast_io;
    int T, N, M;
    bool ans = false;
    cin >> T;
    int sc = 0;
    while (T--)
    {
        sc++;
        cin >> N >> M;
        Graph g(N);
        for (int i = 0; i < M; i++)
        {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        }
        ans = g.isBipartite();
        if (!ans)
        {
            cout << "Scenario #" << sc << ":" << endl;
            cout << "Suspicious bugs found!" << endl;
        }
        else
        {
            cout << "Scenario #" << sc << ":" << endl;
            cout << "No suspicious bugs found!" << endl;
        }
    }
    return 0;
}