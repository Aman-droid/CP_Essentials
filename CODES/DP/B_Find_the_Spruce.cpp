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
void solve(){
    int n,m;cin>>n>>m;
    char a[n][m];
    int dp[n][m];
    int ans=0;

    rep(i,0,n-1){
        rep(j,0,m-1){
            cin>>a[i][j];
            dp[i][j]=0;
        }
    }

    rep(i,0,m-1){
        if(a[n-1][i]=='*'){
            dp[n-1][i]=1;
        }
    }

    rep(i,0,n-1){
        if(a[i][0]=='*'){
            dp[i][0]=1;
        }
        if(a[i][m-1]=='*'){
            dp[i][m-1]=1;
        }
    }   

    for(int i=n-2;i>=0;i--){
        rep(j,1,m-2){
            if(a[i][j]=='*'){
                dp[i][j]=1 + min({dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1]});
            }
        }
    }
    rep(i,0,n-1){
        rep(j,0,m-1){
            ans+=dp[i][j];
        }

    }
    cout<<ans<<endl;

}

signed main() {
    //FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}