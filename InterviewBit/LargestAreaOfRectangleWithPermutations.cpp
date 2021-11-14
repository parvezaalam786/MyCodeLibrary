#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > &A)
{
    int n = A.size();
    int m = A[0].size();

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 0)
                A[i][j] = 0;
            else
                A[i][j] += A[i - 1][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        sort(A[i].begin(), A[i].end(), greater<int>());
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, A[i][j] * (j + 1));
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int> (m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    int ans = solve(arr);
    cout << ans;
    return 0;
}
