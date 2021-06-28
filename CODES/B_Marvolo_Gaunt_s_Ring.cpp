#include<bits/stdc++.h>
#define ll long long 
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
//-------------------soln-----------------------------//

const ll mxn=2e5;
ll n,p,q,r;
void solve(){
    cin>>n>>p>>q>>r;
    ll a[n];
    ll pos=0,neg=0;
    vpll vec;
    rep(i,0,n-1){
        cin>>a[i];
        //vec.pb({a[i],i});
    }
    ll dp[n][3];
    dp[0][0]=p*a[0];
    dp[0][1]=dp[0][0] + q*a[0];
    dp[0][2]=dp[0][1] + r*a[0];
    rep(i,1,n-1){
        dp[i][0]=max(dp[i-1][0],p*a[i]);
        dp[i][1]=max(dp[i-1][1],dp[i][0] + q*a[i]);
        dp[i][2]=max(dp[i-1][2],dp[i][1] + r*a[i]);
    }
    ll ans=dp[n-1][2];
    cout<<ans<<endl;
    
}   
signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}