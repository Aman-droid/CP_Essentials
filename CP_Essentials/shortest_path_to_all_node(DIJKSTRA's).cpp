#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define pii pair< ll,ll >
#define SZ(x) ((ll)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define mp make_pair
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
ll n,m,x,y,w;
vector< pii > adj[100005];
set< pii >setds;
ll vis[100005];
vector<ll> dist(100005,0);
const ll INF=1e18;
void path()
{
	ll x = n;
	for(ll  i=1;i<=n;i++)
	vis[i] = 0;
	vector<ll> ans;
	ans.pb(x);
	while(x!=1)
	{
		for(pii it:adj[x])
 		{
			ll u = it.ff;
			ll  w = it.ss;
			if(dist[u]+w==dist[x] && !vis[x])
			{
				ans.pb(u);
				x = u;
				break;
			}
		}
	}
	for(ll  i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<" ";
}
int main()
{
    //FIO;
    ll T=1;//cin>>T;
    while(T--)
    {
        cin>>n>>m;
        rep(i,1,n)
        {
            adj[i].clear();
            dist[i]=INF;
        }
        for(ll i=1;i<=m;i++)
        {
            cin>>x>>y>>w;
            adj[x].pb({y,w});
            adj[y].pb({x,w});
        }
        ll src=1;
        setds.insert(make_pair(0,src));    //node 1--dist=0
        dist[src]=0;
        while(!setds.empty())
        {
            pii tmp=*(setds.begin());
            setds.erase(setds.begin());
            ll u=tmp.ss;
            for(pii it:adj[u])
            for(pii it:adj[u])
            {
                ll v=it.ff;
                ll weight=it.ss;
                if(dist[u]+weight<dist[v])
                {
                    if(dist[v]!=INF)
                        setds.erase(setds.find(make_pair(dist[v],v)));
                    dist[v]=dist[u]+weight;
                    setds.insert(make_pair(dist[v],v));
                }
            }
        }
        /*rep(i,1,n)
        {
            cout<<dist[i]<<" ";
        }
        cout<<endl;*/
        if(dist[n]==INF)
            cout<<"-1"<<endl;
        else
            path();
    }

    return 0;
}
