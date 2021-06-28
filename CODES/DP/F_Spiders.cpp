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
const int mxn=2e5;
vector<int>adj[105];
vector<int>vis(105);
int sub[105];
int diameter;

void dfs(int node,int par){

    for(int child:adj[node]){
        if(vis[child]==0){
            if(child == par)continue;
            dfs(child,node);
            diameter=max(diameter,sub[node] + sub[child]+1);
            sub[node] = max(sub[node],sub[child]+1);
        }
    }    
}

void solve(){
    int n,N,u,v;cin>>n;
    int ans=0;
    rep(i,0,n-1){
        cin>>N;
        rep(i,1,N)adj[i].clear(),vis[i]=0,sub[i]=0;
        rep(i,1,N-1){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        diameter=0;
        dfs(1,-1);
        //cout<<diameter<<endl;
        ans+=diameter;
    }
    cout<<ans<<endl;
}

signed main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}
