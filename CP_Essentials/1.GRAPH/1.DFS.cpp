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
/* //count of the subtree
const int mxn=2e5;
int n;
int cnt[mxn],vis[mxn];
vector<int>adj[mxn];
ll ans=0;
void dfs(int node,int par){
    cnt[node]=1;
    vis[node]=1;
    for(int child:adj[node]){
        if(child==par)
            continue;
        if(!vis[child])
            dfs(child,node);
        cnt[node]+=cnt[child];
    }
}
*/
vector<int> adj[mxn];
int vis[mxn];
int length;
void dfs(int node)
{
    length++;
    vis[node]=1;
    for(int child:adj[node])
        if(!vis[child])
            dfs(child);
}

int main()
{
   // FIO;
    int T;cin>>T;
    while(T--)
    {
        int n,m,u,v;cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            vis[i]=0;
            adj[i].clear();
        }
        for(int i=1;i<=m;i++)
        {
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int cc_count=0;
        ll ans=1;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                length=0;
                dfs(i);
                cc_count++;
                ans=(ans*length)% mod;
            }
        }
        cout<<cc_count<<" "<<ans<<endl;
    }

	return 0;
}
