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
ll power(ll a, ll b){//a^b
ll res=1;
a=a%mod;
while(b>0){
    if(b&1){res=(res*a)%mod;b--;}
    a=(a*a)%mod;
    b>>=1;
}
    return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//-------------------soln-----------------------------//
const int mxn=2e5;

void solve(){
    int n,m,K;cin>>n>>m>>K;
    int col[n+1],cost[n+1][m+1];

    rep(i,1,n) cin>>col[i];
    rep(i,1,n)rep(j,1,m)cin>>cost[i][j];    
    ll dp[n+1][m+1][K+1];

    rep(i,0,n)rep(j,0,m)rep(k,0,K)dp[i][j][k]=INF;
    //dp[i][j][k]  =  ans for 1 to i => at pos i color = j and beauty k

    if(col[1]==0){
        rep(j,1,m){
            dp[1][j][1]=cost[1][j];
        }
    }
    else{
        dp[1][col[1]][1]=0;
    }
    //cj = col at j & cp prev color
    rep(i,2,n){
        if(col[i]==0){
            rep(cj,1,m){
                rep(k,1,K){
                    rep(cp,1,m){
                        if(cj!=cp) 
                            dp[i][cj][k] = min(dp[i][cj][k],dp[i-1][cp][k-1] + cost[i][cj]);
                        else 
                            dp[i][cj][k] = min(dp[i][cj][k],dp[i-1][cp][k] + cost[i][cj]);
                    }
                }
            }
        }
        else{
            rep(cp,1,m){
                rep(k,1,K)
                {
                    if(col[i]!=cp) 
                        dp[i][col[i]][k] = min(dp[i][col[i]][k],dp[i-1][cp][k-1]);
                    else 
                        dp[i][col[i]][k] = min(dp[i][col[i]][k],dp[i-1][cp][k]);
                }
            }
        }
    }

    int ans = INF;
    
    rep(j,1,m){
        ans=min(ans,dp[n][j][K]);
    }

    if(ans!=INF){
        cout<<ans<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}