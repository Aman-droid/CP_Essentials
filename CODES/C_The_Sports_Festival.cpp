#include<bits/stdc++.h>
#define ll long long
#define int long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpll vector<pll>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n); 
    rep(i,0,n-1) cin >> a[i];
    if(n==1){
        cout<<"0"<<endl;
        return; 
    };
    sort(all(a));
    
    int dp[n][n]; 
    rep(i,0,n-1) dp[i][i] = 0;
    
    for(int d=1;d<n;d++) {
        for(int i=0;i<n;i++) {
            int j = i+d; 
            if (j >= n) continue;
            
            dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + a[j] - a[i];
        }
    }
    // rep(i,0,n-1){
    //     rep(j,0,n-1){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout << dp[0][n-1] << endl;
 
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}