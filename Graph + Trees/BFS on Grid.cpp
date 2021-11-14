/*
Success is Never Owned, It’s Rented, and the Rent is Due EveryDay!!
Love the music of silence.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e9
#define mod 1000000007
#define ff first
#define ss second
#define deb(x) cout<<#x<<" = "<<x
#define all(x) (x).begin(),(x).end()

int dist[1001][1001];
int N, M;
int vis[1001][1001];

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool isvalid(int x, int y)
{
    if (x < 1 || x > N || y < 1 || y > M)
        return false;
    if (vis[x][y] == 1)
        return false;
    return true;
}
void BFS(int srcX, int srcY)
{
    queue<pair<int, int>> que;
    que.push({srcX, srcY});
    vis[srcX][srcY] = 1;
    dist[srcX][srcY] = 0;

    while (!que.empty())
    {
        int currX = que.front().ff;
        int currY = que.front().ss;
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            if (isvalid(currX + dx[i], currY + dy[i]))
            {
                int newX = currX + dx[i];
                int newY = currY + dy[i];

                que.push({newX, newY});
                vis[newX][newY] = 1;
                dist[newX][newY] = dist[currX][currY] + 1;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

void solve()
{
    cin >> N >> M;
    int srcX, srcY;
    cin >> srcX >> srcY;

    BFS(srcX, srcY);
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
