#include<bits/stdc++.h>
#define ll long long
#define int long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()
using namespace std;

signed main() {
    FIO;
    int n;cin >> n;
    int ans=0;

    vector<ll> a(n + 1), b(n + 1), pr(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    pr[0]=0;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    rep(i, 1, n){
        pr[i] = pr[i - 1] + a[i] * b[i];
    }

    rep(len, 1, n ) {
        for(int i = 1; i + len <= n + 1; i++) {

            if(len == 1){ 
                dp[len][i] = a[i] * b[i];
            }
            else {
                dp[len][i] = dp[len - 2][i + 1] +  a[i] * b[i + len - 1] +  a[i + len - 1] * b[i];
            }
            ans = max(ans, dp[len][i] + pr[n] - pr[i + len - 1] + pr[i - 1]);
        }
    }
    cout << ans << endl;
    
    return 0;   
}


