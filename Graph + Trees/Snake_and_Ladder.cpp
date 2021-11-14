#include<bits/stdc++.h>
using namespace std;

/****************************/

map<int, int> mp;

int BFS()
{
    bool visited[101];
    memset(visited, false, sizeof(visited));

    queue<int> que;
    que.push(1);
    visited[1] = true;

    int steps = 0;
    while (!que.empty())
    {
        int n = que.size();

        for (int i = 0; i < n; i++)
        {
            int curr = que.front();
            que.pop();
            if (curr == 100)
                return steps;
            for (int i = 1; i <= 6; i++)
            {
                if (curr + i <= 100)
                {
                    if (mp.count(curr + i) == 0)
                    {
                        if (!visited[curr + i])
                        {
                            visited[curr + i] = true;
                            que.push(curr + i);
                        }
                    }
                    else
                    {
                        if (!visited[mp[curr + i]])
                        {
                            visited[mp[curr + i]] = true;
                            que.push(mp[curr + i]);
                        }
                    }
                }
            }
        }
        steps++;
    }
    return -1;
}

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B)
{
    mp.clear();
    for (auto &x : A)
    {
        mp[x[0]] = x[1];
    }
    for (auto &x : B)
    {
        mp[x[0]] = x[1];
    }
    return BFS();
}

/****************************/

///Adj List for Int Nodes
class Graph
{
    int V;
    list<int> *adjList;
public:
    Graph(int v)
    {
        V = v;
        adjList = new list<int>[V + 1];
    }
    void addEdge(int u, int v, bool bidir = true)
    {
        adjList[u].push_back(v);
        if (bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << "->";
            for (int node : adjList[i])
            {
                cout << node << ",";
            }
            cout << endl;
        }
    }
    void bfs(int src, int dest)
    {
        queue<int> q;
        bool *visited = new bool[V + 1] {0};
        int *dist = new int[V + 1] {0};
        int *parent = new int[V + 1] {0};

        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
        }

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int node = q.front();
            cout << node << " ";
            q.pop();

            for (int x : adjList[node])
            {
                if (!visited[x])
                {
                    q.push(x);
                    visited[x] = true;
                    dist[x] = dist[node] + 1;
                    parent[x] = node;
                }
            }
        }
        cout << endl;
        ///Printing distance of every node from src
        for (int i = 0; i < V; i++)
        {
            cout << i << " node distance is: " << dist[i] << endl;
        }
        cout << endl;
        cout << "Shortest distance is " << dist[dest] << endl;
        cout << "Shortest path is ";
        int temp = dest;
        while (temp != -1)
        {
            cout << temp << "<--";
            temp = parent[temp];
        }
    }
};
int main()
{
    Graph g(50);
    int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;

    ///Insert edges
    for (int u = 0; u < 36; u++) {
        ///Throw a dice
        for (int dice = 1; dice <= 6; dice++) {
            int v = u + dice + board[u + dice];
            g.addEdge(u, v, false);
        }
    }

    ///Shortest path
    g.bfs(0, 36);
    return 0;
}
