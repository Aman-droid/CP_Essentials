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
int dp1[mxn];
int dp2[mxn];
int deg[mxn],l[mxn],r[mxn];
vector<int>adj[mxn];
vector<int>res;

void dfs(int node,int par){
    int fl=0;
    for(int child:adj[node]){
        if(child == par)continue;
       
        dfs(child,node);
        dp1[node] += max(dp1[child]+abs(l[node]-l[child]),dp2[child]+abs(l[node]-r[child]));
        dp2[node] += max(dp1[child]+abs(r[node]-l[child]),dp2[child]+abs(r[node]-r[child]));
        // dp2[node] += dp2[child]+max(abs(r[node]-dp1[child]),abs(r[node]-dp2[child]));
        // if(abs(l[node]-dp1[child]),abs(l[node]-dp2[child]))
        fl=1;
    }
    
    if(fl==0){
        dp1[node]=0;
        dp2[node]=0;
    }
}

void solve(){
    int n,u,v;cin>>n;
    rep(i,1,n){
        cin>>l[i]>>r[i];
        adj[i].clear();
        dp1[i]=0;
        dp2[i]=0;
    }
    rep(i,1,n-1){
        cin>>u>>v;
        deg[u]++;
        deg[v]++;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    //watch(n);
    dfs(1,-1);
    // rep(i,1,n){
    //     watch2(dp1[i],dp2[i]);
    // }
    cout<<max(dp1[1],dp2[1])<<endl;
}

signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}