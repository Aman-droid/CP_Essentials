#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpll vector<pll>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
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
//--------------------------------------------------------------------------------------------------------//
/*const int mxn=3e4;
vector<int> adj[mxn];
int vis[mxn],idx;
unordered_map<int,int>cnt;

void dfs(int node,int dis){
    vis[node]=1;
    for(int child:adj[node]){
        if(dis==0){
            if(!vis[child])
                dfs(child,1);
        }
        else if(child!=idx){
            cnt[child]++;
        }
    }
}
int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        int n,m,u,v;cin>>n>>m;
        rep(i,1,m){
            cin>>u>>v;
            adj[u].pb(v);
        }
        int ans=0;
        rep(i,1,n){
            idx=i;
            dfs(i,0);
            for(auto it:cnt){
                ans+=((it.ss)*(it.ss-1))/2;
            }
            rep(i,1,n)
                vis[i]=0;
            cnt.clear();
        }
        cout<<ans<<endl;
    }
    return 0;   
}*/
vector<int> adj[3001];
int cnt[3001];

int main()
{
    int n,m; cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
    }
    int ans=0;
    for(int node=1;node<=n;node++)
    {
        memset(cnt,0,sizeof(cnt));
        for(auto a : adj[node]){
            for(auto c : adj[a])
                cnt[c]++;
        }    
        for(int i=1;i<=n;++i)
            if(i!=node)
                ans += (cnt[i]*(cnt[i]-1))/2;
    }
    cout<<ans<<endl;
    return 0;
}
