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
vector<int> adj[mxn];
int vis[mxn];
int dis[mxn]; 
int dg[mxn]; 
map<pair<int,int>,int>mp;
vector<pair<int,int>>vec;
int timer=0;
void bfs(int node)
{
    queue<int>q;
    q.push(node);
	vis[node]=1;
	dis[node]=0;
	while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(int child:adj[curr])
            if(!vis[child])
            {
                mp[{curr,child}]=timer;
                mp[{child,curr}]=timer;
                timer++;
                q.push(child);
                dis[child]=dis[curr]+1;
                vis[child]=1;
            }
    }
}

void solve(){
    int n,u,v;cin>>n;
    rep(i,0,n-2){
        cin>>u>>v;
        dg[u]++,dg[v]++;
        vec.pb({u,v});
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int mx=-1;
    int pos=-1;
    rep(i,1,n-1){
        if(dg[i]>mx){
            mx=dg[i];
            pos=i;
        }
    }
    bfs(pos);
    int ans;
    rep(i,0,n-2){
        ans=mp[{vec[i].ff,vec[i].ss}];
        cout<<ans<<endl;
    }
    return;
}
signed main() {
    //freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}