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

const int mxn=2e5+5;
vector<int> adj[mxn];
int sub[mxn];
int val[mxn],level[mxn];

void dfs(int node,int par,int lvl){
    sub[node]=1;
    level[node]=lvl;

    for(int child:adj[node]){
        if(child==par)continue;
        else{
            dfs(child,node,lvl+1);
            sub[node]+=sub[child];
        }
    }
    val[node]=(level[node]-1) - (sub[node]-1);  //increase in happiness when node taken as industry.. 
}

void solve(){
    int n,k,u,v;cin>>n>>k;
    vector<pair<int,int >>res;
    ll ans=0;

    rep(i,1,n-1){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1,-1,1);
    
    rep(i,1,n){
        res.pb({val[i],i});
    }

    sort(all(res));
    reverse(all(res));

    rep(i,0,k-1){
        ans+=res[i].first;
    }
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