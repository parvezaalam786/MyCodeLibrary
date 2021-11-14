/**
*Success is Never Owned, It’s Rented, and the Rent is Due EveryDay!!
*Love the music of silence.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define inf 1e15
#define mod 1000000007
#define ff first
#define ss second
#define deb(x) cout<<#x<<" = "<<x<<"\n"
#define all(x) (x).begin(),(x).end()

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.ff == b.ff)
        return a.ss >= b.ss;
    return a.ff < b.ff;
}

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int sum1 = 0, sum2 = 0;
        int ans = 0;
        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; i++)
        {
            arr[i] = {a[i], b[i]};
            sum1 = max(sum1, a[i]);
            sum2 += b[i];
        }

        ans = min(sum1, sum2);

        sort(arr.begin(), arr.end(), cmp);

        int pre1[n], pre2[n];
        for (int i = 0; i < n; i++)
        {
            pre1[i] = 0;
            pre2[i] = 0;
        }
        pre1[0] = arr[0].ff;

        for (int i = 1; i < n; i++)
        {
            pre2[i] = arr[i].ss + pre2[i - 1];
        }
        pre2[n - 1] = arr[n - 1].ss;

        for (int i = n - 2; i >= 0; i--)
        {
            pre1[i] = max(pre1[i + 1] , arr[i].ff);
        }

        for (int i = 0; i < n - 1; i++)
        {
            ans = min(ans, pre2[i] + max(0LL, pre1[i + 1] - pre2[i]));
        }

        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i].ff << " ";
        // }
        // cout << "\n";
        // for (int i = 0; i < n; i++)
        // {
        //     cout << arr[i].ss << " ";
        // }
        // cout << "\n";
        // for (int i = 0; i < n; i++)
        // {
        //     cout << pre1[i] << " ";
        // }
        // cout << "\n";
        // for (int i = 0; i < n; i++)
        // {
        //     cout << pre2[i] << " ";
        // }
        // cout << "\n";
        cout << ans << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
