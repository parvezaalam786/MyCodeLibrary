/**
*Success is Never Owned, It’s Rented, and the Rent is Due EveryDay!!
*Love the music of silence.
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

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int cnt = 0;
        for (int i = 4 * n; i >= 1; i -= 2)
        {
            cout << i << " ";
            cnt++;
            if (cnt == n)
                break;
        }
        cout << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
